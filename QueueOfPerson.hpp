#include <utility>


class QueueOfPersons{

public:
    int push(int numberOfPeople, int destinatedFloor);
    int size();
    std::pair<int,int> front();
    bool empty();


private:


};

int QueueOfPersons::push(int numberOfPeople, int destinatedFloor){
    return 1;
}

int QueueOfPersons::size(){
    return 1;
}

bool QueueOfPersons::empty(){
    return true;
}

std::pair<int,int> QueueOfPersons::front(){
    return std::make_pair<int,int>(0,0);
}