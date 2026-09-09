*This project has been created as part of the 42 curriculum by lgranger.*

# FdF

## Description

FdF (fil de fer) is a 42 graphics project. The goal is to read a height
map from a `.fdf` file and display it as a 3D wireframe.

Each cell of the file is a point in a regular grid. The integer is the
altitude (`z`). An optional hex color can be attached to a point. The
program projects those points (isometric or perspective), connects
neighbours with lines, and draws the result in a MinilibX window.

This implementation also rotates the mesh with 3x3 matrices, interpolates
colors along edges, and uses a depth buffer so closer pixels hide
farther ones.

## Instructions

### Requirements

- Linux
- `cc` and `make`
- X11 libraries: `libx11-dev`, `libxext-dev`, `zlib1g-dev`

`libft` and `minilibx-linux` are already in the repository.

### Compilation

```sh
make
```

| Rule          | Effect                               |
|---------------|--------------------------------------|
| `make`        | Build `libft`, MinilibX, and `./fdf` |
| `make clean`  | Remove object files (`objs/`)        |
| `make fclean` | `clean` and remove `./fdf`           |
| `make re`     | `fclean` then rebuild                |

The project compiles with `-Wall -Wextra -Werror`.

### Execution

```sh
./fdf <map.fdf>
```

Exactly one argument is required. The file must exist and end with
`.fdf`.

```sh
./fdf landscape/42.fdf
./fdf landscape/dentsdumidi.fdf
./fdf test_maps/elem-col.fdf
```

### Controls

| Input      | Action                    |
|------------|---------------------------|
| Arrows     | Rotate                    |
| W A S D    | Translate                 |
| Scroll     | Zoom (towards the cursor) |
| 1          | Isometric projection      |
| 2          | Perspective projection    |
| R          | Reset view                |
| ESC        | Close                     |

Window size: 1920 x 1080.

### Map format

Each line is a row of the grid. Values are integers separated by spaces.
A color may follow a height as `,0x` plus hexadecimal digits:

```
0  0  0  0
0 10 20,0xFF0000 10
0  0  0  0
```

The map must be rectangular. Empty files, empty lines, and unauthorized
characters are rejected. Sample maps are in `landscape/` and
`test_maps/`.

### MinilibX limits on huge maps

MinilibX is a thin X11 wrapper with no GPU path. Every pixel is written
on the CPU into an image buffer, then copied to the window with
`mlx_put_image_to_window`.

FdF redraws the whole scene on each input event. A frame clears a
1920 x 1080 image and depth buffer, projects every vertex, runs DDA on
every grid edge, and writes pixels one by one.

That cost follows the number of edges, not how small the drawing looks.
`landscape/42.fdf` (13 x 19) is a few hundred lines per frame and stays
smooth. `landscape/dentsdumidi.fdf` (480 x 350) is about 168,000
vertices and 335,000 edges. At default zoom many neighbours already
share a pixel, but MinilibX still walks every edge. Holding an arrow
key repeats that work on every key repeat.

This is a limit of software rasterisation through MinilibX, not a
parsing bug. Small and medium maps are interactive. Very large maps
(`dentsdumidi`, `valley`, `julia`, `elem-fract`) remain usable, but
rotation will not feel like a GPU renderer. Zooming in makes huge maps
heavier, because each edge covers more pixels.

With the functions allowed at 42 (MinilibX, no OpenGL), there is no
way to draw hundreds of thousands of depth-tested lines at a stable
high frame rate. The renderer is meant for wireframe maps the CPU can
walk every frame.

## Resources

### Topic references

- [MinilibX (Linux)](https://github.com/42Paris/minilibx-linux) —
  window, image buffer, hooks, and pixel drawing used by this project
- [Digital differential analyzer (graphics)](https://en.wikipedia.org/wiki/Digital_differential_analyzer_(graphics_algorithm)) —
  line rasterisation (`dda_line`)
- [Isometric projection](https://en.wikipedia.org/wiki/Isometric_projection) —
  default 30-degree view
- [3D projection](https://en.wikipedia.org/wiki/3D_projection) —
  perspective mode
- [Rotation matrix](https://en.wikipedia.org/wiki/Rotation_matrix) —
  X / Z rotations composed into one 3x3 matrix
- [Z-buffering](https://en.wikipedia.org/wiki/Z-buffering) —
  per-pixel depth test so closer fragments hide farther ones
- [Bresenham's line algorithm](https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm) —
  classic alternative to DDA for integer lines

### AI usage

An AI coding assistant (Cursor) was used during cleanup, not to write
the project from scratch.

- **Parser** — locate why valid colored maps such as
  `landscape/42.fdf` were rejected as unauthorized characters (a
  tautology in `check_line` when a comma was present).
- **Makefile** — make `clean` / `fclean` remove `objs/` and `./fdf`.
- **Rendering** — identify lag from clearing the 1920 x 1080 image and
  depth buffer twice per keypress, and from calling `cos` / `sin` on
  every vertex; those paths were then simplified in the source.
- **Performance discussion** — explain why MinilibX cannot keep huge
  maps as smooth as small ones (CPU rasterisation, one full redraw per
  event, hundreds of thousands of DDA edges).
- **README** — draft this file and reshape it to the 42 README rules
  (italic curriculum line, Description, Instructions, Resources, AI
  disclosure).

Core design (grid parsing, projections, matrix rotation, DDA, colors,
hooks) is the student's. AI output was reviewed and adapted before it
went into the repository.
