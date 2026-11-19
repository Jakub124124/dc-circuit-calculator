# Kalkulator obwodów prądu stałego

Program w C++17, który liczy rezystancję zastępczą obwodu
złożonego z rezystorów połączonych szeregowo i równolegle.

## Funkcje (stan na v0.1.0)
- rezystor, połączenie szeregowe i równoległe (dowolnie zagnieżdżane)
- obliczanie rezystancji zastępczej
- własne wyjątki dla błędnych danych

## Platforma
Windows 64-bit

## Budowanie i uruchomienie
    cmake -B build
    cmake --build build --config Release
    build\Release\kalkulator.exe

## Testy
    ctest --test-dir build -C Release --output-on-failure




## Rejestr użycia LLM
commit:
- Dodaj testy polaczenia szeregowego
- Dodanie pipeline wydania dla Windows
- Dodaj testy polaczenia rownoleglego i zaktualizuj CMake
- Dodano sprawdzenie rezystancji oraz identyfikatora
