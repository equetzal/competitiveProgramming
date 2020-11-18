/* 
	Implement an Ordered Set data structure, that iterates in insertion order and has the following api:

	s = OrderedSet() // create new empty set
	s.add(1) // adds 1 to the set
	s.add(8) 
	s.add(3) 
	s.add(5) 
	s.remove(3) // removes 3 from the set
	s.contains(1) // returns whether 1 is contained in the set
	s.toArray() // returns 1 , 8, 5
*/

#include <bits/stdc++.h>

using namespace std;

class ordered_set{
  private:
	  unordered_map<long long int,list<long long int>::iterator> pos;
	  list<long long int> values;

  public:
	  ordered_set(){
	  }

	  void add(long long int val){
	    if(pos.count(val) < 1){
	      values.push_back(val);
	      auto it = values.end();
	      it--;
	      pos[val] = it;
	    }
	    return;
	  }

	  void remove(long long int val){
	    if(pos.count(val) > 0){
	      values.erase(pos[val]);
	      pos.erase(val);
	    }
	    return;
	  }

	  long long int count(long long int val){
	    return pos.count(val);
	  }

	  vector<long long int> toArray(){
	    vector<long long int> ans;
	    for(auto it=values.begin(); it != values.end(); it++){
	      ans.push_back(*it);
	    }
	    return ans;
	  }
};

int main(){
	ordered_set theSet();
	theSet.add(1);
	theSet.add(8);
	theSet.add(3);
	theSet.add(5);
	auto v = theSet.toArray();
	for(auto i:v)
		cout << i << " ";
	cout << endl;

	theSet.remove(3);
	theSet.add(3);
	v = theSet.toArray();
	for(auto i:v)
		cout << i << " ";
	cout << endl;

}

#include <bits/stdc++.h>

using namespace std;

class ordered_set {
 private:
  unordered_map<long long int, list<long long int>::iterator> pos;
  list<long long int> values;

 public:
  ordered_set() {}

  void add(long long int val) {
    if (pos.count(val) < 1) {
      values.push_back(val);
      auto it = values.end();
      pos[val] = --it;
    }
    return;
  }

  void remove(long long int val) {
    if (pos.count(val) > 0) {
      values.erase(pos[val]);
      pos.erase(val);
    }
    return;
  }

  long long int count(long long int val) { return pos.count(val); }

  vector<long long int> toArray() {
    vector<long long int> ans;
    for (auto it = values.begin(); it != values.end(); it++) {
      ans.push_back(*it);
    }
    return ans;
  }
};

int main() {
  ordered_set theSet();
  theSet.add(1);
  theSet.add(8);
  theSet.add(3);
  theSet.add(5);
  auto v = theSet.toArray();
  for (auto i : v) cout << i << " ";
  cout << endl;

  theSet.remove(3);
  theSet.add(3);
  v = theSet.toArray();
  for (auto i : v) cout << i << " ";
  cout << endl;
}
