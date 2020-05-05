//LC 1245 - Tree Diameter

class Solution {
public:
    map< int,vector<int> > graph;
    int treeDiameter(vector<vector<int>>& edges) {
        for(auto v:edges){
            graph[v[0]].push_back(v[1]);
            graph[v[1]].push_back(v[0]);
        }
        
        int u = dfsNode(0,-1).second;
        return dfsNode(u,-1).first;
    }
    
    pair<int,int> dfsNode(int me, int father){
        pair<int,int> ans = make_pair(0,me);//deep, node
        
        for(auto u:graph[me]){
            if(u != father){
                auto res = dfsNode(u,me);
                if((res.first+1) > ans.first){
                    ans = res;
                    ans.first++;
                }
            }
        }
        return ans;
    }
};
