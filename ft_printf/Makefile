NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror 

SRCS = ft_printf.c ft_puthex.c ft_print_string.c ft_putptr.c

RM = rm -f 

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar -csr $@ $^

%.o : %.c 
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all