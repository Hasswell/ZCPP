#include <gtest/gtest.h>
#include "../People.hpp"
#include "../PeopleFactory.hpp"
#include <iostream>



TEST(TestCreate,PeopleFactoryTests){
    
    const unsigned int ExpectedNumberOfPeople = 6;
    const int ExpectedDestination = 10;
    const int ExpectedStartingFloor = -3;

    PeopleFactory testPeopleFactory;
    auto createdGroup = testPeopleFactory.create(ExpectedNumberOfPeople,ExpectedDestination,ExpectedStartingFloor);

    const unsigned int calculatedNumberOfPeople = createdGroup.mNumberOfPeople;
    const int calculatedDestination = createdGroup.mDesignatedFloor;
    const int calculatedStartingFloor = createdGroup.mStartingFloor;

    ASSERT_EQ(ExpectedNumberOfPeople,calculatedNumberOfPeople);
    ASSERT_EQ(ExpectedDestination,calculatedDestination);
    ASSERT_EQ(ExpectedStartingFloor,calculatedStartingFloor);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}