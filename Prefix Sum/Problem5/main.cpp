#include <iostream>
#include <string>
#include <string.h>
using namespace std;

long long a[1000010], sa[1000100],  dem[2000200];

void kt(string s){
    int i, l = s.length();
    for( i = 0; i < l; i++){
        if( s[i] == '('){
            a[i] = 1;
        }else{
            a[i] = -1;
        }
    }
}

int main()
{
    string s;
    cin >> s;
    long long n = s.length(), i, countt = 0, j;
    kt(s);
    sa[0] = 0;
    for( i = 1; i <= n; i++){
        sa[i] = sa[i-1]+a[i-1];
        for( j = i-1; j >= 0; j--){
            if( sa[j] < sa[i] ){
                break;
            }
            if( sa[j] == sa[i] ){
                countt++;
            }
        }
    }
    cout << countt;
    return 0;
}
