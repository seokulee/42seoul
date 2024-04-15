NAME = megaphone

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
AR = ar
RM = rm -rf

SRC = megaphone.cpp
SRCS = $(addprefix $(SRC_DIR), $(SRC))

OBJ = $(SRCS:.cpp=.o)
OBJS_DIR = obj/
OBJS = $(addprefix $(OBJS_DIR), $(OBJ))

all : $(NAME)

$(NAME) : $(OBJS_DIR) $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

$(OBJS_DIR):
	mkdir $(OBJS_DIR)

$(OBJS_DIR)%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

clean:
	$(RM) $(RMFLAGS) $(OBJS_DIR)

fclean:
	make clean
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re
