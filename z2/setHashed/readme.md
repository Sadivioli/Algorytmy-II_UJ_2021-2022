## Zadanie B

Proszę zaimplementować typ danych setHashed reprezentujący matematyczny zbiór oraz operacje które dla dwóch zbiorów `A`, `B` realizują:

- sumę zbiorów `A ∪ B`
- część wspólną zbiorów `A ∩ B`
- różnicę zbiorów `A - B`
- sprawdzanie identyczności zbiorów `A ≡ B`

oraz dla elementu `x` i zbioru `A`

realizują:

- wstawianie `x` do zbioru `A`
- usuwanie `x` ze zbioru `A`
- sprawdzanie czy `x ∈ A`

Tym razem proszę wykrzystać haszowanie otwarte. Państwa implementację proszę wykorzystać w programie, który bada złożoność obliczeniową poszczególnych operacji. Dla każdej z zaimplementowanych operacji program powinien produkować jeden plik, który może być uruchomiony z wykorzystaniem programu gnuplot. W wiadomości e-mail proszę opisać podejście wykorzystane do badania złożoności obliczeniowej i skonfrontować Państwa wyniki z wartościami teoretycznymi.