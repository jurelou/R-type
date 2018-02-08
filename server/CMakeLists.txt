cmake_minimum_required (VERSION 2.8) 

project (r-type)

include_directories(
        "headers/"
        "../Network"
        "../Network/Network/Windows"
        "../Network/headers/Unix"
        "headers/threads"
        "../Protocol/headers"
        "../Protocol"
        "headers/fileSystem"
        "../Physics/headers"
        "../Physics/"
        "ecs/"
        "ecs/components/"
        "ecs/systems/"
        "headers/clock"
)

file (
     GLOB_RECURSE
     src_files_unix

        ../Network/headers/Unix/UnixSocket.hpp
        ../Network/headers/Unix/UnixServerSocket.hpp

        ../Network/src/Unix/UnixSocket.cpp
        ../Network/src/Unix/UnixServerSocket.cpp

        headers/threads/UnixThreads.hpp
        src/threads/UnixThreads.cpp

        headers/clock/UnixClock.hpp
        src/clock/UnixClock.cpp

)

file (
     GLOB_RECURSE
     src_files_win
        ../Network/Network/Windows/
        ../Network/src/network/Windows/
        ../Network/Network/Windows/
        ../Network/src/network/Windows/
)

file (
     GLOB_RECURSE
     src_files_common
        headers/Server.hpp
        src/Server.cpp
        src/main.cpp
        ../Network/ISocket.hpp
        ../Network/IServerSocket.hpp
        ../Network/CrossPlatformSockets.hpp

        ../Protocol/Protocol.hpp
        ../Protocol/ARequest.hpp
        ../Protocol/IRequest.hpp
        ../Protocol/Serializer.hpp
        ../Protocol/Vertex.hpp
        ../Protocol/headers/Login.hpp
        ../Protocol/headers/ListGame.hpp
        ../Protocol/headers/JoinLobby.hpp
        ../Protocol/headers/JoinGame.hpp
        ../Protocol/headers/LeaveGame.hpp
        ../Protocol/headers/CreateGame.hpp
        ../Protocol/headers/Response.hpp
        ../Protocol/headers/NewEntity.hpp
        ../Protocol/headers/MoveEntity.hpp
        ../Protocol/headers/DeleteEntity.hpp
        ../Protocol/headers/PlayerEntered.hpp
        ../Protocol/headers/PlayerAccepted.hpp
        ../Protocol/headers/PlayerLeaved.hpp
        ../Protocol/headers/PlayerMove.hpp

        ../Protocol/ARequest.cpp
        ../Protocol/Serializer.cpp
        ../Protocol/Vertex.cpp
        ../Protocol/src/Login.cpp
        ../Protocol/src/JoinLobby.cpp
        ../Protocol/src/JoinGame.cpp
        ../Protocol/src/LeaveGame.cpp
        ../Protocol/src/CreateGame.cpp
        ../Protocol/src/ListGame.cpp
        ../Protocol/src/Response.cpp
        ../Protocol/src/NewEntity.cpp
        ../Protocol/src/MoveEntity.cpp
        ../Protocol/src/DeleteEntity.cpp
        ../Protocol/src/PlayerEntered.cpp
        ../Protocol/src/PlayerAccepted.cpp
        ../Protocol/src/PlayerLeaved.cpp
        ../Protocol/src/PlayerMove.cpp

        src/Game.cpp
        headers/Game.hpp
        src/Player.cpp
        headers/Player.hpp
        headers/SafeQueue.hpp
        headers/LibLoader.hpp
        headers/threads/CrossPlatformThreads.hpp
        headers/threads/IThreads.hpp

        headers/clock/CrossPlatformClock.hpp
        headers/clock/IClock.hpp


        headers/fileSystem/IFs.hpp
        headers/fileSystem/CrossPlatformFs.hpp
        headers/fileSystem/UnixFs.hpp
        headers/Spawner.hpp
        src/Spawner.cpp
        src/LibLoader.cpp

        src/fileSystem/UnixFs.cpp
        ecs/*.cpp
        ecs/*.hpp
        ecs/components/*.cpp
        ecs/components/*.hpp
        ecs/systems/*.cpp
        ecs/systems/*.hpp
)

if(UNIX)
  set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra -g -w")
  add_executable(
    r-type
    ${src_files_unix}
    ${src_files_common}
  )
  add_definitions("-DSERVER")
  target_link_libraries (r-type pthread dl)

endif(UNIX)

if(WIN32)
SET(mylibSRCS ${src_files_common} ${src_files_win})
  add_executable(
    r-type
	${src_files_win}
    ${src_files_common}
          ../Protocol/src/PlayerLeaved.cpp ../Protocol/headers/PlayerLeaved.hpp ../Protocol/src/PlayerMove.cpp ../Protocol/headers/PlayerMove.hpp)

endif(WIN32)
