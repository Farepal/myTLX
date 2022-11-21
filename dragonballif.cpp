#include <iostream>
#include <string>

using namespace std;

int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		int x;
		cin >> x;
		string s = "";
		if (x == 0){
			cout << s << endl;
			continue;
		}
		s.append("k");
		for (int j = 1; j <= x; j++){
			s.append ("a");
		}
		s.append("m");
		for (int j = 1; j <= x; j++){
			s.append ("e");
		}
		s.append("h");
		for (int j = 1; j <= x; j++){
			s.append ("a");
		}
		s.append("m");
		for (int j = 1; j <= x; j++){
			s.append ("e");
		}
		s.append("h");
		for (int j = 1; j <= x; j++){
			s.append ("a");
		}
		cout << s << endl;
	}
	return 0;
}