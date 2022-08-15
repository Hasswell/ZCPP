#include <gtest/gtest.h>
#include "../Elevator.hpp"


TEST(SimpleTest,ElevatorTests){
    ASSERT_EQ(1,1);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

