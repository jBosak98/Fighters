FLAGS= -g -Wall -Wextra -lsfml-window -lsfml-graphics -lsfml-system -o
NAME = Fighters
OBJECTS = main.o

build: $(OBJECTS)
	g++ $(FLAGS) $(NAME) $(OBJECTS)
	rm -f *.o

main.o: main.cpp
	g++ -c $(FLAGS) main.o main.cpp
