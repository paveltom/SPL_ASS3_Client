#include "../include/Task.h"


Task::Task(const ConnectionHandler& ch, int id, std::mutex&) : _ch(ch) _id(id), _mutex(mutex) {}
Task::~Task() = default;

//Tree::Tree(int rootLabel) : node(rootLabel), children(vector<Tree*>()) {