#include <iostream>
#include <map>
using namespace std;

int main(){
	int n, q;
	cin >> n >> q;
	
	map <string, string> daftar;
	while (n--){
		string nama, no;
		cin >> nama >> no;
		daftar.insert(make_pair(nama, no));
	}
	
	while (q--){
		string x;
		cin >> x;
		
		map <string, string>::iterator it = daftar.find(x);
		if (it == daftar.end()){
			cout << "memek" << endl;
		}
	}
	
	cout << __cplusplus << endl;//if I compile wit "g++ wartel.cpp -o wartel"
	//the output would be 201402
	
	return 0;
}