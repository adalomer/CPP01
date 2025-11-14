#include "Zombie.hpp"

int	main(void)
{
	Zombie*	heapZombie;

	// Zombie on the stack
	randomChump("StackZombie");

	// Zombie on the heap
	heapZombie = newZombie("HeapZombie");
	heapZombie->announce();
	delete heapZombie;

	return (0);
}
