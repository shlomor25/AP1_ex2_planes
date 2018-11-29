cmake_minimum_required(VERSION 3.12)
project(AP22222)

set(CMAKE_CXX_STANDARD 11)

add_executable(AP22222 main.cpp MyImplementation.cpp MyImplementation.h MyCustomer.cpp MyCustomer.h Serial.cpp Serial.h MyEmployee.cpp MyEmployee.h MyPlane.cpp MyPlane.h MyFlight.cpp MyFlight.h MyReservation.cpp MyReservation.h interface.h date.cpp Collection.cpp Collection.h)