/*
	Given a short string S and a dictionary D, find out all possible ways to split S using words in D.

	S = 'abcd' D = ['a', 'b', 'ab', 'cd'] -> ['a b cd', 'ab cd']
	S = 'aaa' D = ['a'] -> ['a a a']
	S = 'abcd' D = ['ab'] -> []
	S = 'abcd' D = ['abcd'] -> ['abcd']

	-- Out of Statement --

	Important Notes:
		Only lowercase english letters
		If is not possible then output is empty []

	Solutions Ideas:
		Look for all the possibilities and try them with a dfs.
*/

void dfs(vector<string> &dictionary, string &s, int positionInS, vector<int> &indexInDictionaryTaken, vector<string> &answer){
	if(positionInS >= S.size()){
		string possibleAnswer;
		for(auto idx:indexInDictionaryTaken){
			possibleAnswer += dictionary[idx];
			possibleAnswer += " ";
		}
		possibleAnswer.pop_back();
		answer.push_back(possibleAnswer);
		return;
	}

	for(int i=0; i<dictionary.size(); i++){
		if(dictionary[i].size() > 0 && s[positionInS] == dictionary[i][0]){
			bool isMatch = true;
			for(int j=0, k=positionInS; j<dictionary[i].size() && k<s.size(); j++, k++){
				if(s[k] != dictionary[i][j])
					isMatch = fase;
			}

			if(isMatch){
				indexInDictionaryTaken.push_back(i);
				dfs(dictionary, s, positionInS + dictionary[i].size(); indexInDictionaryTaken, answer);
				indexInDictionaryTaken.pop_back();
			}
		}
	}

	return;
}

vector<string> lookForAllPossibleStrings(vector<string> &dictionary, string &s){
	vector<string> answer;
	vector<int> indexInDictionaryTaken;
	dfs(dictionary, s, 0, indexInDictionaryTaken, answer);
	return answer;
}