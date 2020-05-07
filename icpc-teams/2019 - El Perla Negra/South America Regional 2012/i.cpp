#include <bits/stdc++.h>

using namespace std;

struct node{
	char value;
	*node left;
	*node right;
}node;

int main(){
	int n,k; cin >> n >> k;

	vector<*node> arr(n);
	for(int i=0; i<n; i++){
		int temp; cin >> temp;
		*node element = memset(sizeof(node));
		element->value = temp;
		element->left = NULL;
		element->right = NULL;
		arr[i] = element;
	}

	return 0;
}

