string = input()
sz = int(input())
prefix = ""
prefix += string[:string.find('*')]
suffix = ""
suffix += string[string.find('*')+1:]
ppanjang = len(prefix)
spanjang = len(suffix)
for i in range(sz):
    temp = input()
    tpanjang = len(temp)
    if tpanjang < ppanjang + spanjang:
        continue
    if ppanjang != 0:
        if temp.find(prefix) != 0:
            continue
    ketemusuffix = temp.find(suffix)
    if spanjang != 0:
        if ketemusuffix == -1 or temp[tpanjang-spanjang:] != suffix:
            continue
    print(temp)
