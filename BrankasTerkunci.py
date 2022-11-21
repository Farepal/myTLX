n,k=input().split()
n=int(n)
k=int(k)
arr = []
for i in range(n):
    arr.append(0)
def kombinasi (kedalaman, angka):
    if kedalaman == k:
        for i in range(k):
            if i < k-1:
                print(arr[i],end=' ')
            else :
                print(arr[i])
    else:
        for i in range (angka, n+1):
            arr[kedalaman] = i
            kombinasi (kedalaman+1, i+1)
kombinasi (0,1)