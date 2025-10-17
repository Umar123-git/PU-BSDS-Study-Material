cmake -S . -B build -A x64
cmake --build build

cmake --build build --config Release

in case project top-level folder in changed
    delete the build folder and rebuild
    or just delete cmakecache.txt in build folder
    better to use --fresh