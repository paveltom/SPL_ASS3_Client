#include "../include/Task.h"
#include "../include/ConnectionHandler.h"

NetTask::NetTask(const ConnectionHandler& ch, int id, std::mutex& mutex) {}

NetTask::~NetTask() = default;

NetTask::NetTask(const NetTask& aCT) = default;

void NetTask::run() {
    while (1) {
        if (!connectionHandler.getLine(answer)) {
            std::cout << "Disconnected. Exiting...\n" << std::endl;
            break;
        }
        len = answer.length();
        answer.resize(len - 1);
        std::cout << "Reply: " << answer << " " << len << " bytes " << std::endl << std::endl;
        if (answer == "ACK 4") {
            std::cout << "Exiting...\n" << std::endl;
            break;
        }
    }
}
