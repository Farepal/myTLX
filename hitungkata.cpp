#include <iostream>
#include <string>

using namespace std;

int main(){
	string s, p;
	cin >> s >> p;

	int len = p.length();

	long fnd = s.find(p[0]);
	
	cout << fnd << '\n';

	return 0;
}