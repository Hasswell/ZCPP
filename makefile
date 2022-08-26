CC=g++
STD=std=c++17

Elevators:
	@$(CC) -$(STD) Starter.cpp -o MAIN && ./MAIN 

unittest: UnitTests/ElevatorTests.cpp
	$(CC) -$(STD) UnitTests/ElevatorTests.cpp -lgtest -lpthread -o TEST_ELEVATOR
	$(CC) -$(STD) UnitTests/ElevatorFactoryTests.cpp -lgtest -lpthread -o TEST_ELEVATOR_FACTORY
	$(CC) -$(STD) UnitTests/PeopleFactoryTests.cpp -lgtest -lpthread -o TEST_PEOPLE_FACTORY
	$(CC) -$(STD) UnitTests/QueueOfPersonTests.cpp -lgtest -lpthread -o TEST_QUEUE_OF_PERSONS
	$(CC) -$(STD) UnitTests/PeopleTests.cpp -lgtest -lpthread -o TEST_PEOPLE
	$(CC) -$(STD) UnitTests/PullOfElevatorsTests.cpp -lgtest -lpthread -o TEST_PULL_OF_ELEVATORS
	@./TEST_ELEVATOR
	@./TEST_ELEVATOR_FACTORY
	@./TEST_PEOPLE_FACTORY
	@./TEST_QUEUE_OF_PERSONS
	@./TEST_PEOPLE
	@./TEST_PULL_OF_ELEVATORS


clean:
	@rm -f TEST_ELEVATOR TEST_PEOPLE_FACTORY MAIN TEST_ELEVATOR_FACTORY TEST_QUEUE_OF_PERSONS TEST_PEOPLE TEST_PULL_OF_ELEVATORS
logsclear:
	@rm -f Logs.txt