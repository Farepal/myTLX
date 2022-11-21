#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> memo;

int solve (int res){
    if (memo[res] != -1)
        return memo[res];
    memo[res] = max (res, solve (res/2) + solve (res/3) + solve (res/4));
    return memo[res];
}

int main(){
    int n;
    cin >> n;
    for (int i = 0; i <= 10; i++)
        memo.push_back (i);
    memo.resize (n + 1, -1);
    cout << solve (n) << endl;
    return 0;
}
