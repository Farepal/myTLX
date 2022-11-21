def ubahDuaPangkat (num):
    i = 1
    while i <= 128:
        if num <= i:
            return i
        i*=2

n = int(input())
arr = []

for i in range(n):
    arr.append(input())
r,c=input().split()

r1 = int(r)
c1 = int(c)
r=ubahDuaPangkat(int(r))
c=ubahDuaPangkat(int(c))
r=c if c>r else r
c=r if r>c else c
kotak = []

for i in range (r):
    s = []
    for j in range (c):
        s.append('0')
    kotak.append(s)

def draw (starti, startj, endi, endj):
    for i in range (starti, endi+1):
        for j in range (startj, endj+1):
            kotak[i][j] = '1'

def penerjemahan (starti, startj, endi, endj, string):
    if string == "":
        draw (starti, startj, endi, endj)
    else:
        pengubahIndeks1 = (starti+endi)//2
        pengubahIndeks2 = (startj+endj)//2
        if string[0] == '0':
            penerjemahan (starti, startj, pengubahIndeks1, pengubahIndeks2, string[1:])
        elif string[0] == '1':
            penerjemahan (starti, pengubahIndeks2+1, pengubahIndeks1, endj, string[1:])
        elif string[0] == '2':
            penerjemahan (pengubahIndeks1+1, startj, endi, pengubahIndeks2, string[1:])
        elif string[0] == '3':
            penerjemahan (pengubahIndeks1+1, pengubahIndeks2+1, endi, endj, string[1:])

for string in arr :
    penerjemahan (0,0,r-1,c-1,string[1:])

for i in range(r1):
    for j in range(c1):
        print (kotak[i][j], end=' ' if j<(c1-1) else '\n')