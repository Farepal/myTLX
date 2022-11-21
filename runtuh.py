baris, kolom = input().split()
baris = int(baris)
kolom = int(kolom)
barisTerbawahYgKena = -1
kotak = []

def itemSebarisGa():
    sabi = False
    global baris
    global kolom
    global barisTerbawahYgKena

    for i in range(baris):
        flag = True
        for j in range(kolom):
            if kotak[i][j] == '0':
                flag = False
                break

        if flag:
            sabi = True
            barisTerbawahYgKena = i
            for j in range(kolom):
                kotak[i][j] = '0'

    return sabi

for i in range(baris):
    temp = []
    sss = input()
    for j in range (kolom):
        temp.append(sss[j])
    kotak.append(temp)

while (itemSebarisGa()):
    for i in range (barisTerbawahYgKena-1, -1, -1):
        for j in range (kolom):
            if kotak[i][j] == '1':
                tempI = i
                while (tempI+1 < baris and kotak[tempI+1][j] == '0'):
                    kotak[tempI][j], kotak[tempI+1][j] = kotak[tempI+1][j], kotak[tempI][j]
                    tempI += 1

for x in kotak:
    for y in x:
        print (y,end='')
    print('')