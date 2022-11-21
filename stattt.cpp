#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int minn = 101000;
	int maxx = -101000;
	while (n--){
		int x;
		cin >> x;
		if (x > maxx)
			maxx = x;
		else if (x < minn)
			minn = x;
	}
	cout << maxx << " " << minn << endl;
	return 0;
}
