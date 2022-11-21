n, m = input().split()
n=int(n)
m=int(m)
matriks = []
for i in range(n) :
    s = input().split()
    matriks.append(s)
j = 0
while (j<m) :
    i = n-1
    while(i>=0) :
        if (i==0):
            print (matriks[i][j])
        else:
            print(matriks[i][j],end=' ')
        i-=1
    j+=1