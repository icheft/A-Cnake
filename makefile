run: main.o Menu.o Info.o
	@echo 🏗 [ 80%]  Buliding Game
	@g++ -w main.o Menu.o Info.o -o A\ Cnake -lsfml-window -lsfml-graphics -lsfml-system -lsfml-audio
	@sleep .3
	@echo 🏗 [ 99%]  Linking A Cnake!
	@sleep .2
	@echo 🍺 [100%]  Cheers. Success! Built target A Cnake.
	@echo
	@echo 👾 Type \"./A\ Cnake\" to start the game. Have fun!

main.o: main.cpp Game.hpp
	@echo 🏗 [ 25%]  Building main.cpp
	@g++ -w main.cpp -c
	@sleep .15

Menu.o: Menu.cpp Menu.hpp
	@echo 🏗 [ 50%] Building Menu.cpp
	@g++ -w Menu.cpp -c
	@sleep .15

Info.o: Info.cpp Info.hpp
	@echo 🏗 [ 75%]  Building Info.cpp
	@g++ -w Info.cpp -c
	@sleep .15

clean:
	@echo 🧹  [ 70%]  Removing redundant files.
	@rm -rf *.o A\ Cnake
	@sleep .15
	@echo ✓   [100%] Done.