//Checkpoints - CF ProblemSet 709B

#include <bits/stdc++.h>
 
using namespace std;
 
int distMin(vector<int> &checkpoints, int low, int high, int pos){
	int dist = abs(checkpoints[high] - checkpoints[low]);
	
	if(dist == 0){
		return abs(checkpoints[low] - pos);
	}
	if(pos <= checkpoints[low]){
		return abs(checkpoints[high]-pos);
	}
	if(pos >= checkpoints[high]){
		return abs(pos-checkpoints[low]);
	}
 
	if(abs(pos-checkpoints[low]) == abs(checkpoints[high]-pos)){
		return abs(pos-checkpoints[low])+dist;
	}
	if(abs(pos-checkpoints[low]) < abs(checkpoints[high]-pos)){
		return abs(pos-checkpoints[low])+dist;
	}
	
	return abs(checkpoints[high]-pos)+dist;
	
}
 
const int N = 1e5 + 100;
int arr[N];
 
int main(){
	 int n,a;
    scanf("%d%d",&n,&a);
    for(int i=0;i<n;i++)  scanf("%d",&arr[i]);
    sort(arr,arr+n);
    if (n==1) {
        cout << 0 << endl;
        return 0;
    }
    int ans1,ans2;
    int tmp1=arr[1], tmp2=arr[n-1];
    ans1 = tmp2-tmp1+min(abs(tmp1-a),abs(tmp2-a));
 
    tmp1=arr[0], tmp2=arr[n-2];
    ans2 = tmp2-tmp1+min(abs(tmp1-a),abs(tmp2-a));
 
    cout << min(ans1,ans2) << endl;
    return 0;
}
