# Lode Runner game bootstrap

This project is a bootstrap on which [Jicehel][jicehel] wanted to remake the famous [Lode Runner][loderunner] game. The code I proposed to him is intended for the [ESPboy][espboy] handheld, and is based on the [ESPboy library][lib], but it can easily be adapted to other consoles.

This version supports logical representation and graphical display of bare levels (without enemies or treasures to collect), animation and simplified movement of the avatar, as well as the avatar tracking with a camera view. Only 2 levels are provided, but it's enough to implement most of the features of the final game.

Interactions between the avatar and the map of the current level (such as collisions, or the use of ladders) are not supported at this stage. The player can move freely in all four horizontal and vertical directions... and through walls.

## Game controls

- **Left**, **Right**, **Up** and **Down** buttons let you move the avatar.
- **Top-Left** and **Top-Right** buttons let you switch from one level to another.

## Demo

![Demo][demo]


[jicehel]:    https://github.com/jicehel
[loderunner]: https://en.wikipedia.org/wiki/Lode_Runner
[espboy]:     https://www.espboy.com
[lib]:        https://m1cr0lab-espboy.github.io/ESPboy/
[demo]:       demo/lode-runner.gif