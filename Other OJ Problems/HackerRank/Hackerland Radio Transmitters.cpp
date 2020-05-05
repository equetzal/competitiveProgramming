//HR hackerland-radio-transmitters - Hackerland Radio Transmitters

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <utility>

using namespace std;


int main(){
    int n, k, temp;
    cin >> n >> k;

    priority_queue <int> Q; 
    pair <int, bool> PC;
    pair <int, int> PA;

    for(int i = 0; i < n; i++){
       cin >> temp;
       Q.push(temp);
    }

    for(int i=0; i<n; i++){
    	cout << Q.top() << " ";
    	Q.pop();
    }

    cout << endl;


    return 0;
}
