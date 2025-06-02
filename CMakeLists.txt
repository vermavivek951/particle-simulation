cmake_minimum_required(VERSION 3.16)
project(particle_simulation)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Specify SDL2 include directory (adjust path if needed)
include_directories("C:/libraries/sdl2_64/include")

# Tell linker where to find SDL2 libs
link_directories("C:/libraries/sdl2_64/lib")

# Add executable
add_executable(main 
    main.cpp
    Particle.cpp
)

# Link the required libraries in the correct order
target_link_libraries(main
    mingw32
    SDL2main
    SDL2
)

# Pass the linker flag for Windows subsystem (GUI app, uses WinMain)
target_link_options(main PRIVATE "-Wl,-subsystem,windows")

# Optional: suppress warnings (like your -w)
target_compile_options(main PRIVATE -w)
