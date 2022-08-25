#include <gtest/gtest.h>
#include "../Elevator.hpp"
#include "../ElevatorFactory.hpp"
#include <iostream>



TEST(TestFactory,ElevatorFactoryTests){
    
    const int ExpectedMinFloor = -3;
    const int ExpectedMaxFloor = 10;
    const std::string ExpectedId = "0xFFAA";
    constexpr int ExpectedStartingFloor = (ExpectedMinFloor + ExpectedMaxFloor) / 2;

    ElevatorFactory testElevatorFactory;
    auto createdElevator = testElevatorFactory.create(ExpectedMinFloor,ExpectedMaxFloor,ExpectedId);

    int calculatedStartingFloor = createdElevator.getCurrentFloor();
    int calculatedMaxFloor = createdElevator.getMaxFloor();
    int calculatedMinFloor = createdElevator.getMinFloor();
    std::string calculatedID = createdElevator.getId();

    ASSERT_EQ(ExpectedMinFloor,calculatedMinFloor);
    ASSERT_EQ(calculatedMaxFloor,ExpectedMaxFloor);
    ASSERT_EQ(calculatedStartingFloor,ExpectedStartingFloor);
    ASSERT_EQ(calculatedID,ExpectedId);



}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}