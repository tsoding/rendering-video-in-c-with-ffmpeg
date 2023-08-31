#ifndef FFMPEG_H_
#define FFMPEG_H_

#include <stddef.h>

int ffmpeg_start_rendering(size_t width, size_t height, size_t fps);
void ffmpeg_send_frame(int pipe, void *data, size_t width, size_t height);
void ffmpeg_send_frame_flipped(int pipe, void *data, size_t width, size_t height);
void ffmpeg_end_rendering(int pipe);

#endif // FFMPEG_H_