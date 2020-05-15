#include <bits/stdc++.h>

using namespace std;

int m;
vector<int> res;

vector <int> cutCinta(int pos, vector<int> &cinta){
    vector<int> ans;
    if(pos < cinta.size()/2){
        int ini = pos*2-1;
        for(int i=cinta.size()-1; i>ini; i--){
            ans.push_back(cinta[i]);
        }
        for(int i=0, j=ini; i<=pos && i<j; i++, j--){
            ans.push_back(cinta[i]+cinta[j]);
        }
    }else if(pos == cinta.size()/2){
        for(int i=0, j=cinta.size()-1; i<=pos && i<j; i++, j--){
            ans.push_back(cinta[i]+cinta[j]);
        }
    }else{
        for(int i=0; i<(cinta.size()-(cinta.size()-pos)*2); i++){
            ans.push_back(cinta[i]);
        }
        for(int i=(cinta.size()-(cinta.size()-pos)*2), j=cinta.size()-1; i<cinta.size() && i<j; i++, j--){
            ans.push_back(cinta[i]+cinta[j]);
        }
    }
    return ans;
}

bool isSame(vector<int> cinta){
    if(cinta == res)
        return true;
    reverse(cinta.begin(), cinta.end());
    if(cinta == res)
        return true;
    return false;
}

bool corta(vector<int> &cinta){
    if(isSame(cinta))
        return true;
    for(int i=1; i<cinta.size(); i++){
        vector<int> hijo = cutCinta(i, cinta);
        if(hijo.size() >= m){
            if(corta(hijo))
                return true;
        }
    }
    return false;
}

int main(){
    int n; cin >> n;
    vector<int> cintaOriginal(n);
    for(int i=0; i<n; i++){
        cin >> cintaOriginal[i];
    }
    cin >> m;
    for(int i=0; i<m; i++){
        int temp; cin >> temp;
        res.push_back(temp);
    }
    
    if(corta(cintaOriginal))
        cout << "S" << endl;
    else
        cout << "N" << endl;

    return 0;
}