cmake_minimum_required(VERSION 3.10)
project(BvhDataParser)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(BvhDataParser
${PROJECT_SOURCE_DIR}/src/main.cpp
${PROJECT_SOURCE_DIR}/src/writeNeo4j.cpp
${PROJECT_SOURCE_DIR}/src/readBvh.cpp)

target_link_libraries(BvhDataParser neo4j-client)