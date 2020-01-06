run: main.o Menu.o Info.o
	@echo 🍺   Buliding Game...
	@g++ main.o Menu.o Info.o -o game -lsfml-window -lsfml-graphics -lsfml-system -lsfml-audio
	@echo Cheers. Success!

main.o: main.cpp Game.hpp
	g++ main.cpp -c

Menu.o: Menu.cpp Menu.hpp
	g++ Menu.cpp -c

Info.o: Info.cpp Info.hpp
	g++ Info.cpp -c

clean:
	rm -rf *.o