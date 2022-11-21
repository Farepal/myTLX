r,c=input().split()
r=int(r)
c=int(c)
kotak = []
for i in range (r):
    temp = input().split()
    kotak.append(temp)
rklik, cklik = input().split()
rklik = int(rklik)
cklik = int(cklik)

def bisaGa (barisAwal, kolomAwal, barisYangKena, kolomYangKena):
    if barisYangKena == r or kolomYangKena == c or barisYangKena == -1 or kolomYangKena == -1:
        return False
    if kotak[barisAwal][kolomAwal] != kotak[barisYangKena][kolomYangKena]:
        return False
    if udahKena[barisYangKena][kolomYangKena]:
        return False
    return True

udahKena = []
for i in range (r):
    temp = []
    for j in range (c):
        temp.append(False)
    udahKena.append(temp)

skor = 0
def klik (baris, kolom):
    global skor
    skor += 1
    udahKena[baris][kolom] = True
    if bisaGa (baris, kolom, baris-1, kolom):
        klik(baris-1, kolom)
    if bisaGa (baris, kolom, baris+1, kolom):
        klik (baris+1, kolom)
    if bisaGa (baris, kolom, baris, kolom+1):
        klik (baris, kolom+1)
    if bisaGa (baris, kolom, baris, kolom-1):
        klik (baris, kolom-1)

klik (rklik, cklik)
print (skor*(skor-1))