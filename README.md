# Rendering Video in C with FFMpeg

https://github.com/tsoding/rendering-video-in-c-with-ffmpeg/assets/165283/3a050622-07cb-4558-b2cd-149f6c19a334

## Examples

### Raw Example

This example generates video by filling up memory with raw pixels. It uses [olive.c](https://github.com/tsoding/olive.c) library for that.

```console
$ ./build_raw.sh
$ ./build/main_raw
```

### Raylib Example

This example captures the output of [Raylib](https://github.com/raysan5/raylib) application and saves it as a video.

```console
$ ./build_raylib.sh
$ ./build/main_raylib
```
