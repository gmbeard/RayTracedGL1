# RTGL1

***Work in progress***

RTGL1 is a library that simplifies the process of porting applications with fixed-function pipeline to *real-time path tracing*

It's achievable with hardware accelerated ray tracing, low sample per pixel count and utilizing denoising algorithms to improve the image quality by aggressively reusing spatio-temporal data.

## Pre-requisites 
- `$ git clone -b feature/cmake-export --depth=1 https://github.com/gmbeard/DLSS.git`

## Building
- `$ mkdir build && cd build`
- `$ cmake ..`
- `$ cmake --build .`

## Installing
- `$ cmake -DCMAKE_INSTALL_PREFIX=<Install Dir.> ..` (Only necessary if you wish to install RTGL1 to a location other than the default)
- `$ cmake --build . --target install`

## Screenshots

Test Scene

![Screenshot 00](/Doc/Screenshots/Screenshot_00.png)
![Screenshot 01](/Doc/Screenshots/Screenshot_01.png)

Serious Sam TFE: Ray Traced

![Screenshot 02](/Doc/Screenshots/Screenshot_02.png)
![Screenshot 03](/Doc/Screenshots/Screenshot_03.png)
![Screenshot 04](/Doc/Screenshots/Screenshot_04.png)
![Screenshot 04](/Doc/Screenshots/Screenshot_05.png)
