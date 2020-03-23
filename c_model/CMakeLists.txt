cmake_minimum_required( VERSION 3.0 )
project( pid_simulation )

set (SOURCE_FILES
    "./src/main.c"
    "./src/pid.c"
)


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories( ./include/pid ./src)

add_executable( pid ${SOURCE_FILES})
