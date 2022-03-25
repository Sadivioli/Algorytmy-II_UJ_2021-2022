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

Instrukcja uruchomienia programu:
    make run

Gnuplot commands:
 (Zakładamy że jesteśmy w tym samym folderze, w którym znakdują się pliki "ins.txt", "rm.txt")

 f(x) = x**2 
 set yrange [0:f(2)]
 set ytics ("0" f(0), "1" f(1)) 
 set xrange [0:490000] 

 plot "ins.txt" title "Number of operations"
 plot "ins.txt" title "Number of operations"

Podejście do zagadnienia obliczania złożoniści obliczeniowej opracji na zbiorach.
    W funcjach insert oraz remove tworzona jest zmienna counter, która reprezentuje ilość wykonanych operacji. Dodaje +1 do zmiennej counter kiedy element zostaje dodany/usnięty ze zbioru. Funkcje insert i remove zwracają tę wartość, która wraz z rozmiarem zbioru w danej iteracji zostaje zapisana do plików odpowidnio "ins.txt" i "rm.txt". Na podstawie tych plików możemy zobaczyć złożoność czasową tych operacji. Złożoność wynosi O(n), co odpowiada wartości teoretycznej.