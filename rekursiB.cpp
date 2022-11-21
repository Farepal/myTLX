#include <iostream>

using namespace std;

//faktorial ganjil genap
//contoh f(5) = 5 * 4/2 * 3 * 2/2 * 1

int fgg (int n){
	if (n == 1)
	{
		return n;
	}
	else if (n % 2 == 0)
	{
		return n / 2 * fgg(n-1);
	}
	else 
	{
		return n * fgg(n-1);
	}
}

int main()
{
	int  x;
	cin >> x;
	
	cout << fgg (x) << endl;
	
	return 0;
}