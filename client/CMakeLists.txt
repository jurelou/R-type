cmake_minimum_required(VERSION 2.6) 
 
project(RTypeClient) 
 
include_directories ("inc/" "../Protocol" "../Protocol/headers" "../Network" "../Network/headers" "../Network/headers/Unix" "../Network/headers/Windows" "src/")


set(EXECUTABLE_OUTPUT_PATH bin)


if(CMAKE_COMPILER_IS_GNUCXX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra")
endif(CMAKE_COMPILER_IS_GNUCXX)

file (
		GLOB_RECURSE
		src_files_unix
		../Network/headers/Unix/UnixSocket.hpp
		../Network/src/Unix/UnixSocket.cpp
		../Network/src/Unix/SfmlSocket.cpp
		../Network/headers/Unix/SfmlSocket.hpp
)

file (
		GLOB_RECURSE
		src_files_win
		../Network/headers/Windows/WindowsSocket.hpp
		../Network/src/Windows/WindowsSocket.cpp
		../Network/src/Windows/SfmlSocketWindows.cpp
		../Network/headers/Windows/SfmlSocketWindows.hpp
)


file (
		GLOB_RECURSE
		src_files_common            
  		../Protocol/ARequest.cpp 
  		../Protocol/Serializer.cpp
  		../Protocol/Vertex.cpp
  		../Protocol/src/Login.cpp 
  		../Protocol/src/JoinLobby.cpp 
  		../Protocol/src/JoinGame.cpp 
  		../Protocol/src/LeaveGame.cpp 
  		../Protocol/src/CreateGame.cpp 
  		../Protocol/src/Response.cpp 
  		../Protocol/src/ListGame.cpp
  		../Protocol/src/Response.cpp
  		../Protocol/src/NewEntity.cpp
  		../Protocol/src/MoveEntity.cpp
  		../Protocol/src/DeleteEntity.cpp
  		../Protocol/src/PlayerEntered.cpp
  		../Protocol/src/PlayerAccepted.cpp
  		../Protocol/src/PlayerLeaved.cpp
  		../Protocol/src/PlayerMove.cpp
  
  		src/CreateGameMenu.cpp
		  src/EntityManager.cpp
  		src/LoginMenu.cpp 
  		src/Client.cpp
		  src/Bullet.cpp
		  src/Human.cpp
		  src/Obstacle.cpp
		  src/Factory.cpp
  		src/JoinGameMenu.cpp 
  		src/Player.cpp 
  		src/SFMLSoundEngine.cpp 
  		src/LobbyMenu.cpp
  		src/SFMLResourceManager.cpp
		  src/Monster.cpp
  		src/SFMLMenuText.cpp
  		src/SFMLFont.cpp
  		src/EditSkinsMenu.cpp 
  		src/MainMenu.cpp
  		src/Loading.cpp
  		src/SFML.cpp 
  		src/SFMLSprite.cpp 
  		src/Game.cpp 
  		src/MenuScene.cpp 
  		src/SFMLMenuEvent.cpp
      src/SFMLGameEvent.cpp 
  		src/main.cpp 
  		src/GameScene.cpp 
  		src/MovableBackground.cpp 
  		src/SFMLSound.cpp 
) 

if(UNIX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")  
  add_executable(RTypeClient ${src_files_unix} ${src_files_common})  
  set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")  
  find_package(SFML 2.3 REQUIRED system window graphics network audio)  
  if (SFML_FOUND)  
      include_directories(${SFML_INCLUDE_DIR})  
      target_link_libraries(RTypeClient ${SFML_LIBRARIES})  
  endif()
endif(UNIX)

if(WIN32)
	SET(mylibSRCS ${src_files_common} ${src_files_win})
	add_executable(
			RTypeClient
			${src_files_win}
			${src_files_common}
	)
	target_link_libraries (RTypeClient sfml-system sfml-window sfml-graphics sfml-network sfml-audio)

endif(WIN32)
