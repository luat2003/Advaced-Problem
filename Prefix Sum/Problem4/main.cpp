#include <iostream>
#include <string>
#include <string.h>
using namespace std;

long long a[1000010], sa[1000100], sb[1000100],  dem[2000200];

void kt(string s){
    int i, l = s.length();
    for( i = 0; i < l; i++){
        if( s[i] == 'a'){
            a[i] = 1;
        }else{
            a[i] = 0;
        }
    }
}

int main()
{
    string s;
    long long n, i, j, l, countt = 0, k;
    cin >> n;
    cin >> s;
    kt(s);
    sa[0] = 0;
    sb[0] = 0;
    for( i = 1; i <= n; i++){
        sa[i] = sa[i-1]+a[i-1];
        sb[i] = i-sa[i];
    }
    for( i = 0; i <= 2*n; i++){
        dem[i] = 0;
    }
    dem[n] = 1;
    for( i = 1; i <= n; i++){
        long long t = n + (sa[i]-sb[i]);
        countt += dem[t];
        dem[t]++;
    }
    cout << countt;
    return 0;
}
