#SET (CMAKE_C_COMPILER             "/usr/bin/clang")
#SET (CMAKE_CXX_COMPILER             "/usr/bin/clang++")
set(CMAKE_BUILD_TYPE Debug)

add_executable(server server.c)
add_executable(client client.c)

