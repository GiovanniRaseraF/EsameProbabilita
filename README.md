## Esame di Probabilità (Secondo anno di informatica Udine)
- Codice per risolvere gli esercizi dell'esame di probabilità del secondo anno di informatica a Udine.
- La risoluzione degli esercizi è basata sul PDF creato da [Magoga Francesco](), Versione 1.6.
- Consiglio di leggere attentamente i passaggi che segue Francesco siccome le spiegazioni sono veramente molto 
dettagliate.
- I miei programmi devono servire solamente a verificare di aver fatto i calcoli giusti.
- Non mi prendo nessuna responsabilità se venissero utilizzati per copiare.

# Importante
- Mi scuso per gli errori di ortografia e di logica che molto probabilmente avrò commesso e per l'implemetazione, spesso sbrigativa, che ho dato.
- Spero che questo progetto non sia fine a se stesso, ma sia un modo per far piacere questa materia anche a noi informatici a cui non interessa proprio nulla dell'argomento.
- Lascio a voi l'implemetazione/miglioramento/ottimizzazione in altri linguaggi. (SE LO FATE IN SCHEME VI OFFRO UN CAFFE')

# Autore
- Giovanni Rasera

# Grazie
- Magoga Francesco
- https://github.com/d99kris/rapidcsv       Miglior libreria per il parsing dei csv
- https://github.com/d99kris
- Cremonini Cesare

# Prerequisiti
- Linux(VM, WLS, Native)                                    .. Testato su Ubuntu WSL
- Compilatore C++(g++, clang, visualstudio, Cygwin, MinGW)  .. Testato con  g++ -std=c++17
- xdg-open installato
    ```bash
    #Ubuntu
    sudo apt-get update -y
    sudo apt-get install -y xdg-utils
    ```
    ```bash
    #MacOS 
    sudo nano .bash_profile
    #L'editor di nano verrà aperto e potrete aggiungere la riga:
    alias xdg-open="open" 
    #Uscire con (control x) -- (^X) e premere y per salvare
    ```
    [INSTALLAZIONE DI XDG-OPEN](https://zoomadmin.com/HowToInstall/UbuntuPackage/xdg-utils)
- Un browser compatibile con xdg-open                       .. Testato Chrome (Non fidati della versione di MacOS che da problemi)

# Come utilizzare
- Compilare il codice dell'esercizio che si desidera utilizzare
    ```bash
    g++ NOME_FILE.cpp -o NOME_FILE.out -std=c++17
    ```
    Credo che questo sia il modo più semplice
- Eseguire
    ```bash
    ./NOME_FILE.out
    ```
    Si presuppone l'utilizzo di Linux o MacOS
