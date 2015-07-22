#!/bin/sh

echo "Compiling..."
echo " "
cd src/
g++ -c main.cpp Gun.cpp Player.cpp Starmap.cpp Menu.cpp -I/Documents/SFML/SFML_SRC/include
mv *.o ../linker/


cd ../linker/
echo "Linking..."
echo " "
g++ main.o Gun.o Player.o Starmap.o Menu.o -o sfml-app -L/Documents/SFML/SFML_SRC/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

mv sfml-app ../
echo "Executing..."
echo " "
cd ../
./sfml-app

if [ -e compile_SFML.sh~ ]
then 
    rm compile_SFML.sh~
fi
