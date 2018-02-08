#ifndef         IMENUSCENE_HPP__
# define        IMENUSCENE_HPP__

#include        "IScene.hpp"

class           IMenuScene : public IScene {
  public:
      enum          MenuState {
        MAIN_MENU = 1,
        EDIT_SKINS,
        CREATE_GAME,
        JOIN_GAME,
        LOGIN,
        LOBBY,
        GOTO_GAME,
        NOTHING,
      };
      virtual   MenuState getNextState() = 0;
      virtual   void resetState() = 0;
};

#endif          /* !IMENUSCENE_HPP__ */