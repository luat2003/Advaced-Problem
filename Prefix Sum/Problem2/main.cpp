#include <iostream>

using namespace std;

int main()
{
    long long n, m, i, j;
    cin >> n >> m;
    long long s[n+2] = {0}, l[m], r[m], x[m], y[m], s2[n+2] = {0}, s3[n+2] = {0};
    for( i = 0; i < m; i++){
        cin >> l[i] >>  r[i] >> x[i] >> y[i];
        s[l[i]] += x[i]-l[i]*y[i];
        s[r[i]+1] -= x[i]-l[i]*y[i];
        s2[l[i]] += y[i];
        s2[r[i]+1] -= y[i];
    }
    long long S2[n+2] = {0};
    for(i = 1; i <= n; i++){
        s2[i] = s2[i]+s2[i-1];
    }
    for(i = 1; i <= n; i++){
        S2[i] = s2[i]*i;
    }

    long long S[n+2] = {0};
    for(i = 1; i <= n; i++){
        S[i] = S[i-1]+s[i];
    }
    for( i = 1; i <= n; i++){
        cout << S2[i]+S[i]<< " ";
    }
    return 0;
}
