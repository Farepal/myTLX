n, k = input().split()
n = int(n)
k = int(k)
for i in range (1,n+1) :
    if (i % k == 0) :
        if (i == n) :
            print ('*')
        else :
            print ('*', end = ' ')
    else :
        if (i == n) :
            print (i)
        else :
            print (i, end = ' ')