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
	int ke;
	cin >> ke;
	
	for (int i = 2, j = 1; j <= ke; i++){
		if (prime (i) == true){ 
			cout << i << " ";
			j++;
		}
	}
	cout << endl;
		
	return 0;
}