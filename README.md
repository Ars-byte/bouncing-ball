# bouncing-ball

A ball bouncing off the window edges. Made with SDL2.

## Build

```bash
g++ -O2 -Wall -o bola bola.cpp $(sdl2-config --cflags --libs)
```

## Run

```bash
./bola
```

Press `ESC` or close the window to quit.

## If something is missing

On Void Linux, if SDL2 is not installed:

```bash
sudo xbps-install SDL2-devel
```

## Changing things

At the top of the file you have `ancho`, `alto`, `radio`, `x`, `y`, `vx` and `vy`.
Change them and build again. `vx` and `vy` are how fast it moves.
