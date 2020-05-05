//LC 1244 - Design A Leaderboard

class Leaderboard {
public:
    map<int,int> score;
    set< pair<int,int> > topScores; //score,id
    
    Leaderboard() {
    }
    
    void addScore(int playerId, int toAdd) {
        topScores.erase(make_pair(score[playerId], playerId));
        score[playerId] += toAdd;
        topScores.insert(make_pair(score[playerId], playerId));
    }
    
    int top(int K) {
        int sum = 0;
        
        auto it=topScores.end();
        K--;
        
        do{
            it--;
            sum += (*it).first;
        }while(K--);
        
        return sum;
    }
    
    void reset(int playerId) {
        topScores.erase(make_pair(score[playerId], playerId));
        score[playerId] = 0;
        topScores.insert(make_pair(score[playerId], playerId));
    }
};
