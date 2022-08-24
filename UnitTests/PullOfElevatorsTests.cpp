#include "../Elevator.hpp"
#include "../ElevatorCOR.hpp"
#include "../PullOfElevators.hpp"
#include "../People.hpp"


TEST(DistanceCalculation_first,PullOfElevatorsTest){
    const int maxFloor = 10;
    const int minFloor = -10;
    const int numberOfElevators = 4;
    PullOfElevators testPullOfElevators(numberOfElevators,minFloor,maxFloor);
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
    const int numberOfElevators = 4;
    PullOfElevators testPullOfElevators(numberOfElevators,minFloor,maxFloor);
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
    const int numberOfElevators = 4;
    PullOfElevators testPullOfElevators(numberOfElevators,minFloor,maxFloor);
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
    const int numberOfElevators = 4;
    PullOfElevators testPullOfElevators(numberOfElevators,minFloor,maxFloor);
    Elevator testElevator(minFloor,maxFloor);
    testElevator.setCurrentFloor(3);
    const int destination = -2;
    const int expectedDistance = 5;
    const int calculatedDistance = testPullOfElevators.calculateDistance(testElevator,destination);
    
    ASSERT_EQ(expectedDistance,calculatedDistance);
}

TEST(ChooseElevator_first,PullOfElevatorsTest){
    const int maxFloor = 10;
    const int minFloor = -10;
    const int numberOfElevators = 4;
    PullOfElevators testPullOfElevators(numberOfElevators,minFloor,maxFloor);
    int destinationFloor = 5;
    testPullOfElevators.setFloorForElevator(0,-3);
    testPullOfElevators.setFloorForElevator(1,4);
    testPullOfElevators.setFloorForElevator(2,7);
    testPullOfElevators.setFloorForElevator(3,-8);
    auto returnedElevator = testPullOfElevators.chooseElevator(destinationFloor);
    ASSERT_EQ(*returnedElevator,testPullOfElevators.selectElevator(1));
}

TEST(ChooseElevator_second,PullOfElevatorsTest){
    const int maxFloor = 10;
    const int minFloor = -10;
    const int numberOfElevators = 4;
    PullOfElevators testPullOfElevators(numberOfElevators,minFloor,maxFloor);
    int currentFloor = -5;
    testPullOfElevators.setFloorForElevator(0,-3);
    testPullOfElevators.setFloorForElevator(1,4);
    testPullOfElevators.setFloorForElevator(2,7);
    testPullOfElevators.setFloorForElevator(3,-8);
    auto returnedElevator = testPullOfElevators.chooseElevator(currentFloor);
    ASSERT_EQ(*returnedElevator,testPullOfElevators.selectElevator(0));
}

TEST(passPeopleToElevator_first,PullOfElevatorsTest){
    unsigned int numberOfPeople = 5;
    People testGroup(numberOfPeople,6,5);
    
    const int maxFloor = 10;
    const int minFloor = -10;
    const int numberOfElevators = 4;
    PullOfElevators testPullOfElevators(numberOfElevators,minFloor,maxFloor);
    testPullOfElevators.setFloorForElevator(0,-3);
    testPullOfElevators.setFloorForElevator(1,4);
    testPullOfElevators.setFloorForElevator(2,7);
    testPullOfElevators.setFloorForElevator(3,-8);
    auto returnedElevator = testPullOfElevators.chooseElevator(testGroup.mStartingFloor);
    testPullOfElevators.passPeopleToElevator(testGroup);
    ASSERT_EQ(returnedElevator->getCurrentFloor(),testGroup.mDesignatedFloor);
}


TEST(alarmForElevators,PullOfElevatorsTest){
    unsigned int numberOfPeople = 5;
    People testGroup(numberOfPeople,6,5);
    
    const int maxFloor = 10;
    const int minFloor = -10;
    const int numberOfElevators = 4;
    PullOfElevators testPullOfElevators(numberOfElevators,minFloor,maxFloor);
    testPullOfElevators.setFloorForElevator(0,-3);
    testPullOfElevators.setFloorForElevator(1,4);
    testPullOfElevators.setFloorForElevator(2,7);
    testPullOfElevators.setFloorForElevator(3,-8);
    testPullOfElevators.setAlarmForElevators();
    const int alarmFloor = 0;
    for(int i = 0; i < numberOfElevators;i++){
        ASSERT_EQ(testPullOfElevators.selectElevator(i).getCurrentFloor() ,alarmFloor);
    }
    
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}