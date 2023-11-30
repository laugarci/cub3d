# cub3d

## Table of Contents

1. [Introduction](#introduction)
2. [Features](#features)
3. [Getting Started](#getting-started)
4. [Scene Description File](#scene-description-file)
5. [Controls](#controls)
6. [Bonus Features](#bonus-features)
7. [Pictures](#pictures)
8. [Video](#video)

## Introduction

Cub3D is a project that utilizes the miniLibX library for graphics and raycasting techniques to create a simple 3D environment. The program allows users to navigate through a maze, view different wall textures, and customize the floor and ceiling colors.

## Features

- Smooth window management
- Textured walls with varying textures based on the wall's orientation
- Customizable floor and ceiling colors
- Interactive controls for movement and rotation
- Scene description file parsing for configuration

## Getting Started

To get started with Cub3D, follow these steps:

1. Clone the repository: `git clone https://github.com/laugarci/cub3d.git`
2. Navigate to the project directory: `cd cub3d`
3. Build the project: `make`
4. Run the program with a scene description file: `./cub3D maps/NAME.cub`

## Scene Description File

The scene description file (.cub) is used to configure the maze and its elements. The file must follow specific rules, including:

- Map composition with only 6 possible characters: 0 for empty space, 1 for a wall, and N, S, E, or W for the player's start position and orientation.
- The map must be surrounded by walls.
- Elements can be separated by one or more empty lines.
- Elements can be set in any order, except for the map, which must be the last element.
- Each element's information is separated by one or more spaces.

## Controls

- Left and right arrow keys: Look left and right
- W, A, S, D keys: Move the point of view through the maze
- ESC key: Close the window and quit the program
- Red cross on the window's frame: Close the window and quit the program

## Bonus Features

The bonus part includes additional features that will be evaluated only if the mandatory part is perfect. These features include:

- Wall collisions
- A minimap system
- Animated sprite
- Rotate the point of view with the mouse

## Pictures

![IMG](https://github.com/laugarci/cub3d/blob/master/img/img1.png)

![IMG](https://github.com/laugarci/cub3d/blob/master/img/img2.png)

![IMG](https://github.com/laugarci/cub3d/blob/master/img/img3.png)

## Video

[![Video](https://img.youtube.com/vi/akXgDEZarMs/0.jpg)](https://www.youtube.com/watch?v=akXgDEZarMs)

<p align="center">
  <a href="https://www.youtube.com/watch?v=akXgDEZarMs">
    <img src="https://github.com/laugarci/cub3d/blob/master/img/img1.png" alt="ALT_TEXT">
  </a>
</p>

