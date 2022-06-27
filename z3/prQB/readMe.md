

## Zadanie B

Proszę zaimplementować kolejkę priorytetową `priorityQueueBinary` z operacjami jak w `zadaniu A` ale tym razem proszę oprzeć swoją implementacje o kopiec binarny. Proszę zbadać złożoność obliczeniową operacji usuwania z kolejki elementu o najmniejszym "priorytecie" (wykres, wartość teoretyczna, dyskusja) oraz porównać wyniki z `zadaniem A`.

### UWAGI

- W większości zadań nie jest określony typ danych elementów zbioru. Można korzystać na przykład z liczb całkowitych. Nie powinno mieć to większego znaczenia jeżeli pewne warunki są spełnione. Jakie to warunki?
  - Wskazówka: `≡`, `<`, `>`

Złożoność obliczeniowa
  g++ complex.cpp prq.cpp binHeap/heap.cpp -o complex
	./complex