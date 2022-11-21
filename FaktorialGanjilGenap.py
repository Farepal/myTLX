def fak (num):
    if num > 1:
        return (num//2 if num%2==0 else num) * fak (num-1)
    else :
        return 1
print (fak(int(input())))