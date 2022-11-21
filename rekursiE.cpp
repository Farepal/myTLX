#include <iostream>

using namespace std;

void konversibiner (int x){
	if (x == 1){
		cout << "1";
	}
	else if (x % 2 == 1){
		konversibiner (x/2);
		cout << "1";
	}
	else if (x % 2 == 0){
		konversibiner (x/2);
		cout << "0";
	}
}
//output berjalan dari belakang ke depan
//contoh  dst 1<--1<--1<--0

int main(){
	int n;
	cin >> n;
	
	konversibiner (n);
	cout << endl;
	
	return 0;
}