#include <gtest/gtest.h>
#include "../Elevator.hpp"
#include <iostream>


TEST(TestElevatorFloor_first,ElevatorTests){
    const int startingFloor = 4;
    Elevator testElevator(startingFloor);
    const int expectedResult = startingFloor;
    const int calculatedResult = testElevator.getFloor();
    ASSERT_EQ(expectedResult,calculatedResult);
}

TEST(TestElevatorFloor_second,ElevatorTests){
    const int startingFloor = 10;
    Elevator testElevator(startingFloor);
    const int expectedResult = startingFloor;
    const int calculatedResult = testElevator.getFloor();
    ASSERT_EQ(expectedResult,calculatedResult);
}

TEST(TestElevatorFloor_third,ElevatorTests){
    const int startingFloor = -3;
    Elevator testElevator(startingFloor);
    const int expectedResult = startingFloor;
    const int calculatedResult = testElevator.getFloor();
    ASSERT_EQ(expectedResult,calculatedResult);
}

TEST(TestIncrementFloor_first,ElevatorTests){
    const int startingFloor = -3;
    Elevator testElevator(startingFloor);
    const int expectedResult = -2;
    const int calculatedResult = testElevator.incrementFloor();\
    ASSERT_EQ(expectedResult,calculatedResult);
}

TEST(TestIncrementFloor_second,ElevatorTests){
    const int startingFloor = 0;
    Elevator testElevator(startingFloor);
    const int expectedResult = 1;
    const int calculatedResult = testElevator.incrementFloor();\
    ASSERT_EQ(expectedResult,calculatedResult);
}

TEST(TestIncrementFloor_third,ElevatorTests){
    const int startingFloor = 5;
    Elevator testElevator(startingFloor);
    const int expectedResult = 6;
    const int calculatedResult = testElevator.incrementFloor();\
    ASSERT_EQ(expectedResult,calculatedResult);
}

TEST(TestDecrementFloor_first,ElevatorTests){
    const int startingFloor = -3;
    Elevator testElevator(startingFloor);
    const int expectedResult = -4;
    const int calculatedResult = testElevator.decrementFloor();\
    ASSERT_EQ(expectedResult,calculatedResult);
}

TEST(TestDecrementFloor_second,ElevatorTests){
    const int startingFloor = 0;
    Elevator testElevator(startingFloor);
    const int expectedResult = -1;
    const int calculatedResult = testElevator.decrementFloor();\
    ASSERT_EQ(expectedResult,calculatedResult);
}

TEST(TestDecrementFloor_third,ElevatorTests){
    const int startingFloor = 5;
    Elevator testElevator(startingFloor);
    const int expectedResult = 4;
    const int calculatedResult = testElevator.decrementFloor();\
    ASSERT_EQ(expectedResult,calculatedResult);
}

TEST(TestsetDestination_third,ElevatorTests){
    const int startingFloor = 5;
    const int endingFloor = 10;
    Elevator testElevator(startingFloor);
    const int expectedResult = StateOfElevator::isMoving;
    const int calculatedResult = testElevator.setDestination(endingFloor);

    const int finalDestination = testElevator.getFloor();
    ASSERT_EQ(expectedResult,calculatedResult);
    ASSERT_EQ(finalDestination,endingFloor);
}

TEST(TestMinFloor_first,ElevatorTests){
    const int minFloor = -2;
    const int startingFloor = 5;
    Elevator testElevator(startingFloor);
    const int expectedResult = minFloor;
    const int calculatedResult = testElevator.getMinFloor();
    ASSERT_EQ(expectedResult,calculatedResult);
}

TEST(TestMinFloor_second,ElevatorTests){
    const int minFloor = 0;
    const int startingFloor = 5;
    Elevator testElevator(startingFloor);
    const int expectedResult = minFloor;
    const int calculatedResult = testElevator.getMinFloor();
    ASSERT_EQ(expectedResult,calculatedResult);
}

TEST(TestMinFloor_third,ElevatorTests){
    const int minFloor = 10;
    const int startingFloor = 5;
    Elevator testElevator(startingFloor);
    const int expectedResult = minFloor;
    const int calculatedResult = testElevator.getMinFloor();
    ASSERT_EQ(expectedResult,calculatedResult);
}

TEST(TestMaxFloor_first,ElevatorTests){
    const int maxFloor = -2;
    const int startingFloor = 5;
    Elevator testElevator(startingFloor);
    const int expectedResult = maxFloor;
    const int calculatedResult = testElevator.getMaxFloor();
    ASSERT_EQ(expectedResult,calculatedResult);
}

TEST(TestMaxFloor_second,ElevatorTests){
    const int maxFloor = 0;
    const int startingFloor = 5;
    Elevator testElevator(startingFloor);
    const int expectedResult = maxFloor;
    const int calculatedResult = testElevator.getMaxFloor();
    ASSERT_EQ(expectedResult,calculatedResult);
}

TEST(TestMaxFloor_third,ElevatorTests){
    const int maxFloor = 10;
    const int startingFloor = 5;
    Elevator testElevator(startingFloor);
    const int expectedResult = maxFloor;
    const int calculatedResult = testElevator.getMaxFloor();
    ASSERT_EQ(expectedResult,calculatedResult);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

