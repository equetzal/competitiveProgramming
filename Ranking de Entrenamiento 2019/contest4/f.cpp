//CF ProblemSet 1003F - Abbreviation

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 310;
const int inf = 11111111;
int memo[MAXN][3];

int dp(int numComb, int n, int tam, int maxAns, vector<int> &ids, vector<int> &lens, vector<int> &wordId){
    for(int i=0; i<MAXN; i++){
        for(int j=0; j<3; j++){
            memo[i][j] = inf;
        }
    }

    memo[0][0] = 0;
    for(int i=0; i<n; i++)
        for(int j=0; j<3; j++){
            if(ids[i] == numComb){
                memo[min(i+tam,n)][min(j+1,2)] =
                    min(memo[min(i+tam,n)][min(j+1,2)], memo[i][j]+tam+1);
            }
            memo[i+1][j] = min(memo[i+1][j], memo[i][j]+1+lens[wordId[i]]);
        }

    return min(maxAns, memo[n][2]-1);
}

int main(){
    int n; cin >> n;
    vector<string> text(n);
    map<string,int> textId;
    vector<int> wordId(n);
    vector<int> lens;
    
    for(int i=0; i<n; i++)
        cin >> text[i];

    int id = 0;
    for(int i=0; i<n; i++){
        if(!textId.count(text[i])){
            textId[text[i]] = id;
            id++;
            lens.push_back(text[i].size());
        }

        wordId[i] = textId[text[i]];
    }

    //Respuesta Maxima
    int maxAns = n-1;
    for(int i=0; i<n; i++)
        maxAns += text[i].size();

    //Minimizar
    for(int tam=1; tam <= n/2; tam++){
        int combId = 0;
        map< vector<int>, int> combi;
        vector<int> combIds(n,-1);

        for(int i=0; i+tam-1<n; ++i){
            vector<int> tmp;

            for(int j=0; j<tam; j++){
                tmp.push_back(wordId[i+j]);
            }

            if(!combi.count(tmp)){
                combi[tmp] = combId++;
            }

            combIds[i] = combi[tmp];
        }

        for(int m=0; m<combId; m++){
            maxAns = dp(m, n, tam, maxAns, combIds, lens, wordId);
        }
    }

    cout << maxAns << endl;
    return 0;
}
