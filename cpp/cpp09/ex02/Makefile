NAME = PmergeMe

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

SRC_DIR = ./
OBJ_DIR = ./obj/

SRC = $(wildcard $(SRC_DIR)*.cpp)
OBJ = $(SRC:.cpp=.o)
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))

INCLUDES = -I./
INC = $(wildcard *.hpp)

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
