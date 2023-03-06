CPP_FLAGS := -std=c++11

test: vehicle.o person.o wheeled_vehicle.o truck.o bike.o boat.o test.cpp vehicle_test.cpp wheeled_vehicle_test.cpp truck_test.cpp boat_test.cpp
	g++ $(CPP_FLAGS) vehicle.o person.o wheeled_vehicle.o truck.o bike.o boat.o vehicle_test.cpp wheeled_vehicle_test.cpp truck_test.cpp bike_test.cpp boat_test.cpp test.cpp -o test -lgtest -lpthread

vehicle.o: vehicle.h vehicle.cpp
	g++ $(CPP_FLAGS) -c vehicle.cpp -o vehicle.o

person.o: person.h person.cpp
	g++ $(CPP_FLAGS) -c person.cpp -o person.o

wheeled_vehicle.o: wheeled_vehicle.h wheeled_vehicle.cpp
	g++ $(CPP_FLAGS) -c wheeled_vehicle.cpp -o wheeled_vehicle.o

truck.o: truck.h truck.cpp
	g++ $(CPP_FLAGS) -c truck.cpp -o truck.o

bike.o: bike.h bike.cpp
	g++ $(CPP_FLAGS) -c bike.cpp -o bike.o

boat.o: boat.h boat.cpp
	g++ $(CPP_FLAGS) -c boat.cpp -o boat.o

.PHONY: clean
clean:
	rm -f *.o
	rm -f test
