#include <gtest/gtest.h>
#include "../Elevator.hpp"
#include "../ElevatorCOR.hpp"


TEST(SimpleTest,ElevatorCORTests){
    ASSERT_EQ(1,1);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}