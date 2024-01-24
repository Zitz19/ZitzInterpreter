cmake_minimum_required(VERSION 3.0.0)
project(ZitzInterpreter VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

find_package(BISON)
find_package(FLEX)
BISON_TARGET(MyParser ZitzParser.y ${CMAKE_CURRENT_BINARY_DIR}/ZitzParser.cpp
             COMPILE_FLAGS --debug
             DEFINES_FILE ${CMAKE_CURRENT_BINARY_DIR}/ZitzParser.h)
FLEX_TARGET(MyScanner ZitzLexer.l ${CMAKE_CURRENT_BINARY_DIR}/ZitzLexer.cpp
             DEFINES_FILE ${CMAKE_CURRENT_BINARY_DIR}/ZitzLexer.h)
ADD_FLEX_BISON_DEPENDENCY(MyScanner MyParser)

include_directories(include ${CMAKE_CURRENT_BINARY_DIR} ${FLEX_INCLUDE_DIRS})

add_executable(ZitzInterpreter ZitzParser.cpp ZitzLexer.cpp ${BISON_MyParser_OUTPUTS} ${FLEX_MyScanner_OUTPUTS})

target_link_libraries(ZitzInterpreter ${FLEX_LIBRARIES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
