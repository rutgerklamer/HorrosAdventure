# CMake entry point
cmake_minimum_required (VERSION 2.6)
project (textAdventure)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# delete CMakeCache.txt from the build directory when you edit these options
####################################################################
OPTION(MAKE_TEXT "Create Text Adventure" ON)
####################################################################

####################################################################
# Adventure                                                        #
####################################################################
IF(MAKE_TEXT)
    add_executable(text
      TextAdventure/main.cpp
      TextAdventure/Player.cpp
      TextAdventure/Player.h
      TextAdventure/Game.cpp
      TextAdventure/Game.h
      TextAdventure/Room.cpp
      TextAdventure/Room.h
      TextAdventure/Inventory.cpp
      TextAdventure/Inventory.h
      TextAdventure/Commandwords.cpp
      TextAdventure/Commandwords.h
      TextAdventure/Parser.cpp
      TextAdventure/Parser.h
      TextAdventure/Entity.cpp
      TextAdventure/Entity.h
      TextAdventure/Shovel.cpp
      TextAdventure/Shovel.h
      TextAdventure/Keys.cpp
      TextAdventure/Keys.h
      TextAdventure/Textloader.cpp
      TextAdventure/Textloader.h
      )


ENDIF()
