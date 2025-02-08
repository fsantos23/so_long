# 🎮 So_long

A simple 2D game made with MinilibX, part of the 42 curriculum.

## 🎯 Game Overview

- Collect all items
- Reach the exit
- Track movement count

## 🗺️ Map Elements

- `1` - Wall
- `0` - Empty space
- `P` - Player starting position
- `C` - Collectible
- `E` - Exit
- `X` - Enemy (bonus)

## 🚀 Installation

```bash
git clone https://github.com/fsantos23/so_long.git
cd so_long
make
```

## 🎲 How to Play

```bash
./so_long maps/map_1.ber
```

### Controls
- `W` or `↑` - Move up
- `S` or `↓` - Move down
- `A` or `←` - Move left
- `D` or `→` - Move right
- `ESC` - Exit game

## 📋 Map Requirements

- File extension: `.ber`
- Rectangular shape
- Surrounded by walls
- Single player (P)
- At least one collectible (C)
- Single exit (E)
- Valid path exists
- Minimum size: 3x3

Example map:
```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

## ⚙️ Requirements

- GCC compiler
- Make
- MinilibX library
- X11 development files

## 🎨 Graphics

- Sprite size: 32x32 pixels
- XPM format
- Consistent theme

## 🐛 Error Handling

- Invalid map format
- Missing elements
- No valid path
- Memory allocation
- File operations
- MLX errors

## ⭐ Show your support

Give a ⭐️ if this project helped you!
