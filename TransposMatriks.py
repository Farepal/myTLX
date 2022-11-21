arr = []
rows = 3
for i in range(rows) :
    col = []
    a, b, c = input ('').split()
    a = int(a)
    b = int(b)
    c = int(c)
    col.append (a)
    col.append (b)
    col.append (c)
    arr.append (col)
for i in range(3) :
    for j in range(3) :
        if j == 2 :
            print (arr[j][i], end = '\n')
        else :
            print (arr[j][i], end = ' ')