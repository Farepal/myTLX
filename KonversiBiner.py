def konversiBiner (num):
    if num==1:
        return "1"
    elif num%2==0:
        return konversiBiner(num//2) + "0"
    else :
        return konversiBiner(num//2) + "1"
print (konversiBiner(int(input())))