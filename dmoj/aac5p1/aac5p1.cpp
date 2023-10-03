#include <bits/stdc++.h>
using namespace std;

int n;
int numEven, numOdd;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(a % 2 == 1) numOdd++;
        else numEven++;
    }
    cout << numOdd/2 + numEven/2 << '\n';
}
