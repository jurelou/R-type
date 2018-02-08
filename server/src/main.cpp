
#include "Server.hpp"

int	main(int ac, char ** av)
{
    if (ac != 2)
	{
        std::cerr << "Usage: " << av[0] << " [ port ]" << std::endl;
		return 0;
	}
  new Server(av[1]);
  return 0;
}
