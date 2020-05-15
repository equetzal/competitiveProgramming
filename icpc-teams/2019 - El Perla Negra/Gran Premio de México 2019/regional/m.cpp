#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    int n,x;
    cin>>n>>x;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    int count = 0,mx = 1;
    int i = 1;
    while (i<n){
        if(nums[i]-nums[i-1]<=x){
            count =2;
            i++;
            while(nums[i]-nums[i-1]<=x && i<n){count++;i++;}
        }
        else i++;
        mx = max(count,mx);
        count = 0;
    }
    cout<<mx<<endl;
    return 0;
}