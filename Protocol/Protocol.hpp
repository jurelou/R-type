
#ifndef __PROTOCOL__HPP__
#define __PROTOCOL__HPP__

class Server;
class Client;

namespace Protocol {
  class Serializer;
  enum Command {
    LOGIN = 0,
    LISTGAME,
    JOINLOBBY,
    JOINGAME,
    LEAVEGAME,
    CREATEGAME,
    RESPONSE,
    NEWENTITY,
    MOVEENTITY,
    DELETEENTITY,
    PLAYERENTERED,
    PLAYERACCEPTED,
    PLAYERLEAVED,
    PLAYERMOVE
  };

  enum PlayerAction {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    SHOOT,
  };

    enum EntityType{
        MONSTER,
        HUMAN,
        BULLET,
        OBSTACLE
    };
    enum PlayerStatus{
        SPECTACTOR,
        DEAD,
        INGAME,
        ONLINE,
        OFF,
        OFFLINE,
        INLOBBY
    };

    enum MapLevel{
        EASY = 0,
        MEDIUM,
        HARD,
        LEGENDARY
    };
}

#endif
