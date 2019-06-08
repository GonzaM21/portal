cmake_minimum_required(VERSION 3.1)
project (portal)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set (CMAKE_CXX_FLAGS -pthread)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -g")
set(CMAKE_CXX_STANDARD 11)

add_executable(Client
	src/client/client.cpp
	src/client/client_communicator.cpp
	src/client/client_communicator.h
	src/client/renderable.cpp
	src/client/renderable.h
	src/client/Joiner.h
	src/client/Joiner.cpp
	src/common/common_error.cpp
	src/common/common_error.h
	src/common/common_protocol.cpp
	src/common/common_protocol.h
	src/common/common_cola_protegida.cpp
	src/common/common_cola_protegida.h
	src/common/common_socket_connect.cpp
	src/common/common_socket_connect.h
	src/common/Thread.cpp
	src/common/Thread.h
	src/vista/Rect.cpp
	src/vista/Rect.h
	src/vista/Camara.cpp
	src/vista/Camara.h
	src/vista/EventsHandler.cpp
	src/vista/EventsHandler.h
	src/vista/Model.cpp
	src/vista/Model.h
	src/vista/ModelFacade.cpp
	src/vista/ModelFacade.h
	src/vista/Acid/Acid.cpp
	src/vista/Acid/Acid.h
	src/vista/Acid/Idle_acid.cpp
	src/vista/Acid/Idle_acid.h
	src/vista/Acid/Touched_acid.cpp
	src/vista/Acid/Touched_acid.h
	src/vista/Sprite.cpp
	src/vista/Sprite.h
	src/vista/Blocks/Stone_block.cpp
	src/vista/Blocks/Stone_block.h
	src/vista/Blocks/Metal_block.cpp
	src/vista/Blocks/Metal_block.h
	src/vista/Blocks/Shoot_block.cpp
	src/vista/Blocks/Shoot_block.h
	src/vista/Emitter/Emitter.cpp
	src/vista/Emitter/Emitter.h
	src/vista/Emitter/Emitter_sprite.cpp
	src/vista/Emitter/Emitter_sprite.h
	src/vista/Emitter/Target_sprite.h
	src/vista/Emitter/Target_sprite.cpp
	src/vista/Blocks/Stone_block_sprite.cpp
	src/vista/Blocks/Stone_block_sprite.h
	src/vista/Blocks/Metal_block_sprite.cpp
	src/vista/Blocks/Metal_block_sprite.h
	src/vista/Blocks/Shoot_block_sprite.cpp
	src/vista/Blocks/Shoot_block_sprite.h
	src/vista/Gate/Gate.cpp
	src/vista/Gate/Gate.h
	src/vista/Gate/Closed_gate.cpp
	src/vista/Gate/Closed_gate.h
	src/vista/Gate/Open_gate.cpp
	src/vista/Gate/Open_gate.h
	src/vista/Gate/Opening_gate.cpp
	src/vista/Gate/Opening_gate.h
	src/vista/Gate/Closing_gate.cpp
	src/vista/Gate/Closing_gate.h
	src/vista/Player/Player.cpp
	src/vista/Player/Player.h
	src/vista/Player/Idle_player.cpp
	src/vista/Player/Idle_player.h
	src/vista/Player/RestingIdle_player.cpp
	src/vista/Player/RestingIdle_player.h
	src/vista/Player/Running_player.cpp
	src/vista/Player/Running_player.h
	src/vista/Player/RunningShoot_player.cpp
	src/vista/Player/RunningShoot_player.h
	src/vista/Player/Dying_player.cpp
	src/vista/Player/Dying_player.h
	src/vista/Player/Stop_player.cpp
	src/vista/Player/Stop_player.h
	src/vista/Player/Dancing_player.cpp
	src/vista/Player/Dancing_player.h
	src/vista/Portal/Portal.cpp
	src/vista/Portal/Portal.h
	src/vista/Portal/Portal_blue_sprite.cpp
	src/vista/Portal/Portal_blue_sprite.h
	src/vista/Portal/Portal_orange_sprite.cpp
	src/vista/Portal/Portal_orange_sprite.h
	src/vista/PowerBall/PowerBall.cpp
	src/vista/PowerBall/PowerBall.h
	src/vista/PowerBall/Flying_powerball.cpp
	src/vista/PowerBall/Flying_powerball.h
	src/vista/PowerBall/Hitting_powerball.cpp
	src/vista/PowerBall/Hitting_powerball.h
	src/vista/PowerBall/Paw_powerball.cpp
	src/vista/PowerBall/Paw_powerball.h
	src/vista/Button/Button.cpp
	src/vista/Button/Button.h
	src/vista/Button/ButtonOff_button.cpp
	src/vista/Button/ButtonOff_button.h
	src/vista/Button/ButtonOn_button.cpp
	src/vista/Button/ButtonOn_button.h
	src/vista/Rocks/Rock.cpp
	src/vista/Rocks/Rock.h
	src/vista/Rocks/Rock_rock_sprite.cpp
	src/vista/Rocks/Rock_rock_sprite.h
	src/vista/SdlException.cpp
	src/vista/SdlException.h
	src/vista/Window.cpp
	src/vista/Window.h
)

