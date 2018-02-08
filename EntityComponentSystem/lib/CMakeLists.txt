cmake_minimum_required (VERSION 2.8) 

project (libEntitys)

include_directories(
  "../../Protocol"
  "../../server/headers/clock"
  "ecs/"
  "ecs/components/"
)

file (
  GLOB_RECURSE
  src_files_common
        ecs/Bullet.cpp
        ecs/Entity.cpp
        ecs/Human.cpp
        ecs/Monster.cpp
        ecs/Obstacle.cpp
        ecs/components/Controlable.cpp
        ecs/components/Movable.cpp
        ecs/components/Shootable.cpp
     Papillon.cpp
)

if(UNIX)
  set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -fPIC -shared")
  add_executable(
    libEntitys
    ${src_files_common}
  )

endif(UNIX)

if(WIN32)
SET(mylibSRCS ${src_files_common} ${src_files_win})
  add_executable(
    r-type
	${src_files_win}
    ${src_files_common}
          ../Protocol/src/PlayerLeaved.cpp ../Protocol/headers/PlayerLeaved.hpp ../Protocol/src/PlayerMove.cpp ../Protocol/headers/PlayerMove.hpp)

endif(WIN32)
