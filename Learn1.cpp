#include <iostream>
#include <string>

using namespace std;

int main(){
	string a("sabunkeramaskekerara");
	string b("kera");
	
	int i = 0;
	int s = a.find(b);

	while (true){
		a = a.erase(a.find(b), a.length());
		if (a.find(b) == string::npos){
			break;
			//nanti ada yg s nya -1 minimal 1 buah
			//jadinya gw break dah
		}
	}
	
	cout << a << endl;

	return 0;
}