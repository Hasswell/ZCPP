CC=g++
STD=std=c++17

Elevators:
	@$(CC) -$(STD) Starter.cpp -o MAIN && ./MAIN 

unittest: UnitTests/ElevatorTests.cpp
	$(CC) UnitTests/ElevatorTests.cpp -lgtest -lpthread -o TEST_ELEVATOR
	$(CC) UnitTests/ElevatorCORTests.cpp -lgtest -lpthread -o TEST_ELEVATOR_COR
	$(CC) UnitTests/ElevatorFactoryTests.cpp -lgtest -lpthread -o TEST_ELEVATOR_FACTORY
	$(CC) UnitTests/QueueOfPersonTests.cpp -lgtest -lpthread -o TEST_QUEUE_OF_PERSONS
	$(CC) UnitTests/PeopleTests.cpp -lgtest -lpthread -o TEST_PEOPLE
	$(CC) UnitTests/PullOfElevatorsTests.cpp -lgtest -lpthread -o TEST_PULL_OF_ELEVATORS
	@./TEST_ELEVATOR
	@./TEST_ELEVATOR_COR
	@./TEST_ELEVATOR_FACTORY
	@./TEST_QUEUE_OF_PERSONS
	@./TEST_PEOPLE
	@./TEST_PULL_OF_ELEVATORS

clean:
	@rm -f TEST_ELEVATOR TEST_ELEVATOR_COR MAIN TEST_ELEVATOR_FACTORY TEST_QUEUE_OF_PERSONS TEST_PEOPLE TEST_PULL_OF_ELEVATORS

logsclear:
	@rm -f Logs.txt