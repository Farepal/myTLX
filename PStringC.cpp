//CAESAR CHIPER
#include <iostream>
#include <string>

using namespace std;

int main(){
	string huruf;
	cin >> huruf;
	
	int n;
	cin >> n;
	
	for (int i = 0; i < huruf.length(); i++){
		int alfabet = huruf[i] - 'a';
		// proses pengubahan huruf menjadi angka
		//angka yg dimaksudkan adalah urutan kode ASCII
		alfabet = (alfabet + n) % 26; 
		//26 itu jumlah huruf
		//baca tentang ASCII code
		huruf[i] = 'a' + alfabet;
		//proses pengubahan angka menjadi huruf
		//angka yg dimaksudkan adalah urutan alfabet
	}
	
	cout << huruf << endl;
	
	return 0;
}