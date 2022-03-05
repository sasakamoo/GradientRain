# **Gradient Rain!!! Inspired by Daniel Shiffman - a legend**
**[Website for more info!](https://thecodingtrain.com/CodingChallenges/004-purplerain.html)**

# **GRAPHICS LIBRARY BY javidx9 - another legend**
**[The C++ PixelGameEngine!](https://github.com/OneLoneCoder/olcPixelGameEngine)**

## ***Use CMake to use your preferred build system(Visual Studio, ninja, mingw, etc).***

## ***Using mingw on windows with CMake!***
In order to use mingw with CMake you need to have both installed and their binaries pointed to in the PATH.
- [CMake](https://cmake.org/)
- [MinGW](https://www.msys2.org/)

To generate your build system, open any terminal and in the same directory as the CMakeLists.txt file type, 
`cmake -G "MinGW Makefiles"` to have CMake automatically generate makefiles for you.
Once done, you can simply type `mingw32-make.exe` to compile your executable. 

If `mingw32-make.exe` gives an error after *adding* a file, type `mingw32-make.exe rebuild_cache` in
your terminal to avoid using CMake for that as well.

