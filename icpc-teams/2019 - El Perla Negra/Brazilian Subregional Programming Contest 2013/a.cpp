#include <bits/stdc++.h>

using namespace std;

int main(){
    bool a,b,c; cin >> a >> b >> c;

    if(a && !b && !c)
        cout << 'A';
    else if(!a && b && !c)
        cout << 'B';
    else if(!a && !b && c)
        cout << 'C';
    else if(!a && b && c)
        cout << 'A';
    else if(a && !b && c)
        cout << 'B';
    else if(a && b && !c)
        cout << 'C';
    else
        cout << '*';

    cout << endl;
    

}