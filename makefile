CC=g++

unittest: UnitTests/ElevatorTests.cpp
	$(CC) UnitTests/ElevatorTests.cpp -lgtest -lpthread -o TEST_ELEVATOR
	$(CC) UnitTests/ElevatorCORTests.cpp -lgtest -lpthread -o TEST_ELEVATOR_COR
	./TEST_ELEVATOR
	./TEST_ELEVATOR_COR

clean:
	rm -f TEST_ELEVATOR TEST_ELEVATOR_COR