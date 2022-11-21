#include <bits/stdc++.h>

using namespace std;

bool prime(int n){
	if (n % 2 == 0 && n != 2 or n == 1 or n % 3 == 0 && n != 3 or n % 5 == 0 && n != 5 or n % 7 == 0 && n != 7){
		return false;
	}
	for (int i = 11; i <= ceil(sqrt(n)); i+=2){
		if (n % i == 0){
			return false;
		}
	}
	return true;
}

int main(){
	int n;
	cin >> n;
	
	bool yangpertama = true;
	int modus;
	for (int i = 2; n > 1; i++){
		while (prime(i) == false){
			i++;
		}
		
		int pangkat = 0;
		while (n % i == 0){
		n /= i;
		pangkat++; 
		}
		
		if (pangkat > 0){
			if (yangpertama){
				yangpertama = false;
				if (pangkat > 1){
					cout << i << "^" << pangkat;
				}
				else {
					cout << i;
				}
			}
			else {
				cout << " x ";
				if (pangkat > 1){
					cout << i << "^" << pangkat;
				}
				else {
					cout << i;
				}
			}
		}
	}
	cout << endl;
	
	return 0;
}