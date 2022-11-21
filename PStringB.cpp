#include <bits/stdc++.h>

using namespace std;

int main(){

	string a, b;
	cin >> a >> b;
	
	/* 
	
	kalau ada beberapa fungsi di bawah
	yang nggak bisa di compile di devc++ mu,
	perhatikan compiler option (ada di tools -> compiler option)
	di bagian "add the following command to the linker kasih:
	-static -libgcc -std=c++11 
	
	*/
	while (a.find(b) != string::npos){
		a.erase(a.find(b), b.length());
		//erase(posisi_karakter, panjang_karakter_yg_dihapus)
	}
	
	cout << a << endl;
	
	/*
	
	lebih lanjut tentang fungsi a.find(b) bisa dilihat di
	https://www.geeksforgeeks.org/string-find-in-cpp/
	
	untuk yang a.erase() bisa dilihat di
	https://www.geeksforgeeks.org/stdstringerase-in-cpp/
	(di sini saya gunakan syntax yang ke-tiga)
	
	*/

	return 0;
}