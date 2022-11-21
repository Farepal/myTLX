#include <iostream>
#include <cmath>
#include <vector> 

using namespace std;
#define int unsigned long long int

int powerin(int x, int y, int mod){
	x %= mod;
	if (x == 1)
		return 1;
	else if (x == 0)
		return 0;
	else if (y == 0)
		return 1;
	else if (y == 1)
		return x;
    vector <int> isi;
    for (int i = 1; i <= y; i *= 2){
        if ((y & i) == i)
            isi.push_back(i);
    }

	int iz = isi.size();
	int ret1 = 1, ret2 = 1;
	for (int i = 0; i < iz; i++){
		ret1 = x;
		for (int j = isi[i]; j > 1; j /= 2){
			ret1 *= ret1;
			ret1 %= mod;
		}
		ret2 *= ret1;
		ret2 %= mod;
	}
	return ret2;
}

signed main(){
    int a, b, c, n;
    cin >> a >> b >> c >> n;
	int ans = powerin (a, b, n);
	for (int i = 1; i <= c - 1; i++)//sebanyak c-1
		ans = powerin (ans, b, n);
	cout << ans + 1 << endl;
	//misal 2 2 3 tanpa n ya; ^ itu pangkat misalnya
	//2^2 = 4; lalu karena sebanyak c-1 kali maka menjadi 3-1=2
	//1 .... 4^2 = 16; 2....16^2 = 256
	// dan 256 itu sama dengan 2^8

    return 0;
}