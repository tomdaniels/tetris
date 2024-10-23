g++ ./src/*.cpp -o tetris -L/raylib/build/raylib -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -Wl,-rpath=/raylib/build/raylib

./tetris
