#include <gtest/gtest.h>
#include "../People.hpp"


TEST(MemberCheck,PeopleTests){
    const unsigned int numberOfPeople = 10;
    const  int designatedFloor = 3;
    const  int startingFloor = 7;
    People testPeople(numberOfPeople,designatedFloor,startingFloor);

    const unsigned int calculatedNumberOfPeople = testPeople.mNumberOfPeople;
    const  int calculatedDesignatedFloor = testPeople.mDesignatedFloor;
    const  int calculatedStartingFloor = testPeople.mStartingFloor;

    ASSERT_EQ(calculatedNumberOfPeople,numberOfPeople);
    ASSERT_EQ(calculatedDesignatedFloor,designatedFloor);
    ASSERT_EQ(calculatedStartingFloor,startingFloor);
}

TEST(NegativePeopleCheck,PeopleTests){
    const  unsigned int numberOfPeople = 10;
    const  int designatedFloor = 3;
    const  int startingFloor = 7;
    People testPeople(numberOfPeople,designatedFloor,startingFloor);

    const unsigned int calculatedNumberOfPeople = testPeople.mNumberOfPeople;
    const  int calculatedDesignatedFloor = testPeople.mDesignatedFloor;
    const  int calculatedStartingFloor = testPeople.mStartingFloor;

    ASSERT_EQ(calculatedNumberOfPeople,numberOfPeople);
    ASSERT_EQ(calculatedDesignatedFloor,designatedFloor);
    ASSERT_EQ(calculatedStartingFloor,startingFloor);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}