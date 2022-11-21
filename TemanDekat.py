n,d=input().split()
n=int(n)
d=int(d)
temen=[]
for i in range(n):
    s=input().split()
    s[0]=int(s[0])
    s[1]=int(s[1])
    temen.append(s)

terkecil = 10e7
terbesar = -10e7
for i in range (n):
    for j in range (i+1, n):
        nilai = abs(temen[j][0]-temen[i][0])**d + abs(temen[j][1]-temen[i][1])**d
        terkecil = nilai if nilai < terkecil else terkecil
        terbesar = nilai if nilai > terbesar else terbesar
print (f"{terkecil} {terbesar}")