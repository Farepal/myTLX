import time
start_time = time.time()
n = 20000#batas nilai bilangan prima
bilangan_prima = [2]
for i in range(3,n,2):
    primaGa = True
    for num in bilangan_prima:
        if (i % num == 0) :
            primaGa = False
            break
    if primaGa == True :
        bilangan_prima.append(i)
for num in bilangan_prima :
    print (num,end=' ')
print('\n')
print(time.time() - start_time, "detik")