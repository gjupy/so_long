# so_long

## Usage
### Requirements to run the game
Only tested on **macOS Catalina (Version 10.15.7)**.<br>
For all other OS it is not guaranteed to work.<br>
OpenGL and AppKit is required to run it.<br>
Click [here](https://github.com/codam-coding-college/MLX42/blob/master/README.md) for more information about the installation.<br>

### Map
A valid map is structured as followed:<br>
- 1 player (`P`)
- at least 1 exit (`E`)
- at least 1 collectible (`C`)`
- is recatangular
- has a solid outside border out of walls (`1`)
- all the empty spaces are filled with `0`
- map has to be `.ber`
- no other characters than:
  * `P`
  * `E`
  * `C`
  * `1`
  * `0`
- i.e. `map1.ber`:
- one new line after the map is valid, if there is anything else, it is not valid

```
1111111111111
10010000000C1
1000011111001
1P0011E000011
1111111111111
```

<br>

### During the game
The player can only be moved by `WASD`.<br>
The player can not move into walls.<br>
The player can only exit if all collectibles are collected.<br>
The amount of movements is counted and displayed in the terminal.<br>
Every try to move even if it is invalid will be counted as one move.<br>

All the visualization is done with the help of the [MLX42 library](https://github.com/codam-coding-college/MLX42).<br>

### How to run the game

All of the commands should be run in the root of the directory.<br>
- compile with `make`
- run the game with `./so_long maps/map1.ber`
