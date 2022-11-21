import time
n = int(input())
startt = time.time()
angka = [0]
flag = [0]

for i in range(n):
    angka.append(0)
    flag.append(False)

def Permutasi (k):
    if k == n+1:
        zigzag = True
        for i in range(2, n) :
            condition1 = angka[i] > angka[i-1] and angka[i] > angka[i+1]
            condition2 = angka[i] < angka[i-1] and angka[i] < angka[i+1]
            zigzag = condition1 or condition2
            if not zigzag:
                break
        if zigzag:
            string = ""
            for i in range(1, n+1):
                string += str(angka[i])
            print(string)
    else :
        for i in range(1,n+1):
            if flag[i] == False:
                flag[i] = True
                angka[k] = i
                Permutasi (k+1)
                flag[i] = False

Permutasi(1)
print(time.time() - startt)