#ifndef         IMAINSCENE_HPP_
# define        IMAINSCENE_HPP_

class           IMainScene {
  public:
    enum SceneState {
      MENU,
      GAME,
      VOID,
    };
    virtual     SceneState  getNextScene() = 0;
};

#endif          /* !IMAINSCENE */