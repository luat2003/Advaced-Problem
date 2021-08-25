#include <iostream>
#include <string.h>
#define N 1000001
int a[3] = {0};
using namespace std;

void dem( string s ){
    for( int i = 0; i < s.length(); i++){
        for( int k = 0; k <= 2; k++){
            if( s[i] - 'A' == k ){
                a[k]++;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    string x = s + s;
    dem(s);
    int Min = 99999999, Count[7] = {0};
    for( int i = 0; i < a[0]; i++){
        if( x[i] != 'A' ){
            Count[0]++;
        }
        if( x[i] == 'C' ){
            Count[4]++;
        }
        if( x[i] == 'B' ){
            Count[2]++;
        }
    }
    for( int i = a[0]; i < a[0]+a[1]; i++){
        if( x[i] != 'B' ){
            Count[1]++;
        }
        if( x[i] == 'A' ){
            Count[3]++;
        }
    }
    for( int i = a[0]; i < a[0]+a[2]; i++){
        if( x[i] != 'C' ){
            Count[5]++;
        }
        if( x[i] == 'A' ){
            Count[6]++;
        }
    }
    int s1 = Count[0]+Count[1]-min(Count[2],Count[3]);
    int s2 = Count[0]+Count[5]-min(Count[6], Count[4]);
    Min = min( Min, min(s1,s2));
    for( int j = 1; j < s.length(); j++){
        if( x[j-1] == 'A' ){
            Count[0]++;
        }else if( x[j-1] == 'B'){
            Count[2]--;
        }else{
            Count[4]--;
        }
        if( x[j+a[0]-1] == 'A'){
            Count[0]--;
            Count[3]--;
            Count[6]--;
        }else if( x[j+a[0]-1] == 'B'){
            Count[2]++;
            Count[1]++;
        }else{
            Count[4]++;
            Count[5]++;
        }
        if( x[j+a[0]+a[1]-1] == 'A'){
            Count[3]++;
        }else if( x[j+a[0]+a[1]-1] == 'B'){
            Count[1]--;
        }
        if( x[j+a[0]+a[2]-1] == 'A'){
            Count[6]++;
        }else if( x[j+a[0]+a[2]-1] == 'C'){
            Count[5]--;
        }
        int s1 = Count[0]+Count[1]-min(Count[2],Count[3]);
        int s2 = Count[0]+Count[5]-min(Count[6], Count[4]);
        Min = min( Min, min(s1,s2));
    }
    cout << Min;
    return 0;
}
