#include <gtest/gtest.h>
#include "../Elevator.hpp"
#include "../ElevatorFactory.hpp"
#include <iostream>



TEST(TestFactory,ElevatorFactoryTests){
    
    const int ExpectedMinFloor = -3;
    const int ExpectedMaxFloor = 10;
    constexpr int ExpectedStartingFloor = (ExpectedMinFloor + ExpectedMaxFloor) / 2;

    ElevatorFactory testElevatorFactory;
    auto createdElevator = testElevatorFactory.create(ExpectedMinFloor,ExpectedMaxFloor);

    int calculatedStartingFloor = createdElevator.getCurrentFloor();
    int calculatedMaxFloor = createdElevator.getMaxFloor();
    int calculatedMinFloor = createdElevator.getMinFloor();

    ASSERT_EQ(ExpectedMinFloor,calculatedMinFloor);
    ASSERT_EQ(calculatedMaxFloor,ExpectedMaxFloor);
    ASSERT_EQ(calculatedStartingFloor,ExpectedStartingFloor);



}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}