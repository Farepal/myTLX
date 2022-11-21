a,b,k,x=input().split()
a=int(a)
b=int(b)
k=int(k)
x=int(x)
def fungsinya(aa,bb,kk,xx):
    if kk>1:
        return abs(aa*(fungsinya(aa,bb,kk-1,xx))+b)
    elif kk==1:
        return abs(aa*xx+b)
print (fungsinya(a,b,k,x))