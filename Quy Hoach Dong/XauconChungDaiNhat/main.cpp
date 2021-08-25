#include <bits/stdc++.h>
#define N 2005
using namespace std;
int dp[N][N];
string a, b;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b;
    int a1 = a.size();
    int b1 = b.size();
    for( int i = 0; i <= a1-1; i++){
        for( int j = 0; j <= b1-1; j++){
            if( a[i] == b[j] ){
                dp[i+1][j+1] = dp[i][j]+1;
            }else{
                dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
            }
        }
    }
    cout << dp[a1][b1];
    return 0;
}
