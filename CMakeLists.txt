cmake_minimum_required(VERSION 3.31)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled main.cpp
        Login.cpp
        Includes/Login.h
        Home.cpp
        Includes/Home.h
        User.cpp
        Includes/User.h
        Deposit.cpp
        Includes/Deposit.h
        CreateAccount.cpp
        Includes/CreateAccount.h)
