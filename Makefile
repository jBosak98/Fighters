FLAGS= -g -Wall -Wextra -lsfml-window -lsfml-graphics -lsfml-system -o
NAME = Fighters

build:
	g++ $(FLAGS) $(NAME) main.cpp
