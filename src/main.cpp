#include "../include/connectionHandler.h"
#include "../include/Task.h"
#include "../include/EncoderDecoder.h"

#include <stdlib.h>
#include <stdexcept>


using namespace std;

/**
* This code assumes that the server replies the exact text the client sent it (as opposed to the practical session example)
*/
int main (int argc, char *argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " host port" << std::endl << std::endl;
        return -1;
    }
    std::string host = argv[1];
    short port = atoi(argv[2]);
    
    ConnectionHandler connectionHandler(host, port);
    if (!connectionHandler.connect()) {
        std::cerr << "Cannot connect to " << host << ":" << port << std::endl;
        return 1;
    }

    std::mutex mutex;
    class : public Task (1, mutex){
        void run(){
            // operating user keyboard input and output to terminal (so there will be no parallel tries to print and write in terminal)
        }
    } keyboardTask;

    class : public Task (2, mutex){
        void run(){
            // operating socket transferring in both directions - working with connectionHolder
        }
    } netTask;

    std::thread th1(&Task::run, &keyboardTask);
    std::thread th2(&Task::run, &netTask);
    th1.join(); // or detach()
    th2.join(); //or detach()

    while (1) {
        const short bufsize = 1024;
        char bufKeyboard[bufsize];
        //char bufNet[bufsize];
        std::cin.getline(bufKeyboard, bufsize);
		std::string line(buf);
		int len=line.length();
        if (!connectionHandler.sendLine(line)) {
            std::cout << "Disconnected. Exiting...\n" << std::endl;
            break;
        }

		// connectionHandler.sendLine(line) appends '\n' to the message. Therefor we send len+1 bytes.
        std::cout << "Sent " << len+1 << " bytes to server" << std::endl;

        // 2. Read a line (up to the newline character using the getline() buffered reader
        std::string answer;

        // We could also use: connectionHandler.getline(answer) and then get the answer without the newline char at the end
        if (!connectionHandler.getLine(answer)) {
            std::cout << "Disconnected. Exiting...\n" << std::endl;
            break;
        }
        
		len=answer.length();
		// task1 = new task(buf, bufSize)
        //
        // thread getFromKey(ref((task1));
        //
        //
        // From here we will see the rest of the ehco client implementation: A C string must end with a 0 char delimiter.
        // When we filled the answer buffer from the socket we filled up to the \n char - we must make
        // sure now that a 0 char is also present. So we truncate last character.
        answer.resize(len-1);
        std::cout << "Reply: " << answer << " " << len << " bytes " << std::endl << std::endl;
        if (answer == "bye") {
            std::cout << "Exiting...\n" << std::endl;
            break;
        }
    }
    return 0;
}


