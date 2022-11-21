#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int n;
	cin >> n;
	
	short x;
	short count = 0;
	for (int i = 0; i < n; i++){
		cin >> x;
		if (x % 2 == 1) count++;
	}
	
 	for (int i=0; i < n; i++){
 		cin >> x;
 	}
	
	if (count % 2 == 0){
		cout << 0 << endl;
	}
	else {
		cout << 1 << endl;
	}
	
	return 0;
}