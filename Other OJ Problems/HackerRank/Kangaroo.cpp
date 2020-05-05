//HR kangaroo - Kangaroo

#include <bits/stdc++.h>

using namespace std;

string kangaroo(int x1, int v1, int x2, int v2) {
    int a=1;
    while(true){
        cout <<"Jump #" << a << "\tX1: " << x1 << "\t X2: " << x2 << '\n';
        if(x1 == x2)
            return "YES";
        if(v1 == v2)
            return "NO";
        if(x2 > x1 && v2 > v1)
            return "NO";
        if(x1 > x2 && v1 > v2)
            return "NO";
        x1+=v1;
        x2+=v2;
        a++;
    }
    return "NO";
}

int main() {
    int x1, x2, v1, v2;
    cin >> x1 >> v1 >> x2 >> v2;
    
    string result = kangaroo(x1, v1, x2, v2);
    cout << result << endl;
    return 0;
}
