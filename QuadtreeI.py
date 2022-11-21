def ubahDuaPangkat (num):
    i = 1
    while i <= 128:
        if num <= i:
            return i
        i*=2
r,c=input().split()
r=int(r)
c=int(c)
kotak = []
for i in range(r):
    s=input().split()
    kotak.append(s)
r=ubahDuaPangkat(int(r))
c=ubahDuaPangkat(int(c))
r=c if c>r else r
c=r if r>c else c
kotakBaru=[]
for i in range(r):
    s=[]
    for j in range(c):
        s.append('0')
    kotakBaru.append(s)
for i in range(len(kotak)):
    for j in range(len(kotak[i])):
        kotakBaru[i][j] = kotak[i][j]

hasilString = [] 

def cekHomogen (starti, startj, endi, endj):
    pengecek = kotakBaru[starti][startj]
    for i in range(starti, endi+1):
        for j in range(startj, endj+1):
            if kotakBaru[i][j] != pengecek :
                return False
    return True

def mulai(starti, startj, endi, endj, string):
    if not cekHomogen (starti, startj, endi, endj):
        pengubahIndeks1 = (starti+endi)//2
        pengubahIndeks2 = (startj+endj)//2
        mulai (starti, startj, pengubahIndeks1, pengubahIndeks2, string+'0')
        mulai (starti, pengubahIndeks2+1, pengubahIndeks1, endj, string+'1')
        mulai (pengubahIndeks1+1, startj, endi, pengubahIndeks2, string+'2')
        mulai (pengubahIndeks1+1, pengubahIndeks2+1, endi, endj, string+'3')
    else :
        if kotakBaru[starti][startj] == '1':
            hasilString.append(kotakBaru[starti][startj]+string)

mulai (0,0,r-1,c-1,"")
print (len(hasilString))
for hasil in hasilString:
    print(hasil)