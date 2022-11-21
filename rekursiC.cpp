#include <iostream>

using namespace std;

int abs(int x)
{
	if (x < 0)
	{
		return -x;
	}
	else
	{
		return x;
	}
}

int kf2 (int a, int b, int k, int x)
{
	if (k == 1)
	{
		return abs (a * x + b);
	}
	else
	{
		return kf2(a, b, k-1, abs(a * x + b));
	}
	//misal 2,5,3,4
	//k == 3 x=4 mereturn ax+b atau 13
	//k = 2 x= 13 mereturn a*13+b atau 31
	//k=1 x = 31 mereturn a*31+b atau 2*31+5 = 62+5 = 67
}

int main()
{
	int a, b, k, x;
	cin >> a >> b >> k >> x;
	cout << kf2(a, b, k, x) << endl;
	return 0;
}