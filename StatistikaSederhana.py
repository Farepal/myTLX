n = int(input())
arr = input().split()
A = -10e5 #terbesar
B = 10e5 #terkecil
#algorithm start here brooooooo
for i in range(n) :
    arr[i] = int(arr[i])
    if (arr[i] > A) :
        A = arr[i]
    if (arr[i] < B) :
        B =  arr[i]
print (f"{A} {B}")