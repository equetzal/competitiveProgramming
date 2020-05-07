#include <bits/stdc++.h>
using namespace std;



int D,N;
string s;

vector<vector<string> > ASD(1005,vector<string>(1005,"-1"));

string dp(int p , int m , string num)
{
   
    if(m == 0 && p == D)
    {
        ASD[p][m] = num;
        return num;
    }else if(m != 0 && p == D)
    {
        return "*";
    }
    if(ASD[p][m] != "-1")
        return ASD[p][m];
    ASD[p][m] = "";
    if(s[p] != '?')
    {
        int a = (((m*(10%N))%N)+((s[p]-'0')%N))%N;
        ASD[p][m] = dp(p+1 , a , num + s[p]);
        return ASD[p][m];
    }else
    {
        string aux;
        int a;
        for(int i = 0 ; i <= 9 ; i++)
        {
            if(p == 0 && i == 0)
                continue;
            int a = (((m*(10%N))%N)+(i%N))%N;
            aux = dp(p + 1 , a , num + to_string(i));
            if(aux != "*")
            {
                ASD[p][m] = aux;
                return aux;
                
            }
        }
        ASD[p][m] = "*";
        return ASD[p][m];
    }
}


int main(){
   ios::sync_with_stdio(false);
   cin.tie(0);

    cin >> s >> N;
    D = s.size();
    string ans = dp(0, 0 , "");
    if(ans != "*")
    {
        for(int i = ans.size() ; i < D ; i++)
            ans += "0";
    }
    cout << ans << endl;
    return 0;
}   
