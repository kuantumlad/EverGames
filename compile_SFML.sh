#!/bin/sh

echo "Compiling..."
echo " "
g++ -c main.cpp Gun.cpp Player.cpp -I/Documents/SFML/SFML_SRC/include

echo "Linking..."
echo " "
g++ main.o Gun.o Player.o -o sfml-app -L/Documents/SFML/SFML_SRC/lib -lsfml-graphics -lsfml-window -lsfml-system

echo "Executing"
echo " " 
./sfml-app

if [ -e compile_SFML.sh~ ]
then 
    rm compile_SFML.sh~
fi
