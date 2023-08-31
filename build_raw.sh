#!/bin/sh

set -xe

mkdir -p ./build/
clang -Wall -Wextra -o ./build/main_raw ./main_raw.c ffmpeg_linux.c
