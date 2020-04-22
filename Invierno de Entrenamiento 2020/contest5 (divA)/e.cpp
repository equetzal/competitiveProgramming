//CF ProblemSet 778A - String Game

#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
#define MAXN 200010

bool isPossible(lli mid, string &s, string &p, vector<int> &ord){
    vector<bool> visited(MAXN,false);
    lli count = 0;

    for(lli i=0; i<= mid; i++){
        visited[ord[i]-1]= true;
    }

    for(lli i=0; i<s.size(); i++){
        if(visited[i])
            continue;
        if(s[i]  == p[count])
            count++;
        if(count == p.size())
            return true;
    }
    return false;
}


int main(){
    string s,p; cin >> s >> p;
    vector<int> ord(s.size());
    for(auto &x:ord){
        cin >> x;
    }

    lli lo = 0, hi = s.size()-1, mid;
    while(lo <= hi){
        mid = (lo+hi)/2;
        if(isPossible(mid,s,p,ord)){
            lo = mid+1;
        }else{
            hi = mid-1;
        }

        if(lo > hi){
            if(hi == mid)
                cout << mid+1 << endl;
            if(lo == mid)
                cout << mid << endl;
            break;
        }
    }    


}
