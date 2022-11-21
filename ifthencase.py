a = int (input (''))
if a < 10 :
    print ('satuan')
elif a < 100 :
    print ('puluhan')
elif a < 1000 :
    print ('ratusan')
elif a < 1e4 :
    print ('ribuan')
elif a <= 1e5 :
    print ('puluhribuan')