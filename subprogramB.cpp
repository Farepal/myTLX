#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	int ar[n+1];
	int br[n+1];

	for (int i = 1; i <= n; i++){
		cin >> ar[i];
	}

	for (int i = 1; i <= n; i++){
		cin >> br[i];
	}

	int t;
	cin >> t;

	while (t--){
		char a, b;
		int x, y;
		cin >> a >> x >> b >> y;

		if (a == 'A' && b == 'B'){
			swap (ar[x], br[y]);
		}

		else if (a == 'A' && b == 'A'){
			swap (ar[x], ar[y]);
		}
		else if (a == 'B' && b == 'B'){
			swap (br[x], br[y]);
		}
		else if (a == 'B' && b == 'A'){
			swap (br[x], ar[y]);
		}
	}

	for (int i = 1; i <= n; i++){
		cout << ar[i];
		if (i == n) cout << endl;
		else cout << " ";
	}

	for (int i = 1; i <= n; i++){
		cout << br[i];
		if (i == n) cout << endl;
		else cout << " ";
	}

	return 0;
}