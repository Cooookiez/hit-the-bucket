# Hit the bucket

AKA prosta gra z udziałem statków 🚤

## Fabuła

Złe tornado pojawiło się na środku moza i mknie w stronę **TWOICH** Statków. Ale się nie martw! Twój **Statek–Obrońca** jest wstanie odbic tornado w stronę twojego przeciwnika!

## Instalacja

1. Skopjować pliki z folderu `assets/` do `/hit-the-bucket/assets/` (w folderze domowym)
2. Mieć zainstalowanego cmake (`sudo apt install cmake` dla ubuntu, lub `sudo brew install cmake` dla OSX)
3. odpali **cmake** (`cmake CMakeLists.txt`) będąc w folderze zawierającym ten plik
4. odpalic **make** (poprostu `make` będąc całyczas w tym samym folderze)
5. pojawi się plik wykonywalny **Hit-The-Bucket** który mona odpali i będzie działała gra 👍

## Załozenia

- [x] Versja c++: 17
- [x] jest cmake
- [x] są statki

## Odpalenie z konsoli (bez cmake i juz nie działa)

Komendy pokoleji
~~~bash
g++ -c cz1.cpp
g++ cz1.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
./sfml-app
~~~

lub w jednej lini
~~~bash
g++ -c main.cpp && g++ main.o -o hit-the-bucket -lsfml-graphics -lsfml-window -lsfml-system && ./hit-the-bucket
~~~
