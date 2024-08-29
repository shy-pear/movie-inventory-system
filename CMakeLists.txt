cmake_minimum_required(VERSION 3.23)
project(perfectMovieProject_2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(perfectMovieProject_2
        Classic.cpp
        Classic.h
        ClassicBuilder.cpp
        ClassicBuilder.h
        Comedy.cpp
        Comedy.h
        ComedyBuilder.cpp
        ComedyBuilder.h
        CustomerFactory.h
        Drama.cpp
        Drama.h
        DramaBuilder.cpp
        DramaBuilder.h
        HashTable.cpp
        HashTable.h
        main.cpp
        Movie.cpp
        Movie.h
        MovieBuilder.cpp
        MovieBuilder.h
        MovieCustomer.cpp
        MovieCustomer.h
        MovieCustomerDatabase.cpp
        MovieCustomerDatabase.h
        MovieDatabase.cpp
        MovieDatabase.h)
