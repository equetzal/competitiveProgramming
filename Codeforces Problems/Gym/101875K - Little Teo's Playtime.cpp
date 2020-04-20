//CF Gym 101875K - Little Teo's Playtime

#include <bits/stdc++.h>

using namespace std;

struct node{
	int value; //Longest Sequence Same Color
	int size;
	pair<int,int> prefix, suffix; //Color, Size
	//int lo,hi;
	node *left, *right;
};

node* mergeSnakes(node* snakeLeft, node* snakeRight){
	node* newSnake = (struct node*)malloc(sizeof(struct node));
	
	newSnake->size = snakeLeft->size + snakeRight->size;
	newSnake->value = max(snakeLeft->value, snakeRight->value);
	newSnake->prefix = snakeLeft->prefix;
	newSnake->suffix = snakeRight->suffix;
	newSnake->left = snakeLeft;
	newSnake->right = snakeRight;
	
	if(snakeLeft->suffix.first == snakeRight->prefix.first){
		newSnake->value = max(newSnake->value, snakeLeft->suffix.second + snakeRight->prefix.second);
		
		if(snakeLeft->prefix.second == snakeLeft->size){
			newSnake->prefix.second += snakeRight->prefix.second;
		}
		
		if(snakeRight->suffix.second == snakeRight->size){
			newSnake->suffix.second += snakeLeft->suffix.second;
		}
	}
	
	return newSnake;
}

int getColor(int i, node* snake){
	if(snake->size == 1)
		return snake->prefix.first;
	
	int mid = snake->size / 2;
	if(i<mid) //Left
		return getColor(i,snake->left);
	else
		return getColor(i-mid, snake->right);
}

void updateColor(int i, int color, node* snake){
	if(snake->size == 1){
		snake->prefix.first = color;
		snake->suffix.first = color;
		return;
	}
	
	int mid = snake->size / 2;
	if(i<mid) //Left
		updateColor(i, color,snake->left);
	else
		updateColor(i-mid, color, snake->right);
	
	
	snake->value = max(snake->left->value, snake->right->value);
	snake->prefix = snake->left->prefix;
	snake->suffix = snake->right->suffix;
	if(snake->left->suffix.first == snake->right->prefix.first){
		snake->value = max(snake->value, snake->left->suffix.second + snake->right->prefix.second);
		
		if(snake->left->prefix.second == snake->left->size){
			snake->prefix.second += snake->right->prefix.second;
		}
		
		if(snake->right->suffix.second == snake->right->size){
			snake->suffix.second += snake->left->suffix.second;
		}
	}
	
	return;
}

pair<node*,node*> splitSnake(node* snake){
	pair<node*,node*> snakes;
	snakes.first = snake->left;
	snakes.second = snake->right;
	return snakes;
}

node* reduxSnake(vector<node*> segmentOfSnake){
	if(segmentOfSnake.size() == 1){
		return segmentOfSnake[0];
	}
	
	vector<node*> newSnake;
	for(int i=0; i<segmentOfSnake.size(); i+=2){
		newSnake.push_back(mergeSnakes(segmentOfSnake[i], segmentOfSnake[i+1]));
	}
	
	return reduxSnake(newSnake);
}

int main(){
	int n,q; cin >> n >> q;
	vector<node*> snake;

	for(int i=0; i<n; i++){
		int sizeSnake; cin >> sizeSnake;
		
		vector<node*> segmentOfSnake;
		for(int j=0; j<sizeSnake; j++){
			int color; cin >> color;
			
			node* temp = (struct node*)malloc(sizeof(struct node));
			temp->value = 1;
			temp->size = 1;
			temp->prefix = make_pair(color,1);
			temp->suffix = make_pair(color,1);
			temp->left = NULL;
			temp->right = NULL;
			segmentOfSnake.push_back(temp);
		}
		
		snake.push_back(reduxSnake(segmentOfSnake));
	}
	
	for(int i=0; i<q; i++){
		int op; cin >> op;
		
		switch(op){
			case 1:{
				int x,y,z; cin >> x >> y >> z;
				x--; y--; z--;
				
				int a = getColor(x,snake[z]);
				int b = getColor(y,snake[z]);
				
				updateColor(x,b,snake[z]);
				updateColor(y,a,snake[z]);
			}break;
			
			case 2:{
				int l,r; cin >> l >> r; 
				l--; r--;
				snake.push_back(mergeSnakes(snake[l], snake[r]));
			}break;
			
			case 3:{
				int z; cin >> z;
				z--;
				auto newSnakes = splitSnake(snake[z]);
				snake.push_back(newSnakes.first);
				snake.push_back(newSnakes.second);
			}break;
			
			case 4:{
				int z; cin >> z;
				z--;
				cout << snake[z]->value << endl;
			}break;
			
			case 5:{
				int z; cin >> z; z--;
				cout << "---Tree---" << endl;
				for(int j=0; j<snake[z]->size; j++)
					cout << getColor(j,snake[z]) << " ";
				cout << endl << "----------" << endl;
			}break;
		}
	}
	
	return 0;
}
