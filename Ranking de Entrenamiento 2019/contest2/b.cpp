//Wiki Lists - CF Gym 101252K

#include <bits/stdc++.h> 
 
using namespace std;
 
string tag(char item, bool open, int pos){
	string ans;
	
	if(open && pos)
		ans += "<li>\n";
	if(item == '#')
		if(open)
			ans += "<ol>\n";
		else
			ans += "</ol>\n";
	else
		if(open)
			ans += "<ul>\n";
		else
			ans += "</ul>\n";
	if(!open && pos)
		ans += "</li>\n";
	
	return ans;
}
 
void toHTML(vector<string> &wikiText, int line, int limit, int pos){
	while(line <= limit){
		if(wikiText[line][pos] != '#' && wikiText[line][pos] != '*'){
			if(pos == 0){
				cout << wikiText[line].c_str() << endl;
			}else{
				cout << "<li>\n" << wikiText[line].substr(pos,wikiText[line].size()).c_str() << '\n' << "</li>\n";
			}
			line++;
			continue;
		}
		
		int nextLimit = line+1;
		bool isAList = false;
		for(;nextLimit <= limit;nextLimit++){
			if(wikiText[nextLimit][pos] == wikiText[line][pos]){ //Checa la ultima linea que pertenece a la misma lista
				isAList = true;
			}
			else
				break;
		}
		nextLimit--;
		
		if(isAList){
			cout << tag(wikiText[line][pos], true, pos).c_str();
			toHTML(wikiText, line, nextLimit, pos+1);
			cout << tag(wikiText[line][pos], false, pos).c_str();
			line = nextLimit+1;
		}else{
			if(!pos){
				cout << wikiText[line].c_str() << endl;
			}else{
				cout << "<li>\n" << wikiText[line].substr(pos,wikiText[line].size()).c_str() << '\n' << "</li>\n";
			}
			line++;
		}
	}
}
 
int main(){
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	
	vector<string> wikiText;
	string s; int mx = -1;
	while(cin >> s){
		wikiText.push_back(s);
		mx = max(mx,(int)s.size());
	}
	
	for(int i=0; i<wikiText.size(); i++){
		wikiText[i].resize(mx+1,'\0');
	}
 
	toHTML(wikiText, 0, wikiText.size()-1, 0);
 
	return 0;
}
