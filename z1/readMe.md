Punkt C:
    Korzystając z wyników zadań A oraz B proszę się zastanowić która implementacja jest lepsza i w jakiej sytuacji. Swoją odpowiedź proszę przesłać za pośrednictwem e-mail. 
    Uwaga: to zadanie może być zaliczone pod warunkiem prawidłowego wykonania A oraz B.

    Przechowywanie danych w tablicy (SetSimple), dobrze sprawdza się w stosunkowo małych lub gęstych zbiorach. Złożoność obliczeniowa jest bardzo mała, dlatego że wszystkie podstawowe operacje są rzędu O(1), kosztem i największą wadą jest ilość zajmowanej pamięci. Wielkość zbioru musi być z góry znana.

    Lista wiązana (SetLinked) sprawdza się najlepiej, kiedy chcemy oszczędzać pamięć. Struktura bez względu na postać zbioru jest gęsto upakowana. Niestety kosztem niskiego zużycia pamięci jest większa złożoność obliczeniowa. Wielkość zbioru nie musi być z góry określona.


UWAGI:
    1. Dla każdej implementacji typu danych oraz dla każdej zaimplementowanej operacji proszę dodatkowo:
        - zamieścić w Państwa programie test sprawdzający czy operacje są zaimplementowane prawidłowo
        - aby ułatwic Państwu pracę możemy się umówić, że w teście będzie sprawdzana niewielka ilość przypadków - na tyle mała aby można było je wypisać na ekranie komputera i przeanalizować ręcznie

    2.Badając złożoność obliczeniową operacji, proszę się zastanowić jak powina wyglądać zależność t(n) czasu wykonania problemu (t) od rozmiaru problemu (n) i nanieść tą hipotezę na odpowiedni wykres.

    3.Kilka przykładów, w których badana jest złożonosć operacji dodawania elementu do zbioru
        - wykres oraz skrypt gnuplot i dane do skryptu dla implementacji wykorzystującej tablicę, której elementami są wartości logiczne
        - dwa wykresy wykres 1, wykres 2 oraz dwa skrypty gnuplot skrypt 1, skrypt 2 dla posortowanej listy łączonej. Dodatkowo dane do skrypt 1 oraz skrypt 2.
            dlaczego te wyniki tak dramatycznie się różnią? Proszę dokładnie przeczytać opis wykresów
        - proszę się zastanowić jak ma się dopasowanie do otrzymanych wyników odpowiedniej krzywej do złożonoći obliczeniowej

    4.Sprawdzenie złożoności obliczeniowej dla każdej z operacji może być trochę pracochłonne. Kryteria zaliczenia zadań są złagodzone: wystarczy jeden wykres dla wybranej operacji. Ale proszę go jednak zrobić porządnie 

    5.W większości zadań nie jest określony typ danych elementów zbioru. Można korzystać na przykład z liczb całkowitych. Nie powinno mieć to większego znaczenia jeżeli pewne warunki są spełnione. Jakie to warunki?
    Wskazówka: ==, <, >