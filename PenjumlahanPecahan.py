a,b=input().split()
a=int(a)
b=int(b)
c,d=input().split()
c=int(c)
d=int(d)
def efpebe(b, d):
    if b%d==0:
        return d
    else:
        return efpebe(d, b%d)
haskpk = b*d//efpebe(b,d)
print(efpebe(b,d))
print(haskpk)