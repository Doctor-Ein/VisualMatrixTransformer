#!/bin/bash
echo "Auto Compile Run"

clear

g++ -o main Matrix.cpp io_lib.cpp main.cpp

./main