/*
caesar cipher:
'abc', shift right 1 --> 'bcd'
'aaa', shift right 2 --> 'ccc'

  'z' -> shift right 1 --> 'a'

Group together words that can be encrypted to be exactly the same using Caesar cipher encryption.
  
Given a list of strings of all the same length, group together equivalent strings.
  
input: ['abc', 'bcd', 'acd', 'bde']
output: [['abc', 'bcd'], ['acd', 'bde']]

input: ['abc', 'bcd', 'acd', 'bde', 'cde']
output: [['abc', 'bcd', 'cde'], ['acd', 'bde']]
*/

int dif(char a, char b){
  if(a == 'z' && b == 'a'){
    return 1;
  }
    if(a-b < 0)
      return 26 - (a-b);
    
    return a-b;
}

map<vector<int>, vector<int>> groupShiftedStrings(vector<string> v){
  map<vector<int>, vector<int>> ans;
  
  for(int j=0; j<v.size(); j++){
    vector<int> id;
    //i = 0, i+1 = 1  0 < 3-2
    //i = 1, i+1 = 2  1 <= 3-2
    for(int i=0; i<=v[j].size()-2; i++){
      id.push_back(difs(v[j][i],v[j][i+1]));
    }
    ans[id].push_back(j);
  }
  
  return ans;  
}
