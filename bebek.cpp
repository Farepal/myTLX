#include <bits/stdc++.h>

using namespace std;

#define vt vector

int main(){
	int n;
	cin >> n;
	
	vt <int> bebek;
	
	for (int i = 1; i <= n; i++){
		int berat;
		cin >> berat;
		bebek.push_back(berat);
	}
	
	int q;
	cin >> q;
	
	while (q--){
		int x, y;
		cin >> x >> y;//lebih dari x dan kurang dari y
		
		vector <int>::iterator kanan, kiri;
		kanan = upper_bound(bebek.begin(), bebek.end(), y);//ngikutin angka terdekat ke kirinya
		//ngikutin angka terdekat ke kirinya
		//contoh 1 3 5 7 9 upb(2) maka ambil index tempat nya 1 yaitu 0
		kiri = upper_bound(bebek.begin(), bebek.end(), x);//
		
		cout << (kanan - bebek.begin()) - (kiri - bebek.begin()) << endl;
	}
	
	return 0;
}