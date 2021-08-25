#include <iostream>

using namespace std;

void binary( int n, string s){
    if( n == 0 ){
        cout << s << "\n";
        return;
    }
    binary(n-1, s + "0");
    binary(n-1, s + "1");
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    binary(n, "");
}
