# Hit the bucket

AKA prosta gra z udziałem statków 🚤

## Fabuła

Złe tornado pojawiło się na środku moza i mknie w stronę **TWOICH** Statków. Ale się nie martw! Twój **Statek–Obrońca** jest wstanie odbic tornado w stronę twojego przeciwnika!

## Wymagania

- **C++ 17** or grater
- **SFML 2.5** or grater
- **CMake 3.5** or grater

## Instalacja

1. W konsoli otworzyc folder z grą (np. `~/downloads/Hit-the-bucket/`)
2. Wpisac `cmake CMakeLists.txt & make` zeby zainstalowac
3. wpisac `./Hit-The-Bucket` zeby zagrac

## Załozenia

- [x] Versja c++: 17
- [x] jest cmake
- [x] są statki

## Odpalenie z konsoli

### cmake & make

```bash
cmake CMakeLists.txt & make & ./Hit-The-Bucket
```

### samemu

Komendy pokolei
~~~bash
g++ -c cz1.cpp
g++ cz1.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
./sfml-app
~~~

lub w jednej linii
~~~bash
g++ -c main.cpp && g++ main.o -o hit-the-bucket -lsfml-graphics -lsfml-window -lsfml-system && ./hit-the-bucket
~~~
