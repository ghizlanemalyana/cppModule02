cmd = c++
flags = -Wall -Wextra -Werror -std=c++98
sources = main.cpp Fixed.cpp
objs = $(sources:.cpp=.o)
NAME = fixed

all: $(NAME)

$(NAME): $(objs) 
	$(cmd) $(flags) $(objs) -o $(NAME)

%.o: %.cpp fixed.hpp
	$(cmd) $(flags) -c $< -o $@

clean:
	rm -f $(objs)

fclean: clean
	rm -f $(NAME)

re: fclean all