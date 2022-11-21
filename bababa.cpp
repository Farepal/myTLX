#include <iostream>

using namespace std;

int main(){
	int n;
	int arr[5] = {0,1,2,3,4};
	
	int s = 0;
	for (int i = 0; i < 5; i++){
		arr[0]++;
		cout << i << " ";
	}
	cout << endl;
	
	cout << arr[0] << endl;
	return 0;
}