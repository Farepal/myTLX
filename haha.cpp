#include <iostream>
#include <string>

using namespace std;

void LowerCase (char &c)
{
	c = c + 32;
}

void UpperCase (char &c)
{
	c = c - 32;
}

int main()
{
	string x;
	cin >> x;
	string n ("_");
	
	int len = x.size();
	
	bool check_ = false;
	
	for (int i = 0; i < len; i++)
	{
		if (x[i] == '_')
		{
			check_ = true;
		}
	}
	
	for (int i = 0; i < x.size(); i++)
	{
		if (check_)
		{	
			if (x[i] == '_')
			{
				x.erase (i, 1);
				UpperCase (x[i]);
			}
		}
		else 
		{
			if (x[i] <= 90 && i != 0){
				LowerCase (x[i]);
				x.insert(i, n);
			}
		}
	}
	
	cout << x << endl;
	
	return 0;
}