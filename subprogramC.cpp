#include <bits/stdc++.h>

using namespace std;

int reserve (int x){
	int ret = 0;
	while (x > 0){
		ret = ret * 10 + x % 10;
		x /= 10;
	}
	return ret;
}

int main(){
	int a, b, c;
	cin >> a >> b;
	
	a = reserve(a);
	b = reserve(b);
	
	c = a + b;
	c = reserve(c);
	
	cout << c << endl;
	
	return 0;
}