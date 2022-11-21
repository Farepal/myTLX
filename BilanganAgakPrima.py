n = int(input())
for i in range(n):
    num = int(input())
    flag = True
    j = 2
    count = 0
    while j**2 <= num:
        if num % j == 0 :
            if j*j == num :
                count += 1
            else :
                count += 2
        if count > 2 :
            flag = False
            break
        j+=1
    if not flag :
        print ("BUKAN")
    else :
        print ("YA")