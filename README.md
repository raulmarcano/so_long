<h2 align="center"> 🕹️🏆 Welcome to:</h2>
<h1 align="center">So_Long - 2D Adventure Game</h1>
<p align="center">
  So_Long is a 2D adventure game where a king in a castle collects diamonds and avoids green pig enemies.
</p>
<h3 align="center">Languages and Tools:</h3>
<p align="center">
    <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/c/c-original.svg" alt="c" width="40" height="40"/>
    <img src="https://www.vectorlogo.zone/logos/git-scm/git-scm-icon.svg" alt="git" width="40" height="40"/>
    <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/linux/linux-original.svg" alt="linux" width="40" height="40"/>
</p>

<div style="text-align: center;">
  <img src="/img/so_long_gameflow.gif" width="1000" alt="Gameplay flow">
</div>


## Installation
To install so_long, follow these steps:
- Clone the repository.
- Run the make command in the project root directory.
## Usage
To run the so_long game, execute the following command:
`/so_long maps/your_map.ber`
### Example map .ber file:
```
1111111
1P00001
1011101
1C0E001
1111111
```

 ## Project Rules and Gameplay
Objective: Collect all diamonds and reach the exit while avoiding green pig enemies.
#### Gameplay:
- The game is in 2D perspective (top-down or side view).
- Use W, A, S, D or arrow keys to move the king.
- The player cannot move through walls.
- The number of moves is displayed in the terminal.
- The game ends when all diamonds are collected and the exit is reached.
#### Map:
- Maps are composed of walls, diamonds, open spaces, exit, and the player's starting position.
- The map must be surrounded by walls, and it must have at least one exit, one diamond, and one starting position.
- Maps use the following characters: 0 (Empty space), 1 (Wall), C (Collectible diamond), E (Exit), P (Player's start position).
#### Window Management:
- Pressing ESC or clicking the red cross closes the window and ends the game.
### Error Handling
The game will terminate and display "Error\n" for the following cases:
- The map file is invalid or not found.
- The map is not rectangular.
- The map is not surrounded by walls.
- Duplicate start or exit positions are found.
- No valid path from the start to the exit exists.
#### Floodfill
The game uses the floodfill algorithm to guarantee that the map can be solved.
<div>
  <p>Floodfill Example:</p>
  <img src="/img/floodfill.gif" width="300" alt="Algorithm illustration">
</div>

## Additional Features (Bonus)
- Player loses if they touch an enemy.
- Sprite animations for movements and actions.
- Display move counter on the game screen instead of the terminal.
