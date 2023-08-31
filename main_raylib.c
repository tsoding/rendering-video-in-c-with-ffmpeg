#include <stdio.h>
#include <raylib.h>

#include "ffmpeg.h"

#define WIDTH 800
#define HEIGHT 600
#define FPS 30
#define DURATION 10

int main(void)
{
    int ffmpeg = ffmpeg_start_rendering(WIDTH, HEIGHT, FPS);

    InitWindow(WIDTH, HEIGHT, "FFmpeg");
    SetTargetFPS(FPS);
    RenderTexture2D screen = LoadRenderTexture(WIDTH, HEIGHT);

    float x = WIDTH/2;
    float y = HEIGHT/2;
    float r = HEIGHT/8;
    float dx = 200;
    float dy = 200;
    float dt = 1.0f/FPS;
    for (size_t i = 0; i < FPS*DURATION && !WindowShouldClose(); ++i) {
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

        BeginDrawing();
            BeginTextureMode(screen);
                ClearBackground(GetColor(0x181818FF));
                DrawCircle(x, y, r, GetColor(0xFF0000FF));
            EndTextureMode();

            ClearBackground(GetColor(0x181818FF));
            DrawTexture(screen.texture, 0, 0, WHITE);
        EndDrawing();

        Image image = LoadImageFromTexture(screen.texture);
        ffmpeg_send_frame_flipped(ffmpeg, image.data, WIDTH, HEIGHT);
        UnloadImage(image);
    }

    UnloadRenderTexture(screen);
    CloseWindow();

    ffmpeg_end_rendering(ffmpeg);

    printf("Done rendering the video!\n");

    return 0;
}
