NAME := ft_containers
CXX := clang++
CXXFLAGS := -std=c++98 -pedantic -Wall -Wextra -Werror #-g3 -fsanitize=address
SRCS := main.cpp
OBJS := $(SRCS:.cpp=.o)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
