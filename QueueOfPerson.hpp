#ifndef QUEUE_OF_PERSON_HPP
#define QUEUE_OF_PERSON_HPP
#include <utility>
#include "People.hpp"
#include <queue>

class QueueOfPersons{
private:
    std::queue<People> mPersonQueue;

public:
    int push(People groupOfPeople);
    int size();
    People front();
    bool empty();
    int Pop();

};

int QueueOfPersons::push(People groupOfPeople){
    mPersonQueue.push(groupOfPeople);
    return this->size();
}

int QueueOfPersons::size(){
    return mPersonQueue.size();
}

bool QueueOfPersons::empty(){
    return mPersonQueue.empty();
}

People QueueOfPersons::front(){
    return mPersonQueue.front();
}

int QueueOfPersons::Pop(){
    mPersonQueue.pop();
    return this->size();
}

#endif