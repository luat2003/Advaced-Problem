#include <iostream>
#include <string.h>
#include <string>
#define N 10005
using namespace std;
int dem, kt[N][30], n, dp[N][30];
string s;
char sett;

int soBuocNhoNhat( int k, char sett ){
    if( k == n ){
        return 0;
    }
    if( kt[k][sett - 'A'] ){
        return dp[k][sett -'A'];
    }
    if( s[k] == sett ){
        kt[k][sett- 'A'] = 1;
        dp[k][sett - 'A'] = soBuocNhoNhat(k+1, sett);
        return dp[k][sett - 'A'];
    }
    kt[k][sett- 'A'] = 1;
    dp[k][sett-'A'] = min( soBuocNhoNhat(k+1, s[k] ) + 1, soBuocNhoNhat(k+1, sett) + 1);
    return dp[k][sett - 'A'];
}
int main()
{
    cin >> s;
    n = s.length();
    sett = s[0];
    cout << n+1 + soBuocNhoNhat(0, sett);
    return 0;
}
