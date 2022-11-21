#include <iostream>
#include <string>

using namespace std;

int main(){
	string st1, st2, st3, st4;
	
	cin >> st1 >> st2 >> st3 >> st4;
	
	st1.erase(st1.find(st2), st2.length());
	
	st1.insert(st1.find(st3) + st3.length(), st4);
	
	cout << st1 << endl;
	
	return 0;
}