class BinaryTree:
    def __init__(self):
        self.bilgi = None
        self.mesaj = None
        self.sol = None
        self.sag = None

kok = None

def ekle(agac_kok, yeni):
    global kok
    if (agac_kok == None):
        kok = yeni
    else:
        if (yeni.bilgi <= agac_kok.bilgi):
            if (agac_kok.sol == None):
                agac_kok.sol = yeni
            else:
                ekle(agac_kok.sol, yeni)
        else:
            if (agac_kok.sag == None):
                agac_kok.sag = yeni
            else:
                ekle(agac_kok.sag, yeni)

def listele(agac_kok):
    if (agac_kok != None):
        listele(agac_kok.sol)
        print("{0}: {1}".format(agac_kok.bilgi, agac_kok.mesaj))
        listele(agac_kok.sag)

def ara(agac_kok, aranan):
    while ((agac_kok != None) and (agac_kok.bilgi != aranan)):
        if (aranan < agac_kok.bilgi):
            agac_kok = agac_kok.sol
        else:
            agac_kok = agac_kok.sag
    return agac_kok

def minValueNode(node):
    current = node
    while(current.left is not None):
        current = current.left
    return current

def sil(agac_kok, silinecek):
    if agac_kok == None:
        return agac_kok
    
    if silinecek < agac_kok.bilgi:
        agac_kok.sol = sil(agac_kok.sol, silinecek)
    elif silinecek > agac_kok.bilgi:
        agac_kok.sag = sil(agac_kok.sag, silinecek)
    else:
        if agac_kok.sol == None:
            temp = agac_kok.sag
            agac_kok = None
            return temp
        elif agac_kok.sag == None:
            temp = agac_kok.sol
            agac_kok = None
            return temp
        temp = minValueNode(agac_kok.sag)
        agac_kok.bilgi = temp.bilgi
        agac_kok.sag = sil(agac_kok.sag, temp.bilgi)
    return agac_kok


if __name__ == '__main__':
    bt1 = BinaryTree()
    bt1.bilgi = 1
    bt1.mesaj = "Merhaba"

    bt2 = BinaryTree()
    bt2.bilgi = 2
    bt2.mesaj = "Nasılsın"

    bt3 = BinaryTree()
    bt3.bilgi = 3
    bt3.mesaj = "Görüşürüz"
    
    ekle(kok, bt1)
    ekle(kok, bt2)
    ekle(kok, bt3)

    print('Ekleme sonrası listeleme:')
    listele(kok)

    sil(kok, 3)
    print('Silme işlemi sonrası listeleme:')
    listele(kok)

    bulunan = ara(kok, 2)
    print('Bulunan -> {0}: {1}'.format(bulunan.bilgi, bulunan.mesaj))
