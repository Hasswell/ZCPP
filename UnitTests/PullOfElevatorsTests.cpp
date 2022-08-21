#include "../Elevator.hpp"
#include "../ElevatorCOR.hpp"
#include "../PullOfElevators.hpp"


TEST(DistanceCalculation_first,PullOfElevatorsTest){
    const int maxFloor = 10;
    const int minFloor = -10;
    PullOfElevators testPullOfElevators;
    Elevator testElevator(minFloor,maxFloor);
    testElevator.setCurrentFloor(5);
    const int destination = 3;
    const int expectedDistance = 2;
    const int calculatedDistance = testPullOfElevators.calculateDistance(testElevator,destination);
    
    ASSERT_EQ(expectedDistance,calculatedDistance);
}

TEST(DistanceCalculation_second,PullOfElevatorsTest){
    const int maxFloor = 10;
    const int minFloor = -10;
    PullOfElevators testPullOfElevators;
    Elevator testElevator(minFloor,maxFloor);
    testElevator.setCurrentFloor(-6);
    const int destination = -2;
    const int expectedDistance = 4;
    const int calculatedDistance = testPullOfElevators.calculateDistance(testElevator,destination);
    
    ASSERT_EQ(expectedDistance,calculatedDistance);
}

TEST(DistanceCalculation_third,PullOfElevatorsTest){
    const int maxFloor = 10;
    const int minFloor = -10;
    PullOfElevators testPullOfElevators;
    Elevator testElevator(minFloor,maxFloor);
    testElevator.setCurrentFloor(-3);
    const int destination = 7;
    const int expectedDistance = 10;
    const int calculatedDistance = testPullOfElevators.calculateDistance(testElevator,destination);
    
    ASSERT_EQ(expectedDistance,calculatedDistance);
}

TEST(DistanceCalculation_fourth,PullOfElevatorsTest){
    const int maxFloor = 10;
    const int minFloor = -10;
    PullOfElevators testPullOfElevators;
    Elevator testElevator(minFloor,maxFloor);
    testElevator.setCurrentFloor(3);
    const int destination = -2;
    const int expectedDistance = 5;
    const int calculatedDistance = testPullOfElevators.calculateDistance(testElevator,destination);
    
    ASSERT_EQ(expectedDistance,calculatedDistance);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}