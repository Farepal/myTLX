n = int(input())
num = 0
for i in range(1, n+1) :
    for j in range(1, i+1) :
        if(j==i) :
            print(num)
        else :
            print(num,end='')
        if(num == 9) :
            num = 0
        else :
            num += 1