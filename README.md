# Ducks2- Final Fantasy Inspired RPG Project
  
<!--Partners and contribution-->
## Michael Habermann, Tyler LaFleur and Zackary Morrow
### Contribution:
* Michael - Made the Tiles Class, Overworld, and spritework(Credits: final fantasy 1 textures)
* Tyler - Managed workflow, Created the battle Sequence, including all combat and classes, Also merged everything together
* Zack - Menu System, including Main menu and menus in game
  
<!--How to play-->
### How to play
* Title Screen
  * Arrow keys are used to move up and down
  * Enter is used for selecting choice
* Overworld
  * Arrow keys are used to move around the world
  * Escape is used to enter the main menu
  * While moving, there is a random chance for a combat to happen
* Main Menu
  * Arrow keys are used to move up and down
  * Enter must be held down to see menu choice
  * Q used to go back to overworld
* Combat
  * Arrow keys are used to traverse up and down the menu
  * Enter is used to select a choice
  * Escape is used to go back on a choice
  
<!--Combat Abilities-->
### Choices
* Fight: Deal physical damage to the enemy.
* Skills/Magic: Four options unique to each of the classes
  * Smite (Paladin): Deal physical and magical damage to enemy
  * Cure (White Mage): Heal a party member
  * Fire (Black Mage): Deal double magical damage to enemy
  * Slash (Fighter): Deal double physical damage to enemy
* Items: Use a potion to heal a party member
* Run: Run away from fight, ending combat sequence

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
git clone https://github.com/TSLAFLEUR/CS151-SP-2023-Final-Project.git FinalDuck
```
7. Change into our directory
```
cd FinalDuck
```
8. Compile our game
```
g++ *.cpp -o FinalDuck -lsfml-system -lsfml-window -lsfml-graphics
```
9. Run the executable
```
./FinalDuck
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
  * I would have liked to improve on the menu by adding transition animations as well as animated icons for spells and items
  * I think that adding sound would have been interesting as well but we just didn't have the time.
  
* Tyler:  
  * I would have liked to create a battle system that supported multiple enemies instead of just one, as well as create more enemy types.
  * I would have also liked to create more items for the players to use, such as an ether to regain MP

[StS]: https://cdn.discordapp.com/attachments/1053728427426992248/1103506185568649277/image.png
[ORW]: https://cdn.discordapp.com/attachments/1053728427426992248/1103371470329098240/image.png
[BS]: https://cdn.discordapp.com/attachments/1053728427426992248/1103371184755724288/image.png
[GO]: https://cdn.discordapp.com/attachments/1053728427426992248/1103371929420824576/image.png
