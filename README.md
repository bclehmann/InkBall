# InkBall

This is an InkBall game that's still in development. It doesn't use any game engine, it's just built on top of SDL (which was a big mistake).

# Building

These are not full instructions. I will revisit this once the game is finished.

For now, all dependencies are statically linked. You can see the dependencies in [dependencies.md](https://github.com/bclehmann/InkBall/blob/master/dependencies.md).

The project is compiled with GCC using the C++ 17 standard, although at the time of writing any C++ 14 or C++ 11 compatible compiler will work (provided you update [CMakeLists.txt](https://github.com/bclehmann/InkBall/blob/master/CMakeLists.txt) accordingly).
