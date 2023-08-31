#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>

#define OLIVEC_IMPLEMENTATION
#include "olive.c"

#include "ffmpeg.h"

#define WIDTH 800
#define HEIGHT 600
#define FPS 30
#define DURATION 10

uint32_t pixels[WIDTH*HEIGHT];

int main(void)
{
    FFMPEG *ffmpeg = ffmpeg_start_rendering(WIDTH, HEIGHT, FPS);

    Olivec_Canvas oc = olivec_canvas(pixels, WIDTH, HEIGHT, WIDTH);

    float x = WIDTH/2;
    float y = HEIGHT/2;
    float r = HEIGHT/8;
    float dx = 200;
    float dy = 200;
    float dt = 1.0f/FPS;
    for (size_t i = 0; i < FPS*DURATION; ++i) {
        float nx = x + dx*dt;
        if (0 < nx - r && nx + r < WIDTH) {
            x = nx;
        } else {
            dx = -dx;
        }

        float ny = y + dy*dt;
        if (0 < ny - r && ny + r < HEIGHT) {
            y = ny;
        } else {
            dy = -dy;
        }

        olivec_fill(oc, 0xFF181818);
        olivec_circle(oc, x, y, r, 0xFF0000FF);
        ffmpeg_send_frame(ffmpeg, pixels, WIDTH, HEIGHT);
    }

    ffmpeg_end_rendering(ffmpeg);

    printf("Done rendering the video!\n");

    return 0;
}
