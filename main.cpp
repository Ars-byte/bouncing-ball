#include <SDL2/SDL.h>

#include <cmath>

int ancho = 800;
int alto = 600;
int radio = 20;

int x = 400;
int y = 300;
int vx = 6;
int vy = 4;

void dibujarPelota(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    for (int fila = -radio; fila <= radio; fila++) {
        int medio = (int)sqrt(radio * radio - fila * fila);
        SDL_RenderDrawLine(renderer, x - medio, y + fila, x + medio, y + fila);
    }
}

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        return 1;
    }

    SDL_Window* ventana = SDL_CreateWindow("Pelota", SDL_WINDOWPOS_CENTERED,
                                           SDL_WINDOWPOS_CENTERED, ancho, alto,
                                           SDL_WINDOW_SHOWN);

    SDL_Renderer* renderer = SDL_CreateRenderer(ventana, -1, SDL_RENDERER_ACCELERATED);

    bool abierto = true;

    while (abierto) {
        SDL_Event evento;
        while (SDL_PollEvent(&evento)) {
            if (evento.type == SDL_QUIT) {
                abierto = false;
            }
            if (evento.type == SDL_KEYDOWN && evento.key.keysym.sym == SDLK_ESCAPE) {
                abierto = false;
            }
        }

        x = x + vx;
        y = y + vy;

        if (x < radio) {
            x = radio;
            vx = -vx;
        }
        if (x > ancho - radio) {
            x = ancho - radio;
            vx = -vx;
        }
        if (y < radio) {
            y = radio;
            vy = -vy;
        }
        if (y > alto - radio) {
            y = alto - radio;
            vy = -vy;
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        dibujarPelota(renderer);

        SDL_RenderPresent(renderer);
        SDL_Delay(1000 / 60);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(ventana);
    SDL_Quit();

    return 0;
}
