# Tetris

Tetris clone written in C++ with raylib.
To avoid submodules build raylib with cmake directly in the source folder:

```
git clone https://github.com/raysan5/raylib.git raylib
cd raylib
mkdir build && cd build
cmake -DBUILD_SHARED_LIBS=ON ..
make
sudo make install
```
