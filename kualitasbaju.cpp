#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;


/*void mySort (int x){
	if (x > 0){
		for (int i = 0; i < x; i++){
			if (kualitas[i] > kualitas[i+1]){
				swap (kualitas[i], kualitas[i+1]);
			}
		}
		mySort(x-1);
	}
}*/

int main(){
	int n;
	cin >> n;
	
	int kualitas[n];

	for (int i = 0; i < n; i++){
		cin >> kualitas[i];
	}
	
	sort (kualitas, kualitas + n);
	
	cout << setprecision(1) << fixed;
	
	if (n % 2 == 0){
		cout << ((double)kualitas[n/2] + (double)kualitas[n/2 - 1]) / 2 << endl;
	}
	else {
		cout << (double)kualitas[n/2] << endl;
	}
	
	return 0;
}