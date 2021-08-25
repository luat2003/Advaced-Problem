#include <bits/stdc++.h>
#include <string.h>
#include <math.h>
#include <string>
#define N 10005
using namespace std;
string a, b;
int l1;
double tichLonNhat(string s)
{
    double t = 0;
    for( int i = 0; i < s.length(); i++){
        if( s[i] == '0' ){
            t = -1;
            break;
        }
        t += log2(s[i]-'0');
    }
    return t;
}


string soCoTichLonNhat(string a, string b)
{
    string kq = b;
    for (int i = 0; i < b.length(); i++) {
        if (b[i] == '0'){
            continue;
        }
        string s = b;
        s[i] = ((s[i] - '0') - 1) + '0';
        for (int j = i + 1; j < s.length(); j++){
            s[j] = '9';
        }
        while( s[0] == '0' ){
            s.erase(0,1);
        }
        if(  (s.length() > l1 || (s.length() == l1 && s >= a) ) && (tichLonNhat(kq) < tichLonNhat(s)) ){
            kq = s;
        }
    }
    return kq;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b;
    if( a.length() == b.length() ){
        l1 = a.length();
    }else{
        l1 = b.length()-1;
    }
    cout << soCoTichLonNhat(a, b) << endl;
    return 0;
}