add_executable(Server
    src/server/server.cpp
	src/server/modelo/World.cpp
	src/server/modelo/World.h
	src/server/modelo/InvalidPosition.cpp
	src/server/modelo/InvalidPosition.h
	src/server/modelo/Chell_Player.cpp
	src/server/modelo/Chell_Player.h 
	src/server/modelo/Block.cpp
	src/server/modelo/Block.h
	src/server/modelo/Ground.cpp
	src/server/modelo/Ground.h
	src/server/modelo/MyContactListener.cpp
	src/server/modelo/MyContactListener.h
	src/server/modelo/Acid.cpp
	src/server/modelo/Acid.h
	src/server/modelo/Entity.h
	src/server/modelo/Filter_Data.cpp
	src/server/modelo/Filter_Data.h
	src/server/modelo/Metal_Block.cpp
	src/server/modelo/Metal_Block.h
	src/server/modelo/Rock.cpp
	src/server/modelo/Rock.h
	src/server/modelo/Stone_Block.cpp
	src/server/modelo/Stone_Block.h
	src/server/modelo/Energy_Ball.cpp
	src/server/modelo/Energy_Ball.h
	src/server/server_game_loop.cpp
	src/server/server_game_loop.h
	src/server/server_sender.cpp
	src/server/server_sender.h
	src/server/server_model.cpp
	src/server/server_model.h
	src/server/server_socket_accept.cpp
	src/server/server_socket_accept.h
	src/server/server_protocol.cpp
	src/server/server_protocol.h
	src/server/server_client_acceptor.cpp
	src/server/server_client_acceptor.h
	src/server/server_room_game.cpp
	src/server/server_room_game.h
	src/server/server_communicator.cpp
	src/server/server_communicator.h
	src/server/server_room_manager.cpp
	src/server/server_room_manager.h
	src/server/server_command.cpp
	src/server/server_command.h
	src/server/server_command_join.cpp
	src/server/server_command_join.h
	src/server/server_command_mates.cpp
	src/server/server_command_mates.h
	src/server/server_command_start.cpp
	src/server/server_command_start.h 
	src/server/server_command_factory.cpp
	src/server/server_command_factory.h
	src/server/server_command_jump.cpp
	src/server/server_command_jump.h
	src/server/server_command_move.cpp
	src/server/server_command_move.h
	src/common/common_error.cpp
	src/common/common_error.h
	src/common/common_protocol.cpp
	src/common/common_protocol.h
	src/common/common_cola_protegida.cpp
	src/common/common_cola_protegida.h
	src/common/common_socket_connect.cpp
	src/common/common_socket_connect.h
	src/common/Thread.cpp
	src/common/Thread.h
	src/server/level_creator/factory_objetcs.cpp
	src/server/level_creator/factory_objetcs.h
	src/server/level_creator/map_parser.cpp
	src/server/level_creator/map_parser.h
	src/server/level_creator/object_acid.cpp
	src/server/level_creator/object_acid.h
	src/server/level_creator/object.cpp
	src/server/level_creator/object_door.cpp
	src/server/level_creator/object_door.h
	src/server/level_creator/object_energy_ball.cpp
	src/server/level_creator/object_energy_ball.h
	src/server/level_creator/object_energy_barrel.cpp
	src/server/level_creator/object_energy_barrel.h
	src/server/level_creator/object.h
	src/server/level_creator/object_lunch_block.cpp
	src/server/level_creator/object_lunch_block.h
	src/server/level_creator/object_metal_block.cpp
	src/server/level_creator/object_metal_block.h
	src/server/level_creator/object_portal.cpp
	src/server/level_creator/object_portal.h
	src/server/level_creator/object_rock.cpp
	src/server/level_creator/object_rock.h
)


# Agrego la carpeta con los headers autogenerados a los includes
#message("Agregando '${PROJECT_BINARY_DIR}' como directorio de includes")
#include_directories(${PROJECT_BINARY_DIR})


#add_executable (Client
#  src/client/client.cpp
#) 

#add_executable (Server
#  src/server/server.cpp
#)

target_link_libraries(Client SDL2 SDL2_image)
add_subdirectory(src/server/modelo/3rdparty/Box2D-cmake)
#target_compile_features(Server PUBLIC cxx_std_17)
target_link_libraries(Server TG::Box2D)
