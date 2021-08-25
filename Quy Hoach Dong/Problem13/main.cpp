#include <bits/stdc++.h>
#define N 5005
using namespace std;
int n, kt[N][N] = {0}, dp[N][N];
string s;

int xauConChungDaiNhat( int k, int l){ // Tìm xâu con chung dài nhất với xâu nghịch đảo
    if( k == -1 || l == -1){
        return 0;
    }
    if( k >= l ){
        kt[k+1][l+1] = 1;
        dp[k+1][l+1] = 0;
        return 0;
    }
    if( kt[k+1][l+1] ){
        return dp[k+1][l+1];
    }
    int maxx = 0;
    if( s[k] == s[l]){
        maxx = xauConChungDaiNhat(k+1,l-1);
    }else{
        maxx = 1+min(xauConChungDaiNhat(k+1,l), xauConChungDaiNhat(k,l-1));
    }
    kt[k+1][l+1] = 1;
    dp[k+1][l+1] = maxx;
    return maxx;

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> s;
    cout << xauConChungDaiNhat(0,n-1);
    return 0;
}
