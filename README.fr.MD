﻿UniversalTest
-------------------
![UTestpython app](https://github.com/pigetArduino/utest/raw/master/doc/utestapp.png)
* Télécharger: http://utestapp.madnerd.org
* Code Arduino / Python : http://utest.madnerd.org
* Pilotes Arduino nano (CH340g) : http://nano.madnerd.org

Utest est une application en **python** pour contrôler des arduinos sous Windows.   
Cette application éteint/allume la led interne de l'arduino.   
Un **module python** s'occupe de gérer l'arduino.   
L'application peut être sauvegardés en tant qu'exécutable et ainsi être facilement utilisé par n'importe qui.

# Fonctionnalités
* Code accessible et simple à modifier 
* Détection automatique du port série
* Reconnexion automatique même si le port série change
* La détection et la communication série est géré automatiquement.
* Contrôler plusieurs arduino facilement

# Problèmes
L'application peut ne pas fonctionner sur Windows 7 faute de .dll manquantes
Normalement si votre ordinateur est à jour ceci ne devrait pas arriver
* Explications: http://stackoverflow.com/questions/34218333/pyinstaller-onefile-does-not-start-on-some-windows-7-machines
* Mis à jour nécessaire: https://support.microsoft.com/en-gb/kb/2999226

# Modifier le programme

## Prérquis
* Télécharger python 3 : https://www.python.org/downloads/
* Pendant l'installation, Cocher **Add Python 3.5 to PATH**   
![Python Path](https://github.com/pigetArduino/utest/raw/master/doc/python_install_path.jpg)

* Ouvrez une invite de commande (Touche Windows + cmd)
```
pip install pyserial
```

## Lancer l'application
* Ouvrer une invite de commande (Touche Windows + cmd)
* Aller dans le dossier du code source 
* Tapez:
```
python utest.py
```

# Compiler
Vous pouvez compiler l'application pour pouvoir facilement la partager à l'aide d'un fichier .exe   
Il nous faut installer **pyinstaller**

```
pip install pyinstaller
```
Puis vous pouvez utiliser le script compile.bat ou 
```
pyinstaller --onefile --noconsole utest.py 
```
Si vous voulez afficher la console de l'application
```
pyinstaller --onefile utest.py 
```

# Comment utiliser la bibliothèque python : USB.py
Afin de rendre l'utilisation de l'arduino le plus simple possible, toute la communication est géré par un module.   
Aller voir le code source (dans apps/utest et /utest) pour plus d'informations 

## Du coté du PC
Le module est constitué d'uniquement deux commandes pour le moment

Se connecter à un arduino
```
device_name = "CH340" #Nom de la puce série de l'arduino
device_type = "UTest" #Nom de l'arduino (définit dans le programme de celui-ci)
device_return_string = "OK" #Réponse de l'arduino à une commande correcte
device_baudrate = 115200 #Baudrate (Vitesse de transmission)
usb = USB.Device(device_name,device_type,device_return_string,device_baudrate)
```

Envoyer une chaine de caractères à un arduino
```
usb.write("ON")
```

## Du coté de l'arduino
Définition du nom
```
const String usb_name = "UTest";
```

Fonctionnement 
```
void loop() {
  serialManager(); //Fonctions qui gère la communication

  //If string received
     if (readString.length() > 0) {
      serialCheck(); //Vérification du type d'arduino

      //Insérez une liste d'actions ici
      if (readString == "ON"){
        digitalWrite(13,1);
      }
      if (readString == "OFF"){
        digitalWrite(13,0);
      }
      
    }

  //Nettoyage du buffer de communication
  readString = "";
}
```

# Licenses
Icône par jpapun
Creative Commons Attribution (by)
Lien : http://findicons.com/icon/158595/device_and_hardware

Logiciel par Rémi Sarrailh (madnerd.org)
License: MIT