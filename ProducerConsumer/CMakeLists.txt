cmake_minimum_required(VERSION 3.10)
project(ProducerConsumer CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Sources
set(SOURCES
    main.cpp
)

add_executable(producer_consumer ${SOURCES})

# Link threads
find_package(Threads REQUIRED)
target_link_libraries(producer_consumer PRIVATE Threads::Threads)
