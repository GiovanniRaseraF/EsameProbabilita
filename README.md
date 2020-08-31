## Esame di Probabilità (Secondo anno di informatica Udine)
Codice per risolvere gli esercizi dell'esame di probabilità del secondo anno di informatica a Udine

# Autore
- Giovanni Rasera

# Prerequisiti
- Linux(VM, WLS, Native)                                    .. Testato su Ubuntu WSL
- Compilatore C++(g++, clang, visualstudio, Cygwin, MinGW)  .. Testato con  g++ -std=c++17
- xdg-open installato
    Ubuntu
    ```bash
    sudo apt-get update -y
    sudo apt-get install -y xdg-utils
    ```
    [INSTALLAZIONE DI XDG-OPEN](https://zoomadmin.com/HowToInstall/UbuntuPackage/xdg-utils)
- Un browser compatibile con xdg-open                       .. Testato Chrome

# Come utilizzare
- Compilare il codice dell'esercizio che si desidera utilizzare
    ```bash
    g++ NOME_FILE.cpp -o NOME_FILE.out
    ```
    Credo che questo sia il modo più semplice
- Eseguire
    ```bash
    ./NOME_FILE.cpp
    ```
    Si presuppone l'utilizzo di Linux