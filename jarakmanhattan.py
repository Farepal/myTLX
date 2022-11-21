a, b, c, d = input ('').split()
a = int(a)
b = int(b)
c = int(c)
d = int(d)
hasil1 = (a-c) if (a-c) >= 0 else (a-c)*-1
hasil2 = (d-b) if (d-b) >= 0 else (d-b)*-1
print (hasil1 + hasil2)