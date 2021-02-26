def binary_search(liste, aranan):
    sol = 0
    sag = len(liste) - 1
    while (sol <= sag):
        ortadaki = (sol + sag) // 2
        if (aranan == liste[ortadaki]):
            return ortadaki
        elif (aranan > liste[ortadaki]):
            sol = ortadaki + 1
        else:
            sag = ortadaki -1
    return -1

liste = [3, 4, 5, 9, 11, 18, 20, 21]
indeks = binary_search(liste, 21)
print('Aranan elemanın indeksi: {0}'.format(indeks))