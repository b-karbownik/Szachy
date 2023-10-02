Implementacja gry w szachy stworzona jako projekt zaliczeniowy jednego z przedmiotów na Uniwersytecie. Program napisany w języku C++ z użyciem biblioteki SDL2.

# Prezentacja
![chess2](https://github.com/b-karbownik/Szachy/assets/127301057/86d4f4f8-6859-4e6a-9797-27b68011aa05)
![chess1](https://github.com/b-karbownik/Szachy/assets/127301057/6968f76b-527c-46f1-9b20-3352917f0f65)
entacja

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
* https://github.com/llanillo/clion-cmake-sdl2-template
