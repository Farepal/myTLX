#include <bits/stdc++.h>

using namespace std;

int faktorial(int n){
	int num = 1;
	for (int i = n; i >= 1; i--){
		num = num * i;
	}
	return num;
}

int kombinasi (int a, int b){
	int i = faktorial(a);
	int j = faktorial(a-b);
	int k = faktorial(b);
	return i/(j*k);
}

int main(){
	int sum = 0;
	for (int i = 1; i <= 3; i++){
		for (int j = 1; j <= 3; j++){
			for (int k = 1; k <= 3; k++){
				int baaa = 0;
				if ((i+j+k) == 7){
					baaa = 1;
					cout << i << ' ' << j << ' ' << ' ' << k << endl;
					baaa = kombinasi(7,i) * kombinasi(7-i,j);
				}
				sum = sum + baaa;
			}
		}
	}
	cout << sum << endl;
	return 0;
}