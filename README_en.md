# FdF

42 core curriculum project: a wireframe representation of a landscape, built
from a map of 3D points.

## Table of contents

- [Description](#description)
- [.fdf file format](#fdf-file-format)
- [Installation](#installation)
- [Usage](#usage)
- [Controls](#controls)
- [How it works](#how-it-works)
- [Project structure](#project-structure)
- [Known limitations](#known-limitations)
- [AI usage](#ai-usage)

## Description

FdF reads a `.fdf` file describing the altitude of every point of a map, and
displays the corresponding landscape as a wireframe in a graphical window,
using the MinilibX.

The project handles:

- Isometric and perspective projection.
- Rotation on the X and Y axes.
- Translation and zoom (mouse wheel).
- Color interpolation between two points of different altitude.
- A z-buffer for depth handling.

## .fdf file format

Each line of the file represents a line of the map, each number a point
whose position (x, y) matches its position in the file, and its value the
altitude (z).

```
0 0 1 2 3 4 5 6 7 8 9
0 0 0 1 2 3 4 5 6 7 8
0 0 0 0 1 2 3 4 5 6 7
```

A hexadecimal color can be added after an altitude, in the form
`altitude,0xRRGGBB`, to color a specific point.

Sample maps are provided in `test_maps/` and `landscape/`.

## Installation

The project builds on Linux (tested with the Linux MinilibX provided in the
repo) and requires the following dependencies:

```sh
sudo apt-get update && sudo apt-get install -y libxext-dev libx11-dev
```

Clone and build:

```sh
git clone https://github.com/leogranger/fdf.git
cd fdf
make
```

## Usage

```sh
./fdf <file.fdf>
```

Example:

```sh
./fdf test_maps/42.fdf
```

The program rejects any file without the `.fdf` extension, as well as any
argument count other than 1.

## Controls

| Key            | Action                     |
|----------------|-----------------------------|
| Arrows         | Rotation                    |
| W / A / S / D  | Translation                 |
| Mouse wheel    | Zoom in / out                |
| 1              | Isometric projection        |
| 2              | Perspective projection      |
| R              | Reset view                  |
| ESC            | Close the window              |

The controls are also printed to the terminal when the program starts.

## How it works

Rendering happens in several steps:

1. **Parsing** (`parse.c`, `map.c`, `map_utils.c`): reads the file and
   builds the point map, checking the format and color values.
2. **Transformation** (`matrix.c`, `rotation.c`, `translation_scaling.c`):
   applies rotation, translation and scaling matrices to the points, then
   projects them (isometric or perspective).
3. **Rendering** (`draw.c`, `points.c`, `color.c`): draws segments between
   points using Bresenham's line algorithm, with color interpolation and
   depth handling through a z-buffer.
4. **Events** (`hooks.c`, `events.c`): handles keyboard and mouse input for
   real-time rotation, translation, zoom and projection switching.

## Project structure

```
.
├── srcs/               # Project sources
├── libft/               # Personal library (libft)
├── minilibx-linux/      # MinilibX (provided by 42, for Linux)
├── test_maps/           # Sample .fdf maps
├── landscape/           # Larger, real-world-scale .fdf maps
├── include/             # Headers
└── Makefile
```

Makefile rules:

- `make`: builds the project.
- `make clean`: removes object files.
- `make fclean`: also removes the executable.
- `make re`: rebuilds the project from scratch.

## Known limitations

The window is a fixed 1920x1080 resolution, and the map is not
automatically fitted to it: with a very large map, points can be far
outside the visible area on launch. You may need to zoom out manually
(mouse wheel) after opening the file before the whole landscape becomes
visible.

Every rotation, translation or zoom event fully clears and redraws the
entire image, recomputing every point's projected position and every
line segment from scratch, with no partial redraw and no multithreading.
This is fine for the sample maps in `test_maps/`, but on very large,
high-resolution maps such as `landscape/dentsdumidi.fdf` (roughly 167,000
points), this full redraw becomes noticeably heavier, and interactions can
lose fluidity compared to smaller maps, even after optimization work on
the rotation and translation logic.

## AI usage

In accordance with 42's AI charter, it is stated that artificial
intelligence was used on this project for:

- Optimizing parts of the code, in particular to address a lack of
  fluidity during rotation and translation.
- Debugging parts of the code.
- Writing this README.

The project's logic (parsing, matrices, projection, rendering, event
handling) was designed and implemented by the author.
