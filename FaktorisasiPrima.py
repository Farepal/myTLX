import math
def cekPrima (num):
    if num==1 or num%2==0 and num!=2 or num%3==0 and num!= 3 or num%5==0 and num!= 5 or num%7==0 and num!=7 or num%11==0 and num!=11:
        return False
    for i in range(11, int(math.ceil(math.sqrt(num)))+1, 2):
        if num%i==0:
            return False
    return True

m =int(input())
huruf = ""
i = 2
while m>1:
    count = 0
    while not cekPrima(i):
        i +=1
    while m%i==0 and m>1:
        m//=i
        count+=1
    if m==1:
        if count > 1:
            huruf =huruf + f"{i}^{count}"
        elif count==1 :
            huruf = huruf + f"{i}"
    else :
        if count > 1:
            huruf =huruf + f"{i}^{count} x "
        elif count==1 :
            huruf = huruf + f"{i} x "
    i+=1
print (huruf)