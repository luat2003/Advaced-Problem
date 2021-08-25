#include <iostream>

using namespace std;

int main()
{
    long long n, m, i, j;
    cin >> n >> m;
    long long s[n+2] = {0}, l[m], r[m], v[m];
    for( i = 0; i < m; i++){
        cin >> l[i] >>  r[i] >> v[i];
        s[l[i]] += v[i];
        s[r[i]+1] -= v[i];
    }
    long long S[n+2] = {0};
    for(i = 1; i <= n; i++){
        S[i] = S[i-1]+s[i];
    }
    for( i = 1; i <= n; i++){
        cout << S[i] << " ";
    }
    return 0;
}
