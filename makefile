run: main.o Menu.o
	@g++ main.o Menu.o -o game -lsfml-window -lsfml-graphics -lsfml-system

main.o: main.cpp
	g++ main.cpp -c

Menu.o: Menu.cpp Menu.hpp
	g++ Menu.cpp -c

clean:
	rm -rf *.o