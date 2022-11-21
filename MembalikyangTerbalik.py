a,b=input().split()
a=int(a)
b=int(b)
def reverse (num):
    baru = 0
    while num>0 :
        baru =baru*10 + num%10
        num//=10
    return baru
print (reverse(reverse(a)+reverse(b)))