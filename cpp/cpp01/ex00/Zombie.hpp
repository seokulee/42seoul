#ifndef ZOMBIE_HPP_
# define ZOMBIE_HPP_

# include <iostream>

class Zombie {
	private:
		std::string name;

	public:
		Zombie();
		~Zombie();
		void announce(void);
		void setName(std::string name);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif
