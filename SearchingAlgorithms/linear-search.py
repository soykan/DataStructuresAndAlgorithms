def linear_search(liste, aranan):
    for i in range(0, len(liste)):
        if (liste[i] == aranan):
            return i
    return -1

liste = [5, 3, 11, 9, 21, 18, 20, 4]
indeks = linear_search(liste, 21)
print('Aranan elemanın indeksi: {0}'.format(indeks))

