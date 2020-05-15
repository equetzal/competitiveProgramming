#include <bits/Stdc++.h>
using namespace std;
int main(){
    int n;
    vector<string> names(n);
    for(int i = 0;i<n;i++)
        cin>>names[i];
    for(int i = 0;i<n-1;i++){
        int j = 0;
        while(names[i][j] == names[i+1][j]&&j<min(names[i].size(),names[i+1].size()){
            j++;
        }
        if(names[i+1][j]>names[i])continue;
        else quit(names[i]);

    }
    cout<<a<b;
    return 0;
}