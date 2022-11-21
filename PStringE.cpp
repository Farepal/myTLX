#include <iostream>
#include <string>

using namespace std;

//Baca ASCII Code anjink biar ngerti apa yg gw ketik

void UpperCase (char &c){
	c = c - 32;
}

void LowerCase (char &c){
	c = c + 32;
}

int main(){
	string ch;
	cin >> ch;
	
	for (int i = 0; i < ch.size(); i++){
		if (ch[i] > 90){
			UpperCase (ch[i]);
		}
		else if (ch[i] <= 90){
			LowerCase (ch[i]);
		}
	}
	
	cout << ch << endl;
	
	return 0;
}