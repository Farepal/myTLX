string = input()
panjang = len(string)

def cekPalindrom (starting, ending):
    if starting==ending or starting==ending+1:
        return True
    else :
        if string[starting] == string[ending]:
            return cekPalindrom(starting+1, ending-1)
        else :
            return False

print ("YA" if cekPalindrom(0,panjang-1) else "BUKAN")