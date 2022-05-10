<div id="top"></div>

<br />
<div align="center">
  <a href="https://github.com/AlganOngun/Monke-Engine">
    <img src="https://i1.sndcdn.com/avatars-ylM4tanwBXJZhjWb-X76mWw-t240x240.jpg" alt="Logo" width="175" height="175">
  </a>

  <h3 align="center">Monke Engine</h3>

  <p align="center">
    An Open Source, Cross-Platform Game Engine To Make Your Dream Game
  </p>
    
  [![Contributors][contributors-shield]][contributors-url]
  [![Forks][forks-shield]][forks-url]
  [![Stargazers][stars-shield]][stars-url]
  [![Issues][issues-shield]][issues-url]
  [![MIT License][license-shield]][license-url]
  
  <p align="center">
    <br />
    ·
    <a href="https://github.com/AlganOngun/Monke-Engine/issues">Report Bug</a>
    ·
    <a href="https://github.com/AlganOngun/Monke-Engine/issues">Request Feature</a>
  </p>
</div>

<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
        <li><a href="#Example">Example</a></li>
      </ul>
    </li>
    <li><a href="#contributing">Contributing</a></li>
  </ol>
</details>

## About The Project

This Game Engine is currently in a really early stage and it is under heavy development.

### Built With

* [Spdlog](https://github.com/gabime/spdlog)
* [GLFW](https://www.glfw.org)
* [GLAD](https://glad.dav1d.de)

## Getting Started

This is a short tutorial on how to build and run the project

### Prerequisites

* cmake
  ```sh
  sudo apt install cmake
  ```
* spdlog
* glfw

### Installation

1. Install the prerequisites
2. Clone the repo
   ```sh
   git clone https://github.com/AlganOngun/Monke-Engine.git
   ```
3. Create a build directory and get inside of it
   ```sh
   mkdir build
   cd build
   ```
4. Build
   ```sh
   cmake ..
   cmake --build .
   ```
5. Copy all header files to your include folder
6. Move libEngine.so to your project directory
   ```sh
   cp src/libEngine.so some/dir/myproject/
   ```
7. Link libEngine.so and required libraries
   ```cmake
   target_link_libraries(project libEngine.so libspdlog.a glfw3)
   ```
8. Run your project

### Example

After your project compiles successfully, now you can start using the engine. To get started please follow the steps below:

1. Include The Engine Header
   ```cpp
   #include <MonkeEngine/Engine.h>
   ```
2. Now create a class which derives from Engine::Application
   ```cpp
   class MyApplication : public Engine::Application
   {
      MyApplication()
      {
      }
      
      ~MyApplication()
      {
      }
   }
   ```
3. Create a CreateApplication function in your main source file
   ```cpp
   Engine::Application* Engine::CreateApplication()
   {
      return new MyApplication();
   }
   ```
4. Now Monke Engine Will Handle Starting your application for you so you can now delete your main function
5. Congratulations you're set you can type in code inside of your MyApplication constructor or destructor and it will run
6. Try running the following code snippet inside of your ```MyApplication()```
   ```cpp
   Engine::Logger::Log("Hello, MonkeEngine");
   ```
7. If you setted up everything correctly you should see ```Hello, MonkeEngine``` in your console

## Contributing

Currently this project is in a early development stage. If you want to contribute please contact me through this email address: "alganunlu1896@gmail.com"

[contributors-shield]: https://img.shields.io/github/contributors/AlganOngun/Monke-Engine?style=flat-square
[contributors-url]: https://github.com/AlganOngun/Monke-Engine/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/AlganOngun/Monke-Engine?style=flat-square
[forks-url]: https://github.com/AlganOngun/Monke-Engine/network/members
[stars-shield]: https://img.shields.io/github/stars/AlganOngun/Monke-Engine?style=flat-square
[stars-url]: https://github.com/AlganOngun/Monke-Engine/stargazers
[issues-shield]: https://img.shields.io/github/issues/AlganOngun/Monke-Engine?style=flat-square
[issues-url]: https://github.com/AlganOngun/Monke-Engine/issues
[license-shield]: https://img.shields.io/github/license/AlganOngun/Monke-Engine?style=flat-square
[license-url]: https://github.com/AlganOngun/Monke-Engine/blob/master/LICENSE.txt
