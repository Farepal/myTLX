#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
int k, n;
int w[101], h[101], dp[101][2001] = {0};

int main(){
	cin >> n >> k;
	for (int i = 1; i <= k; i++)
		cin >> w[i] >> h[i];
	
	for (int i = 1; i <= k; i++){
		for (int j = 1; j <= n; j++){
			dp[i][j] = dp[i - 1][j];
			if (j >= w[i])
				dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + h[i]);
		}
	}

	int res = dp[k][n];
	int we;
	for (int i = 0; i <= n; i++){
		if (res == dp[k][i]){
			we = i;
			break;
		}
	}
	stack <int> has;
	for (int i = k; i > 0 && res != 0; i--){
		if (res != dp[i - 1][we]){
			has.push(i);
			we = we - w[i];
			res = res - h[i];
		}
	}

	while (!has.empty()){
		cout << has.top() << endl;
		has.pop();
	}

	return 0;
}