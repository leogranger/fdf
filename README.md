# FdF

42 graphics project: a wireframe renderer for 3D height maps.

The program reads a `.fdf` file, projects the grid in isometric or
perspective view, and draws it with [MinilibX](https://github.com/42Paris/minilibx-linux).

## Requirements

- Linux
- `cc`, `make`
- X11 development libraries (`libx11-dev`, `libxext-dev`, `zlib1g-dev`)

This project uses the local `libft` and `minilibx-linux` copies in the
repository. It is written to compile with `-Wall -Wextra -Werror`.

## Compilation

```sh
make
```

| Rule     | Effect                                      |
|----------|---------------------------------------------|
| `make`   | Build `libft`, MinilibX, and `./fdf`        |
| `make clean`  | Remove object files (`objs/`)          |
| `make fclean` | `clean` + remove `./fdf`               |
| `make re`     | `fclean` then `all`                    |

## Usage

```sh
./fdf <map.fdf>
```

Examples:

```sh
./fdf landscape/42.fdf
./fdf landscape/dentsdumidi.fdf
./fdf test_maps/elem-col.fdf
```

The program takes exactly one argument. The file must exist and end
with `.fdf`.

## Map format

Each line is a row of the grid. Values are integers separated by spaces.
An optional color can follow a height with `,0x` and hexadecimal digits:

```
0  0  0  0
0 10 20,0xFF0000 10
0  0  0  0
```

The map must be rectangular: every row has the same number of points.
Empty files, empty lines, and characters that are not part of a height
or a hex color are rejected.

Sample maps live in `landscape/` and `test_maps/`.

## Controls

| Key        | Action                    |
|------------|---------------------------|
| Arrow keys | Rotate                    |
| W A S D    | Translate                 |
| Scroll     | Zoom (towards the cursor) |
| 1          | Isometric projection      |
| 2          | Perspective projection    |
| R          | Reset view                |
| ESC        | Close                     |

The window is 1920 x 1080.

## Features

- Isometric and perspective projections
- Rotation with 3x3 matrices, applied from each point's original
  coordinates
- Color parsing (`z,0xRRGGBB`) and interpolation along edges
- Depth buffer so closer pixels hide farther ones
- Automatic Z scaling from the map's min / max height

## MinilibX and large maps

MinilibX is a thin X11 wrapper. It has no GPU path: every pixel is
written on the CPU, into an image buffer, then copied to the window
with `mlx_put_image_to_window`.

FdF redraws the whole scene on each input event (key, scroll). For
every frame it:

1. Clears a 1920 x 1080 image and depth buffer
2. Projects every vertex
3. Runs DDA on every grid edge
4. Writes pixels one by one, with a depth test

That cost grows with the number of edges, not with how the map looks
on screen. A small map such as `landscape/42.fdf` (13 x 19) is a few
hundred lines per frame and stays smooth.

A map such as `landscape/dentsdumidi.fdf` is 480 x 350:

- about 168,000 vertices
- about 335,000 edges
- each edge is a DDA loop and several `put_pixel` calls

At default zoom, neighbouring points often land on the same pixel, so
most of that work is redundant. MinilibX still has to do it. Holding
an arrow key repeats the full redraw many times per second. This is a
limit of software rasterisation through MinilibX, not a parsing bug.

Practical expectation:

- Small and medium maps: interactive
- Very large maps (`dentsdumidi`, `valley`, `julia`, `elem-fract`):
  usable, but rotation will not feel like a GPU renderer

Zooming in on a huge map makes it heavier still, because each edge
covers more pixels.

There is no supported way in this stack (42 allowed functions,
MinilibX, no OpenGL) to draw hundreds of thousands of lines at a
stable high frame rate while keeping a full depth buffer. The
renderer is built for wireframe maps of a size the CPU can walk every
frame.

## Project layout

```
include/     headers
srcs/        renderer, parser, events
libft/       libc-style helpers, printf, get_next_line
minilibx-linux/
landscape/   maps
test_maps/   maps
```

## Author

lgranger @ 42 Lausanne
