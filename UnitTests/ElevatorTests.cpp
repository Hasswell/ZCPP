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
    const int expectedResult = startingFloor;
    const int calculatedResult = testElevator.incrementFloor();\
    std::cout << "Calculated Resutl: " << calculatedResult << std::endl;
    std::cout << "Expected Resutl: " << expectedResult << std::endl;
    ASSERT_EQ(expectedResult,calculatedResult);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

