# Hit the bucket

AKA prosta sgra w statki 🚤

## Załoenia

- Versja c++: 17
- Robi cmake
- Tworzy Testy jednostkowe żeby było łatwiej (można wtedy testować też przez githuba)
- uywac qt? (qtcreator)
- Firebase
- 
## Odpalenie

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
