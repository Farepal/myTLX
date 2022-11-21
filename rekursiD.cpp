#include <iostream>
#include <string>

using namespace std;

int palindrom(string s, int len){
	if (len == 1 or len == 0){
		return len;
	}
	else{
		if (s[0] != s[len-1]) {
			return len;
		}
		else {
			s.erase (0, 1);
			s.erase (len-2, 1);
			return palindrom (s, s.length());
		}
	}
}

int main(){
	string s;
	cin >> s;
	
	if (palindrom (s, s.length()) == 1 or palindrom (s, s.length()) == 0){
		cout << "YA" << endl;
	}
	else {
		cout << "BUKAN" << endl;
	}
	
	return 0;
}