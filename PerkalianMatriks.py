n,m,p = input().split()
n=int(n)
m=int(m)
p=int(p)
matriks1 = []
for i in range(n):
    s = input().split()
    for j in range(m):
        s[j]=int(s[j])
    matriks1.append(s)

matriks2=[]
for i in range(m):
    s=input().split()
    for j in range(p):
        s[j]=int(s[j])
    matriks2.append(s)

ansMatriks = []
for i in range(n):
    tempMatriks=[]
    for j in range(p):
        temp = 0
        for k in range (m):
            temp += (matriks1[i][k]*matriks2[k][j])
        tempMatriks.append(temp)
    ansMatriks.append(tempMatriks)

for i in range(n):
    for j in range(p):
        if j==p-1:
            print (ansMatriks[i][j])
        else :
            print(ansMatriks[i][j],end=' ')