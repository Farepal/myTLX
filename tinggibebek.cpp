#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> tinggi;
void mySort (int x){
	if (x > 0){
		for (int i = 0; i < x; i++){
			if (tinggi[i] > tinggi[i+1]){
				swap (tinggi[i], tinggi[i+1]);
			}
		}
		mySort(x-1);
	}
}

int main(){
	int n, k;
	cin >> n >> k;
	
	for (int i = 0; i < n; i++){
		int t;
		cin >> t;
		tinggi.push_back(t);
	}
	
	mySort (n-1);
	
	cout << tinggi[k-1] << endl;
	
	return 0;
}