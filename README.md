# A CNAKE

An uni year 1 final project for IM1003 Programming Design. The simple but fascinating game is developed all by ourselves with a little help from YouTube. Feel free to make it cooler. 

## To Do
### Main Game (v1): 
- [ ] 1. Separate main.cpp into different classes
- [ ] 2. Instruction window
- [x] 3. win, lose, 平手, play again windows
    + Add player 1 (blue snake) wins
    + Add player 2 (yellow snake) wins
    + Add Fair play
    + Play again button(?)
- [ ] 4. Add sound effects
- [x] 5. Add pause state (no beautiful UI though, the frame will be paused however.)

### v2 or later: 
1. Settings
   1. sound on/off
   2. speed
2. place bomb, and your lenth will decrease
3. Single player mode
4. connected through server


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

You should be able to run the game by typing `./game`. 

### Windows 

