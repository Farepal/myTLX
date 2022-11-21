num = int(input())
i = 1
flag = False
while i <= 2**16 :
    if (i == num) :
        flag = True
        print ("ya")
    i *= 2
if flag == False :
    print ("bukan")