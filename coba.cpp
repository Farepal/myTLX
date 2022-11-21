#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
//PERMUTASI dengan N angka dengan B baris
using namespace std;
//index dimulai dari 0 ya!!!

int banyaknya_mutasi = 0;

void permutasi(int baris[], bool udah[], string s, int len, int ind){
	if (ind == len){
		banyaknya_mutasi++;
		for (int i = 0; i < len; i++){
			cout << s[baris[i]];
		}
		if (banyaknya_mutasi % 7 == 0) cout << endl;
		else cout << "\t";
	}
	else {
		for (int i = 0; i < len; i++){
			if (udah[i] == false){
				udah[i] = true;
				baris[ind] = i;
				permutasi (baris, udah, s, len, ind+1);
				udah[i] = false;
			}
		}
	}
}

int main(){
	string s;
	cin >> s;
	int len = s.length();
	
	int baris[len];
	bool udah[len];
	
	memset (udah, false, sizeof udah);
	
	permutasi (baris, udah, s, len, 0);
	cout << endl;
	cout << "BANYAKNYA PERMUTASI ADALAH : " << banyaknya_mutasi << endl;
	
	return 0;
}