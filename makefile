# run: objects

run: dir src/main.o src/Menu.o src/Info.o src/Game.o src/Snake.o src/Props.o
	@echo 🏗 [ 97%]  Linking A Cnake!
	@g++ -w obj/main.o obj/Menu.o obj/Info.o obj/Game.o obj/Snake.o obj/Props.o -o A\ Cnake -lsfml-window -lsfml-graphics -lsfml-system -lsfml-audio
	@sleep .2
	@echo 🍺 [100%]  Cheers. Success! Built target A Cnake.
	@echo
	@echo 👾 Type \"./A\ Cnake\" to start the game. Have fun!
	@echo 💬 \(Or type \"make clean\" to clean the project\)

dir:
	@if [ ! -d "obj" ]; then mkdir obj; fi

src/main.o: src/main.cpp
	@echo 🏗 [ 17%]  Building main.cpp
	@g++ -w src/main.cpp -o obj/main.o -c

src/Menu.o: src/Menu.cpp src/Menu.hpp
	@echo 🏗 [ 34%] Building Menu.cpp
	@g++ -w src/Menu.cpp -o obj/Menu.o -c

src/Info.o: src/Info.cpp src/Info.hpp
	@echo 🏗 [ 51%]  Building Info.cpp
	@g++ -w src/Info.cpp -o obj/Info.o -c

src/Game.o: src/Game.hpp src/Game.cpp
	@echo 🏗 [ 67%]  Building Game.cpp
	@g++ -w src/Game.cpp -o obj/Game.o -c

src/Snake.o: src/Snake.hpp src/Snake.cpp
	@echo 🏗 [ 80%]  Building Snake.cpp
	@g++ src/Snake.cpp -o obj/Snake.o -c

src/Props.o: src/Props.cpp src/Props.hpp
	@echo 🏗 [ 93%]  Building Props.cpp
	@g++ src/Props.cpp -o obj/Props.o -c

clean:
	@echo 🧹  [ 70%]  Cleaning objects.
	@rm -rf obj
	@sleep .15
	@echo ✓   [100%] Done.

remove: clean
	@while [ -z "$$CONTINUE" ]; do \
        read -r -p "Rly want to remove the A Cnake game executable? [y/N]: " CONTINUE; \
    done ; \
    [ $$CONTINUE = "y" ] || [ $$CONTINUE = "Y" ] || (echo "👌  Exiting."; exit 1;)
	@echo 🧹  [ 80%]  Removing A Cnake game.
	@rm -rf A\ Cnake
	@echo ✓   [100%] Done.