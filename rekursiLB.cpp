#include <iostream>

using namespace std;

void pegunungan(int n){
	if (n > 0){
		pegunungan (n-1);
		for (int i = 1; i <= n; i++){
			cout << "*";
		}
		cout << endl;
		pegunungan (n-1);
	}
}

int main(){
	int n;
	cin >> n;
	
	pegunungan (n);
	return 0;
}