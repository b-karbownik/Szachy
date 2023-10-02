Implementacja gry w szachy stworzona jako projekt zaliczeniowy jednego z przedmiotów na Uniwersytecie. Program napisany w języku C++ z użyciem biblioteki SDL2.

# Prezentacja
![chess1](https://github.com/b-karbownik/Szachy/assets/127301057/71ca88b1-e874-44c5-8b23-5882a08d1b86)
![chess2](https://github.com/b-karbownik/Szachy/assets/127301057/9c05391c-32e8-4fee-9d0b-be06ef5c77e7)

# TODO
 * Wyodrębnić klasę SDL_Handler
 * Dodanie en-passant
 * Zapis przebiegu partii w formacie PGN
 * Obsługa promocji (aktualnie brak wyboru, automatyczna zmiana na hetmana)
 * Optymalizacja metod isInCheck, isCheckMate (sprawdzana jest każda pozycja na planszy, czy nie jest pusta, czy kolor jest przeciwny. Docelowo przechowywanie figur w strukturze danych i iterowanie po nich)
 * Zrobić porządek ze wskaźnikami :)





# Reference

* [Using SDL2 with CMake](https://trenki2.github.io/blog/2017/06/02/using-sdl2-with-cmake/)
* [Using SDL2_image with CMake](https://trenki2.github.io/blog/2017/07/04/using-sdl2-image-with-cmake/)
