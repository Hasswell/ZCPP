#include <gtest/gtest.h>
#include "../Elevator.hpp"
#include "../ElevatorCOR.hpp"
#include <iostream>

class Elevator;

TEST(TestIncrementFloor_first,ElevatorTests){
    const int minFloor = -3;
    const int maxFloor = -1;
    std::string id = "0xFFAA";
    Elevator testElevator(minFloor,maxFloor,id);
    const int startingFloor = testElevator.getCurrentFloor();
    const int expectedResult = startingFloor + 1;
    testElevator.incrementFloor();
    const int calculatedResult = testElevator.getCurrentFloor();
    ASSERT_EQ(expectedResult,calculatedResult);
}

TEST(TestIncrementFloor_second,ElevatorTests){
    const int minFloor = -5;
    const int maxFloor = -1;
    std::string id = "0xFFAA";
    Elevator testElevator(minFloor,maxFloor,id);
    const int expectedResult = testElevator.getCurrentFloor() + 2;
    testElevator.incrementFloor();
    testElevator.incrementFloor();
    const int calculatedResult = testElevator.getCurrentFloor();
    ASSERT_EQ(expectedResult,calculatedResult);
}

TEST(TestDecrementFloor_first,ElevatorTests){
    const int minFloor = -5;
    const int maxFloor = -1;
    std::string id = "0xFFAA";
    Elevator testElevator(minFloor,maxFloor,id);
    const int expectedResult = testElevator.getCurrentFloor() - 2;
    testElevator.decrementFloor();
    testElevator.decrementFloor();
    const int calculatedResult = testElevator.getCurrentFloor() ;
    ASSERT_EQ(expectedResult,calculatedResult);
}

TEST(TestDecrementFloor_second,ElevatorTests){
    const int minFloor = -3;
    const int maxFloor = -1;
    std::string id = "0xFFAA";
    Elevator testElevator(minFloor,maxFloor,id);
    const int expectedResult = testElevator.getCurrentFloor() - 1;
    const int calculatedResult = testElevator.decrementFloor();
    ASSERT_EQ(expectedResult,calculatedResult);
}

TEST(TestsetDestination_third,ElevatorTests){
    const int minFloor = -3;
    const int maxFloor = -1;
    const int endingFloor = -1;
    std::string id = "0xFFAA";
    Elevator testElevator(minFloor,maxFloor,id);
    const int expectedResult = StateOfElevator::isFree;
    const int calculatedResult = testElevator.setDestination(endingFloor);

    const int finalDestination = testElevator.getCurrentFloor();
    ASSERT_EQ(expectedResult,calculatedResult);
    ASSERT_EQ(finalDestination,endingFloor);
}

TEST(TestMinFloor_first,ElevatorTests){
    const int minFloor = -3;
    const int maxFloor = -1;
    std::string id = "0xFFAA";
    Elevator testElevator(minFloor,maxFloor,id);
    const int expectedResult = minFloor;
    const int calculatedResult = testElevator.getMinFloor();
    ASSERT_EQ(expectedResult,calculatedResult);
}

TEST(TestMinFloor_second,ElevatorTests){
    const int minFloor = 0;
    const int maxFloor = 1;
    std::string id = "0xFFAA";
    Elevator testElevator(minFloor,maxFloor,id);
    const int expectedResult = minFloor;
    const int calculatedResult = testElevator.getMinFloor();
    ASSERT_EQ(expectedResult,calculatedResult);
}

TEST(TestMinFloor_third,ElevatorTests){
    const int minFloor = 10;
    const int maxFloor = 20;
    std::string id = "0xFFAA";
    Elevator testElevator(minFloor,maxFloor,id);
    const int expectedResult = minFloor;
    const int calculatedResult = testElevator.getMinFloor();
    ASSERT_EQ(expectedResult,calculatedResult);
}

TEST(TestMaxFloor_first,ElevatorTests){
    const int maxFloor = -2;
    const int minFloor = -4;
    std::string id = "0xFFAA";
    Elevator testElevator(minFloor,maxFloor,id);
    const int expectedResult = maxFloor;
    const int calculatedResult = testElevator.getMaxFloor();
    ASSERT_EQ(expectedResult,calculatedResult);
}

TEST(TestMaxFloor_second,ElevatorTests){
    const int maxFloor = 0;
    const int minFloor = -4;
    std::string id = "0xFFAA";
    Elevator testElevator(minFloor,maxFloor,id);
    const int expectedResult = maxFloor;
    const int calculatedResult = testElevator.getMaxFloor();
    ASSERT_EQ(expectedResult,calculatedResult);
}

TEST(TestMaxFloor_third,ElevatorTests){
    const int maxFloor = 10;
    const int minFloor = 6;
    std::string id = "0xFFAA";
    Elevator testElevator(minFloor,maxFloor,id);
    const int expectedResult = maxFloor;
    const int calculatedResult = testElevator.getMaxFloor();
    ASSERT_EQ(expectedResult,calculatedResult);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

