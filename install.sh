#!/usr/bin/env bash
echo "Beggin Portal installer..."
echo "
  _______         ̣_____               
 |  ___  |       / __  \_________  ___     _
 | |___| | ______||__| |__    __| / _ \   | |
 |  _____||  __  |     /  |  |   / /_\ \  | |
 | |      | |__| | |\ \   |  |  / /   \ \ | |___
 |_|      |______|_| \_\  |__| /_/     \_\|_____|
 
 "
echo "Installing cmake..."
sudo apt-get install cmake
echo "Installing gcc..."
sudo apt-get install gcc
echo "Updating..."
sudo apt-get update && sudo apt-get install build-essential
echo "Installing sdl2 libs..."
sudo apt-get install libsdl2-dev
sudo apt-get install libsdl2-image-dev
sudo apt-get install qt5-default
sudo apt-get install libsdl2-mixer-dev
echo "Installing qt5..."
sudo apt-get install qt5-default
echo "Installing ffmpeg..."
sudo apt-get install ffmpeg
echo "Decompressing pictures and sounds..."
sudo rm -rf resources
mkdir resources
unzip resources.zip
unzip qt.zip
unzip sounds.zip
unzip img.zip
sudo rm -rf qt.zip
sudo rm -rf sounds.zip
sudo rm -rf img.zip
sudo mv qt resources
sudo mv Music resources
sudo mv img resources 
echo "Descompresing box2d..."
unzip Box2D.zip
sudo mv Box2D src/server/modelo/3rdparty/Box2D-cmake
sudo rm -rf Box2D.zip
echo "Building executers..."
cmake CMakeLists.txt
make -j128
echo "Deleting unecesary folders..."
sudo rm -rf CMakeFiles
sudo rm -rf CMakeCache.txt
sudo rm -rf Makefile
sudo rm -rf cmake_install.cmake
sudo rm -rf resources.zip
echo "Installation finish. Good game!"
