cmd = c++
flags = -Wall -Wextra -Werror -std=c++98
sources = main.cpp zombie.cpp randomChump.cpp newZombie.cpp
objs = $(sources:.cpp=.o)
NAME = zombie

all: $(NAME)

$(NAME): $(objs) 
	$(cmd) $(flags) $(objs) -o $(NAME)

%.o: %.cpp Zombie.hpp
	$(cmd) $(flags) -c $< -o $@

clean:
	rm -f $(objs)

fclean: clean
	rm -f $(NAME)

re: fclean all