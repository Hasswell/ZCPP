#include <gtest/gtest.h>
#include "../QueueOfPerson.hpp"
#include "../People.hpp"


class QueueuOfPersonsFixture : public ::testing::Test{
public:
    QueueuOfPersonsFixture(){
    firstSetOfPeople = People((unsigned int)3,3,5);
    secondSetOfPeople = People((unsigned int)5,3,10);
    thirdSetOfPeople  = People((unsigned int)2,5,-3);

    }
    ~QueueuOfPersonsFixture(){
        
    }
virtual void SetUp(){

}

virtual void TearDown(){
    
}
    People firstSetOfPeople;
    People secondSetOfPeople;
    People thirdSetOfPeople;
};

TEST_F(QueueuOfPersonsFixture,SizeTest_First){
    
    QueueOfPersons testQueue;
    const int expectedSize = 2;
    testQueue.push(firstSetOfPeople);
    testQueue.push(secondSetOfPeople);
    const int calculatedSize = testQueue.size();
    ASSERT_EQ(expectedSize,calculatedSize);
}

TEST_F(QueueuOfPersonsFixture,SizeTest_Second){
    
    QueueOfPersons testQueue;
    const int expectedSize = 1;
    testQueue.push(firstSetOfPeople);
    const int calculatedSize = testQueue.size();
    ASSERT_EQ(calculatedSize,expectedSize);
}

TEST_F(QueueuOfPersonsFixture,IsNotEmptyTest){
    
    QueueOfPersons testQueue;
    const bool expectedIsEmpty = false;
    testQueue.push(firstSetOfPeople);
    const bool calculatedIsEmpty = testQueue.empty();
    ASSERT_EQ(expectedIsEmpty,calculatedIsEmpty);
}

TEST_F(QueueuOfPersonsFixture,IsEmptyTest){
    
    QueueOfPersons testQueue;
    const bool expectedIsEmpty= true;
    const bool calculatedIsEmpty = testQueue.empty();
    ASSERT_EQ(expectedIsEmpty,calculatedIsEmpty);
}

TEST_F(QueueuOfPersonsFixture,PushTest){ 
    QueueOfPersons testQueue;
    testQueue.push(firstSetOfPeople);
    testQueue.push(secondSetOfPeople);
    People testGroupOfPeople = testQueue.front();
    ASSERT_EQ(testGroupOfPeople,firstSetOfPeople);
}

TEST_F(QueueuOfPersonsFixture,PopTest){ 
    int currentSizeOfQueue = 0;
    int expectedSizeOfQueue = 2;

    QueueOfPersons testQueue;
    currentSizeOfQueue = testQueue.push(firstSetOfPeople);
    currentSizeOfQueue = testQueue.push(secondSetOfPeople);
    People testGroupOfPeople = testQueue.front();
    ASSERT_EQ(testGroupOfPeople,firstSetOfPeople);
    ASSERT_EQ(currentSizeOfQueue,expectedSizeOfQueue);
    
    expectedSizeOfQueue = 1;
    currentSizeOfQueue = testQueue.Pop();
    testGroupOfPeople = testQueue.front();
    ASSERT_EQ(testGroupOfPeople,secondSetOfPeople);
    ASSERT_EQ(currentSizeOfQueue,expectedSizeOfQueue);
}


int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}