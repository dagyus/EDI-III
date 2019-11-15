#!/bin/bash
##Borro el directorio si ya existiera
if [ -d ./bin/ ];
	then rm -r ./bin/;
fi
##Creo los directorios para el Binario y las bibliotecas
mkdir ./bin/
mkdir ./bin/lib/
mkdir ./bin/lib/actions/
cp ./configuration.ini ./bin/

##compilo el Binario
g++ -Wall -std=c++11 -I./include/ main.cpp -ldl -o ./bin/main.bin

##compilo las bibliotecas
##g++ -shared -Wall -std=c++11 -fPIC -I./include/ ./src/RequestHandler.cpp -o ./bin/lib/RequestHandler.so
##g++ -shared -Wall -std=c++11 -fPIC -I./include/ ./src/ResponseHandler.cpp -o ./bin/lib/ResponseHandler.so
g++ -shared -Wall -std=c++11 -fPIC -I./include/ ./src/Application/Application.cpp -o ./bin/lib/Application.so
g++ -shared -Wall -std=c++11 -fPIC -I./include/ ./src/Actions/CreateNote/CreateNote.cpp -o ./bin/lib/actions/CreateNote.so
g++ -shared -Wall -std=c++11 -fPIC -I./include/ ./src/Actions/ReadNotes/ReadNotes.cpp -o ./bin/lib/actions/ReadNotes.so
g++ -shared -Wall -std=c++11 -fPIC -I./include/ ./src/Actions/DeleteNote/DeleteNote.cpp -o ./bin/lib/actions/DeleteNote.so
g++ -shared -Wall -std=c++11 -fPIC -I./include/ ./src/Actions/UpdateNote/UpdateNote.cpp -o ./bin/lib/actions/UpdateNote.so

##otorgo permisos de escritura a los ejecutables
chmod +x ./bin/main.bin
