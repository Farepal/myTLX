gelas = []
for i in range(1001):
    gelas.append(0)
n = int(input())
s=input().split()
for i in range(n):
    s[i] = int(s[i])
for num in s:
    gelas[num] += 1
terbesar = -9
mod = 0
for num in s:
    if gelas[num] > mod:
        mod = gelas[num]
        terbesar = num
    elif gelas[num] == mod and num > terbesar:
        terbesar = num
print (terbesar)