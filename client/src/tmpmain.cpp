#include <iostream>
#include <string>
#include "Client.hpp"

int main(int ac, char *av[])
{
  if (ac == 2)
    {
      std::string port = av[1];
      Client *client = new Client();
        /* connection a un server */
        if (client->initSocket("127.0.0.1", port) == true) {

            std::cout << "CONNECTION ESTABLISHED" << std::endl;
            /* login */
            if (client->SendLogin("mder") == true) {
                /* create game */
                if ((client->SendCreateGame("mapartie", Protocol::MapLevel::LEGENDARY)) == true)
                    std::cout << "GAME BIEN CREE" << std::endl;
                else
                    std::cout << "GAME IMPOSSIBLE A CREER" << std::endl;
                /* list game */
                client->SendListGame();
                for (auto it: client->getGamesList()){
                    std::cout << "Game: "<<it << std::endl;
                }
                /* join loby */
                if (client->SendJoinLobby("mapartie") == true)
                    std::cout << "JOINED LOBBY" << std::endl;
                else
                    std::cout << "impossible de join le lobby" << std::endl;
                /* quit game */
                client->SendExitGame();
                std::cout << "exited game" << std::endl;

            } else {
                std::cout << "LOGIN ERROR" << std::endl;
            }
	    while (42){};
        } else {
            std::cout << "CONNECTION FAILED" << std::endl;
            return (1);
        }
    }
  else
    {
      std::cerr << "Use : ./r-type [PORT]" << std::endl;
    }
}

