#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, d;
	cin >> n >> d;
	
	int anak[n][2];
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < 2; j++){
			cin >> anak[i][j];
		}
	}
	//Tij = |Xj - Xi|^d + |Yj - Yi|^d
	//Mencari teman yang satu dengan yang lain mana yang terkecil dan terbesar
	int dekatTerkecil;
	int dekatTerbesar;
	for (int i = 0; i < n; i++){
		for (int j = i+1; j < n; j++){
			int num = pow (abs (anak[i][0] - anak[j][0]), d) + pow (abs (anak[i][1]- anak[j][1]), d);
			if (i == 0 && j == 1){
				dekatTerkecil = num;
				dekatTerbesar = num;
				yangpertama = false;
			}
			else {
				if (num > dekatTerbesar){
					dekatTerbesar = num;
				}
				
				if (num < dekatTerkecil){
					dekatTerkecil = num;
				}
			}
		}
	}
	
	cout << dekatTerkecil << " " << dekatTerbesar << endl;
	
	return 0;
}