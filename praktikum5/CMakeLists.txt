cmake_minimum_required(VERSION 3.5)

project(first LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(first main.cpp
    battleship.cpp
    battleship.h
    gameboard.cpp
    gameboard.h
    part.cpp
    part.h
    player.cpp
    player.h
    ship.cpp
    ship.h



)

include(GNUInstallDirs)
install(TARGETS first
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
