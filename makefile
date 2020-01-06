run: main.o Menu.o
	@echo 🍺   Buliding Game...
	@g++ main.o Menu.o -o game -lsfml-window -lsfml-graphics -lsfml-system -lsfml-audio
	@echo Cheers. Success!

main.o: main.cpp Game.hpp
	g++ main.cpp -c

Menu.o: Menu.cpp Menu.hpp
	g++ Menu.cpp -c

clean:
	rm -rf *.o