CPP_FLAGS := -std=c++11

test: vehicle.o person.o wheeled_vehicle.o truck.o bike.o boat.o test.cc vehicle_test.cc wheeled_vehicle_test.cc truck_test.cc boat_test.cc
	g++ $(CPP_FLAGS) vehicle.o person.o wheeled_vehicle.o truck.o bike.o boat.o vehicle_test.cc wheeled_vehicle_test.cc truck_test.cc bike_test.cc boat_test.cc test.cc -o test -lgtest -lpthread

vehicle.o: vehicle.h vehicle.cc
	g++ $(CPP_FLAGS) -c vehicle.cc -o vehicle.o

person.o: person.h person.cc
	g++ $(CPP_FLAGS) -c person.cc -o person.o

wheeled_vehicle.o: wheeled_vehicle.h wheeled_vehicle.cc
	g++ $(CPP_FLAGS) -c wheeled_vehicle.cc -o wheeled_vehicle.o

truck.o: truck.h truck.cc
	g++ $(CPP_FLAGS) -c truck.cc -o truck.o

bike.o: bike.h bike.cc
	g++ $(CPP_FLAGS) -c bike.cc -o bike.o

boat.o: boat.h boat.cc
	g++ $(CPP_FLAGS) -c boat.cc -o boat.o

.PHONY: clean
clean:
	rm -f *.o
	rm -f test
