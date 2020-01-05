run: main.o
	g++ main.o -o game -lsfml-window -lsfml-graphics -lsfml-system

main.o: main.cpp
	g++ main.cpp -c

clean:
	rm -rf *.o