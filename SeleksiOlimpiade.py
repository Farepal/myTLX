T =int(input())

def tukerGa (isinyaList, indeksAcuan, indeksKanan):
    if isinyaList[indeksAcuan][3] < isinyaList[indeksKanan][3]:
        return True
    elif isinyaList[indeksAcuan][3] == isinyaList[indeksKanan][3]:
        if isinyaList[indeksAcuan][2] < isinyaList[indeksKanan][2]:
            return True
        elif isinyaList[indeksAcuan][2] == isinyaList[indeksKanan][2]:
            if isinyaList[indeksAcuan][1] < isinyaList[indeksKanan][1]:
                return True
        return False
    return False

for i in range(T):
    n,m=input().split()
    n=int(n)#peserta
    m=int(m)#banyaknya yg lulus
    stringSiswa = input()
    peserta = []

    for j in range(n):
        arrTemp = input().split()
        for k in range(1,4):
            arrTemp[k] = int(arrTemp[k])
        peserta.append(arrTemp)

    #SORTING BOSSSSS
    for j in range (n):
        for k in range (j+1,n):
            if tukerGa (isinyaList=peserta, indeksAcuan=j, indeksKanan=k):
                peserta[j], peserta[k] = peserta[k], peserta[j]

    berhasil = False
    for j in range(m):
        if peserta[j][0] == stringSiswa:
            berhasil = True
            break

    print ("YA" if berhasil else "TIDAK")