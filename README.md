# Particle Simulation in C++ with SDL2

A real-time particle simulation built using **C++**, **SDL2**, and **CMake**. Particles are influenced by physics-based forces like gravity and wind, interact with mouse input, and bounce off window edges with fading effects.

## Features

- Particle motion using Euler integration
- Gravity, wind, and user interaction forces
- Collision with window borders
- Color transitions and alpha fading
- Written with modular C++ and modern CMake

## Demo

![demo](./demo.gif)


## Dependencies

- [SDL2](https://www.libsdl.org/)
- CMake ≥ 3.10
- MinGW (or any C++17-compatible compiler)


## Build Instructions

```bash
# Clone the repo
git clone https://github.com/vermavivek951/particle-simulation.git
cd particle-simulation

# Create and enter build directory
mkdir build
cd build

# Run CMake and build
cmake .. -G "MinGW Makefiles"
cmake --build .

# Run the simulation
./main.exe
```

## Control Instructions
 * Right Click to spawn single circle shape;
 * Left Click to spawn multiple particle shape