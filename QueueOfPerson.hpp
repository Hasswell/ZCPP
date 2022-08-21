#ifndef QUEUE_OF_PERSON_HPP
#define QUEUE_OF_PERSON_HPP
#include <utility>
#include "People.hpp"
#include <queue>

class QueueOfPersons{
private:
    std::queue<People> personQueue;

public:
    int push(People groupOfPeople);
    int size();
    People front();
    bool empty();
    int Pop();

};

int QueueOfPersons::push(People groupOfPeople){
    personQueue.push(groupOfPeople);
    return this->size();
}

int QueueOfPersons::size(){
    return personQueue.size();
}

bool QueueOfPersons::empty(){
    return personQueue.empty();
}

People QueueOfPersons::front(){
    return personQueue.front();
}

int QueueOfPersons::Pop(){
    personQueue.pop();
    return this->size();
}

#endif