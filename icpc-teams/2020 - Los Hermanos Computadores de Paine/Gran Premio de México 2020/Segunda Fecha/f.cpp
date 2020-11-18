#include<bits/stdc++.h>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    long long int pl=0,pr=0, gl=0, gr=0;
    bool sacaizq=true;
    bool winner=false;
    bool firstLine=true;
    for(long long int i=0; i<s.length(); i++){

        if((pl>=5 and (pl-pr)>=2) or pl==10) { gl++; pl=0; pr=0;}
        if((pr>=5 and (pr-pl)>=2) or pr==10) { gr++; pl=0; pr=0;}
        if(s[i]=='S'){
            if(sacaizq) pl++;
            else pr++;
        }else if(s[i]=='R'){
            if(sacaizq) pr++;
            else pl++;
            sacaizq= (!sacaizq);
        }else{//Q
            if(gl>=2) cout<<((firstLine)?"":"\n") <<"2 (winner) - "<<gr;
            else if(gr>=2) cout<<((firstLine)?"":"\n")<<gl<<" - 2 (winner)";
            else
                cout<<((firstLine)?"":"\n")<<gl<<" ("<<pl<<((sacaizq)?"*)":")")<<" - "<<gr<<" ("<<pr<<((!sacaizq)?"*)":")");
            firstLine=false;
        }

    }

    return 0;
}
