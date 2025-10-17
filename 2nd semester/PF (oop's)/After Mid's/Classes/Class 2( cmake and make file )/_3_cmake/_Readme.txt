1. create file named CMakeLists.txt

2. add following contents in above file

cmake_minimum_required(VERSION 3.10)
project(Tutorial)
add_executable(Tutorial tutorial.cpp)

3. enter command in the top-level prject folder

cmake -B cmake_files    // one time or when CMakeLists.txt need to be updated
cmake --build cmake_files     // when source code files got updated

cmake --build cmake_files --config Debug
cmake --build cmake_files --config Release

4. run the exe

cmake_files\Debug\Tutorial.exe    // to run the program

5. to add other.cpp in the project, change a 
   line in CMakeLists.txt (in the folder named 
   cmake_files) as

add_executable(Tutorial tutorial.cpp other.cpp)

6. in case project top-level folder in changed
    delete the build folder and rebuild
    or just delete cmakecache.txt in build folder
    
7. misc
    --fresh to rebuild cache
    -A to specify plateform x86 or x64
