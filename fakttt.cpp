#include <iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	for (int i = 1, j = 0; i <= n; i++){
		for (int k = 1; k <= i; k++, j++){
			if (j==10){
				j = 0;
			}
			cout << j;
		}
		cout << endl;
	}
	return 0;
}
