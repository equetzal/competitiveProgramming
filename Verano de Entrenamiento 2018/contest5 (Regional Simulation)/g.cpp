//CF Gym 100753G - Extreme Sort

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, a[2000];
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int mindif = 1e9;
    for (int i = 0; i < n - 1; i++) {
        mindif = min(mindif, a[i + 1] - a[i]);
    }
    if (mindif >= 0)
        cout << "yes\n";
    else
        cout << "no\n";
    return 0;
}
