//AtCoder 4165 - Maximum Difference

#include <iostream>
#include <algorithm>
using namespace std;


int main() {
        
    int n, a[110];
    
    cin >> n;
    for(int i=0; i < n; i++)
        cin >> a[i];

    int maxdif = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            maxdif = max(maxdif, abs(a[i] - a[j]));
        }
    }
    cout << maxdif << "\n";
    return 0;
}
