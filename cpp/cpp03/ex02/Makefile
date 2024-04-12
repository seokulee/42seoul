NAME = fragtrap

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
AR = ar
RM = rm -rf

SRC_DIR = ./
OBJ_DIR = ./obj/

SRC = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
OBJ = $(SRC:.cpp=.o)
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))

INCLUDES = -I./

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@ $(INCLUDES)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean:
	make clean
	$(RM) $(RMFLAGS) $(NAME)

re :
	make fclean
	make all

