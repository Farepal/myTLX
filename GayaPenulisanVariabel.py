string = input()
if '_' in string :
    while '_' in string :
        finder = string.find('_')
        string = string[:finder] + string[finder+1].upper() + string [finder+2:]
else :
    i = 1
    while i < len(string):
        if string[i].isupper():
            string = string[:i] + '_' + string[i].lower() + string[i+1:]
        i+=1
print (string)