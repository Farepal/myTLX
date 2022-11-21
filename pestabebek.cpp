#include <iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	
	string nama[n];
	
	for (int i = 0; i < n; i++){
		cin >> nama[i];
	}
	
	cout << "1" << endl;
	
	for (int i = 1; i < n; i++){
		int count = 1;
		for (int j = 0; j < i; j++){
			if (nama[i] > nama[j]) count++;
		}
		cout << count << endl;
	}
	
	return 0;
}