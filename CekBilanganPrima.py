bilangan_prima = [2]
for i in range (3,1000,2):
    primaGa = True
    for num in bilangan_prima:
        if (i % num == 0) :
            primaGa = False
            break
    if(primaGa == False) :
        continue
    for j in range (3, i):
        if (i % j == 0) :
            primaGa = False
            break
    if primaGa == True :
        bilangan_prima.append(i)
# for num in bilangan_prima :
#     print (num,end=' ')

n = int(input())
for i in range(n) :
    num = int(input())
    prime = True
    if (num == 1) :
        prime = False
    for bilP in bilangan_prima :
        if num == bilP :
            break
        if num % bilP == 0 :
            prime = False
            break
    if (prime==False):
        print("BUKAN")
    else :
        print("YA")