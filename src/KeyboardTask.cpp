#include "../include/Task.h"

KeyboardTask::KeyboardTask(const ConnectionHandler& ch, int id, std::mutex& mutex) {}

KeyboardTask::~KeyboardTask() = default;

KeyboardTask::KeyboardTask(const KeyboardTask& aCT) = default;

void KeyboardTask::run() {
    while (1) {
        const short bufsize = 1024;
        char buf[bufsize];
        std::cin.getline(buf, bufsize);
        std::string line(buf);
        int len = line.length();
        if (!connectionHandler.sendLine(line)) {
            std::cout << "Disconnected. Exiting...\n" << std::endl;
            break;
        }
    }
}