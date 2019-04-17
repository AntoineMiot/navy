##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## 
##

SRC	=	main.c	\
		disp_usage.c	\
		check_good_file_pos.c	\
		check_good_file_pos_two.c	\
		pos_boat_two.c	\
		pos_boat_three.c	\
		pos_boat_four.c	\
		pos_boat_five.c	\
		check_boat_same_place_one.c	\
		check_boat_same_place_one_two.c	\
		check_boat_same_place_one_three.c	\
		check_boat_same_place_one_four.c	\
		check_boat_diff_sameway_x.c	\
		check_boat_diff_sameway_x_two.c	\
		check_boat_diff_sameway_x_three.c	\
		check_boat_diff_sameway_x_four.c	\
		check_boat_diff_sameway_y.c	\
		check_boat_diff_sameway_y_two.c	\
		check_boat_diff_sameway_y_three.c	\
		check_boat_diff_sameway_y_four.c	\
		distrib_check.c	\
		check_map_victory.c	\
		handler.c	\
		multi_check_and_map.c	\
		multi_check_and_map_two.c	\
		multi_check_and_map_three.c	\
		display_map.c	\
		recept_input.c	\
		player_one.c	\
		player_two.c

OBJ		=	$(SRC:.c=.o)

NAME	=	navy

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my/
	gcc -o $(NAME) $(OBJ) -L./lib -lmy -I./include
	rm *.o

clean:
	rm -f $(OBJ)
	rm -f vgcore.*
	rm -f *.o

fclean:	clean
	make fclean -C lib/my/
	rm -f $(NAME)

re:	fclean all
