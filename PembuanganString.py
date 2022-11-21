string, kehapus = input().split()
while kehapus in string :
    string = string.replace(kehapus, '')
print(string)