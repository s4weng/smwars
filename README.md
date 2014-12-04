(To Be Named)
====

This repository will contain a tank-like game, written in **C++** and utilizing [SFML](http://www.sfml-dev.org/).
It will play out similarly to other online tank games (turn based shooting, with the goal of destroying/killing the other players), but will have character/sprites instead.

Players will be able to move around the map before selecting their weapon of choice and firing at the other players. If the player hits another target, they will deal damage based on their weapon choice (and possibly other factors). When a player's health points hit 0, they will be taken out of the game until the round is over (one player remains).

Basic to-do list:
- turn-based system
- basic attack functionality
  - human
  - AI
- multiple human player support
- multiple AI support

Required Graphical Tasks:
- Sprites with transparent background
- Background items for maps (e.g., mountains, trees, snow, etc.)
- Weapons (sword, staff, bow and arrows)
- Animations for attacks (shooting spells, shooting arrows, swinging sword)