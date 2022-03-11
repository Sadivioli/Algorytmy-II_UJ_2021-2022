Proszę zaimplementować typ danych setSimple reprezentujący matematyczny zbiór oraz operacje które dla dwóch zbiorów, realizują:
    - sumę zbiorów A u B
    - część wspólną zbiorów A n B
    - różnicę zbiorów A - B
    - sprawdzanie identyczności zbiorów A == B
    dla elementu  i zbioru  realizują:
        - wstawianie x do zbioru A
        - usuwanie x ze zbioru A
        - sprawdzanie czy x należy do zbioru A

Proszę założyć, że istnieje skończona liczba  możliwych elementów. Można sobie na przykład wyobrazić, że wszystkie rozpatrywane przez nas zbiory są podzbiorami pewnego zbioru  zawierającego N elementów. Dzięki takiemu założeniu implementacja każdego z rozpytywanych zbiorów może być oparta na jednowymiarowej tablicy o rozmiarze N. Każdy index i = 1 ... N (lub i = 0 ... N-1) tej tablicy odpowiadałby jednemu z elementów Omega. Wartość przechowywana w tablicy pod indeksem  i (lub i-1) wskazuje na to czy dany element należy (np. true , 1) do rozpatrywanego zbioru czy nie (np. false , 0).


Państwa implementację proszę wykorzystać w programie, który bada złożoność obliczeniową poszczególnych operacji. Dla każdej z zaimplementowanych operacji program powinien produkować jeden plik, który może być uruchomiony z wykorzystaniem programu gnuplot. W wiadomości e-mail proszę opisać podejście wykorzystane do badania złożoności obliczeniowej i skonfrontować Państwa wyniki z wartościami teoretycznymi.