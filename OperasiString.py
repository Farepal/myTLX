s1=input()
s2=input()
s3=input()
s4=input()
ans = ""
s1 = s1.replace(s2, "")
ind = s1.find(s3)
length = len(s3)
ans = s1[:ind+length] + s4 + s1[ind+length:]
print (ans)