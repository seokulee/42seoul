NAME = account

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
AR = ar
RM = rm
RMFLAGS = -rf

SRC = Account.cpp\
	tests.cpp

SRC_DIR = ./
SRCS = $(addprefix $(SRC_DIR), $(SRC))

OBJ = $(SRCS:.cpp=.o)
OBJS_DIR = obj/
OBJS = $(addprefix $(OBJS_DIR), $(OBJ))

HDR = Account.hpp
HDRS_DIR = ./
HDRS = $(addprefix $(HDRS_DIR), $(HDR))

all : $(NAME)

$(NAME) : $(OBJS_DIR) $(OBJS) $(HDRS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

$(OBJS_DIR):
	mkdir $(OBJS_DIR)

$(OBJS_DIR)%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(RMFLAGS) $(OBJS_DIR)

fclean: clean
	$(RM) $(RMFLAGS) $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re
