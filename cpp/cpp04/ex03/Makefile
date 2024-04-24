NAME = character

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

SRC_DIR = ./
OBJ_DIR = ./obj/

SRC = main.cpp \
		AMateria.cpp \
		Character.cpp \
		Cure.cpp \
		Ice.cpp \
		MateriaSource.cpp
OBJ = $(SRC:.cpp=.o)
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))

INCLUDES = -I./
INC = AMateria.hpp \
	Character.hpp \
	Cure.hpp \
	Ice.hpp \
	ICharacter.hpp \
	IMateriaSource.hpp \
	MateriaSource.hpp

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@ $(INCLUDES)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(INC)
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