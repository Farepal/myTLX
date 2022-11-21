n =int(input())
A=input().split()
B=input().split()

T=int(input())
for i in range(T):
    p,x,q,y=input().split()
    x = int(x)-1
    y = int(y)-1
    if p == 'A' and q=='B':
        A[x],B[y] = B[y],A[x]
    elif p=='A' and q=='A' :
        A[x],A[y] = A[y],A[x]
    elif p=='B' and q=='B':
        B[x],B[y] =B[y],B[x]
    elif p=='B' and q=='A':
        B[x],A[y] = A[y],B[x]

for i in range(n):
    if i==n-1:
        print(A[i])
    else:
        print(A[i],end=' ')
for i in range(n):
    if i==n-1:
        print(B[i])
    else:
        print(B[i],end=' ')