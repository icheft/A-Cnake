# A CNAKE

An uni year 1 final project for IM1003 Programming Design. The simple but fascinating game is developed all by ourselves with a little help from YouTube. Feel free to make it cooler. 

The entire project is built natively on macOS with some *terminal commands* and *Visual Studio Code* (that's why there's a `.vscode` setting folder and a `acnake.code-workspace` for opening a workspace in VS Code.) In fact, any text editors can do the job. `SFML` library is required to build this game. 


Developing this project does not require any IDE nor Windows (you can definitely run it on Windows though). Building this project is easy (not sure for Windows, tell us after you successfully build!) on any platform.

## How to Play
Two pre-set snakes are for you (and your friend) to play:
![blue snake](resources/images/blue.png)
![yellow-snake](resources/images/yellow.png)

Instructions (can be seen in the game itself):
![info page1](resources/images/instra1.png)
![info page2](resources/images/instra2.png)
![info page3](resources/images/instra3.png)

Demo:
![start](resources/images/beginning-window.png)
![play](resources/images/gameplay.png)

See demo on YouTube [here](https://youtu.be/ZDKSKEFhWOg).


## To Do
### Current Version Game (v1.4): 
- [ ] 1. Separate main.cpp into different classes
- [ ] 2. Minor bugs 


### v2 or later: 
- [ ] 1. Settings
   - [ ] 1. sound on/off
   - [ ] 2. speed
- [ ] 2. place bomb, and your lenth will decrease
- [ ] 3. Single player mode
- [ ] 4. connected through server
- [ ] 5. Even more players
- [ ] 6. Shoot from mouth lol
- [ ] 7. Speed up


## Build
### macOS
Pre-requisite: 
+ SFML
+ Homebrew

If you don't have the above programs loaded on your mac, make sure to download [homebrew](https://brew.sh) first.
Type `/usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"` on your terminal prompt. 

Download **SFML** through terminal: 
Type `brew install SFML`. (If your user setting doesn't fit the system requirement, i.e. your are not the root user, please follow the instruction on your terminal prompt.)

Download this repository, copy and paste `git clone https://gitlab.com/icheft/snake.git` in your terminal. 

It should create a folder name **snake**.

Go to your project directory by typing `cd snake`, then type in `make`.

You should be able to run the game by typing `./A\ Cnake`. Or, you can follow the instructions shown on your terminal prompt. 

### Windows 
:) No offense. But it should be easy :)

## Archive
- [x] 1. win, lose, 平手, play again windows
    + Add player 1 (blue snake) wins
    + Add player 2 (yellow snake) wins
    + Add Fair play
    + Play again button(?)
- [x] 2. Add sound effects
- [x] 3. Add pause state (no beautiful UI though, the frame will be paused however.)
- [x] 4. Instruction window

## Contributors
+ Pony
+ Watermelon Man
+ Other resources from the Internet (Mostly from [SFML-dev.org](https://www.sfml-dev.org))