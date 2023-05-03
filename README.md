# Ducks2- Final Fantasy Inspired RPG Project
  
<!--Partners and contribution-->
## Michael Habermann, Tyler LaFleur and Zackary Morrow
### Contribution:
* Michael - Made the Tiles Class, Overworld, and spritework(Credits: final fantasy 1 textures)
* Tyler - Managed workflow, Created the battle Sequence, including all combat and classes, Also merged everything together
* Zack - Menu System, including Main menu and menus in game
  
<!--How to play-->
### How to play
* Start Screen
  *Arrow keys are used to move up,down,left,right
  *Enter is used for select in the game for the combat sequence
  *If all of your party members lose health there is a game over
  
<!--How to download, compile, and run the game-->
### How to run the game
1. Open the [Ubuntu](https://ubuntu.com/) terminal
2. Update the terminal
```
sudo apt-get update && sudo apt-get upgrade -y
```
3. Install the GNU compiler tools
```
sudo apt-get install build-essential gdb
```
4. Install git
```
sudo apt-get install git
```
5. Install SFML
```
sudo apt-get install libsfml-dev
```
6. Clone our repository
```
git clone https://github.com/TSLAFLEUR/CS151-SP-2023-Final-Project.git FF1
```
7. Change into our directory
```
cd FF1
```
8. Compile our game
```
g++ *.cpp -o FF1 -lsfml-system -lsfml-window -lsfml-graphics
```
9. Run the executable
```
./FF1
```
  
<!--Screen Shots and explaining-->
## This is the start screen for the game  
![StartScreen][StS]  
## This is the "Overworld" where part of the game you move around and can encounter enemies
![Overworld][ORW]  
## This is the battle sequence of the game 
![BattleSequence][BS]  
## The gameover screen if you lose all of your part members
![GameOver][GO]  
  
<!--What we would improve on-->
### What would we improve on?
* Michael:  
  * I would have liked to dedicate more time to the project, giving ample time to create a full dungeon
  * Most of the project is very scalable on my side but time limitations hurt a project of this scope
* Zack:  
  
* Tyler:  

[StS]: https://cdn.discordapp.com/attachments/1053728427426992248/1103371470329098240/image.png
[ORW]: https://cdn.discordapp.com/attachments/1053728427426992248/1103371470329098240/image.png
[BS]: https://cdn.discordapp.com/attachments/1053728427426992248/1103371184755724288/image.png
[GO]: https://cdn.discordapp.com/attachments/1053728427426992248/1103371929420824576/image.png
