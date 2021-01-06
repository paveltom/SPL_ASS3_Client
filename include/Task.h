#ifndef CLIENT_TASK_H
#define CLIENT_TASK_H

#include <stdlib.h>

class Task{
private:
    int _id;
    std::mutex & _mutex;
public:
    Task (int id, std::mutex& mutex) : _id(id), _mutex(mutex) {}
    virtual void run() = 0;
//        for (int i= 0; i < 100; i++){
//            std::lock_guard<std::mutex> lock(_mutex); // constructor locks the mutex while destructor (out of scope) unlocks it
//            std::cout << i << ") Task " << _id << " is working" << std::endl;
//        }
//        throw std::invalid_argument( "Not implemented" );
//    }
};

#endif //CLIENT_TASK_H
