def draw (num):
    if num == 1:
        print ('*')
    else :
        draw (num-1)
        print ("*"*num)
        draw (num-1)
draw (int(input()))