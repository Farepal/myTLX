s=input("")
k=int(input())
huruf = ""
for i in s:
    huruf = huruf + (chr((ord(i)-ord('a')+k)%26+ord('a')))
print (huruf)