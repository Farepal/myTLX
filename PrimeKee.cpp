#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

vector <long long> prima;

bool prime(int n){
	if (n % 2 == 0 && n != 2 or n == 1 or n % 3 == 0 && n != 3 or n % 5 == 0 && n != 5 or n % 7 == 0 && n != 7){
		return false;
	}
	
	for (int i = 11; i <= floor(sqrt(n)); i += 2){
		while (i % 3 == 0 or i % 5 == 0 or i % 7 == 0){
			i += 2;
		}
		
		if (n % i == 0){
			return false;
		}
	}
	return true;
}

int main(){
	prima.push_back(1);
	for (int i=0, j = 2; i < 77777; j++){
		if (prime(j)){
			prima.push_back(j);
			i++;
		}
	}
	
	int t;
	cin >> t;
	
	for (int i = 0; i < t; i++){
		int x;
		cin >> x;
		cout << prima[x] << endl;
	}
	
	return 0;
}