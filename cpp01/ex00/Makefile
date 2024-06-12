CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address
RM = rm -rf
NAME = Zombieeee

SRCS =  Zombie.cpp\
		main.cpp\
		randomChump.cpp\
		newZombie.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	${CC} ${CFLAGS} -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

run: all clean
	./$(NAME)

.PHONY: all clean fclean re run