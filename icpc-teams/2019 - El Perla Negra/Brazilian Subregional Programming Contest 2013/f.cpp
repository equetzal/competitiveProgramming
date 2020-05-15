
 #include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int n; cin >> n;
    long long int currPos = 0;
    map<int, bool> point;
 
    for(int i=0; i<n; i++){
        int dist; cin >> dist;
        currPos += dist;
        point[currPos] = true;
    }
 
    int dist = currPos/3;
    int triangles = 0;
    for(int i=1; i<=dist; i++){
        if(point[i] && point[i+dist] && point[i+dist+dist])
            triangles++;
    }
 
    cout << triangles << endl;
}