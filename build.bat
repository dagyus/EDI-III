::Creo los directorios para el binario y las bibliotecas
MD .\web\backend\
MD .\web\backend\lib\
MD .\web\backend\lib\actions\

::Creo los directorios para el Binario y las bibliotecas
mkdir ./bin/
mkdir ./bin/lib/

::compilo el Binario
g++ -Wall -std=c++11 -I./include/ main.cpp -o ./bin/main.bin

::compilo las bibliotecas
g++ -shared -Wall -std=c++11 -I./include/ ./src/Test/Test.cpp -o ./bin/lib/Test.so
