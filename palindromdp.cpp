#include <iostream>//input output
#include <string>//string nya
#include <algorithm>//max
#include <cstring>//memset

using namespace std;

int main(){
    int n;
    cin >> n;
    while (n--){
        string s;
        cin >> s;
        int len = s.length();
        s = '$' + s;
        //dp[akhir][akhir]
        int dp[len+1][len+1];
        memset (dp, 0, sizeof (dp[0][0]) * (len + 1) * (len + 1));
        for (int i = 1; i <= len; i++)
            dp[i][i] = 1;
        for (int i = 1; i <= len-1; i++){
            for (int j = 1; (j + i) <= len; j++){
                if (s[j] == s[i+j])
                    dp[j][i+j] = 2 + dp[j+1][i+j-1];
                else
                    dp[j][i+j] = max (dp[j+1][i+j], dp[j][i+j-1]);
            }
        }
        cout << dp[1][len] << endl;
    }
    return 0;
}
