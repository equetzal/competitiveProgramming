#include <iostream>
#include <set>
#include <map>
#include <utility>
#include <cmath>

typedef long long int lli;

using namespace std;

int main(){
    map<lli, pair<char,lli> > people;
    set<lli> alives;
    map<lli, lli> replace;
    lli id;

    lli n; cin >> n;
    for(id=1; id<=n; id++){
        char sex; cin >> sex; 
        people[id] = make_pair(sex, id);
        alives.insert(id);
    }

    lli query; cin >> query;
    while(query--){
        lli papa,mama; char sex;
        cin >> papa;
        if(papa < 0){
            alives.erase(-1*(papa));
        }else{
            cin >> mama >> sex;
            alives.insert(id);
            people[id] = {sex, people[mama].second};
            id++;
        }
    }

    lli k; cin >> k;

    while(k--){
        lli person, dna; cin >> person >> dna;
        replace[people[person].second] = dna;
    }

    set<lli> corrected;
    bool incongruences = false;
    for(lli p:alives){
        lli ancestor = people[p].second;
        if(replace.find(ancestor) == replace.end()){
            incongruences = true;
            corrected.insert(ancestor);
        }else{
            corrected.insert(replace[ancestor]);
        }
        
    }


    if(corrected.size() == 1){
        cout << "YES" << endl;
    }else{
        if(incongruences)
            cout << "POSSIBLY" << endl;
        else{
            cout << "NO" << endl;
        } 
        
    }
    
    return 0;
}