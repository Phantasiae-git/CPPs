CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g
RM = rm -rf
NAME = PMergeMe

SRCS = main.cpp utils.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	${CC} ${CFLAGS} -c $< -o $@ -I ./

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

run: all clean
	./$(NAME)

.PHONY: all clean fclean re run