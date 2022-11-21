#include <iostream>
#include <string>

using namespace std;

void UpperCase (char &c){
	c = c - 32;
}

void LowerCase (char &c){
	c = c + 32;
}

int main()
{	
	for (int i = 0; i <= 255; i++){
		char ch = i;
		cout << ch << "------" << i << endl;
	}
	
	return 0;
}