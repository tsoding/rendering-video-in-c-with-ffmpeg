#!/bin/sh

set -xe

CFLAGS="-Wall -Wextra `pkg-config --cflags raylib`"
LIBS="`pkg-config --libs raylib` -lm"

mkdir -p ./build/
clang $CFLAGS -o ./build/main_raylib ./main_raylib.c ffmpeg_linux.c $LIBS
