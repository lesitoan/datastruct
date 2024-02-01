#include <iostream>
#include<queue>
#include<stack>
using namespace std;
const int V = 7;

void BFS(int A[][V], int n, int start) {
	queue<int> que;
	int visited[V] = {0};
	que.push(start);
	cout << start << "\t";
	visited[start] = 1;
	
	while(!que.empty()) {
		int vertex = que.front();
		que.pop();
		for(int i = 1; i < n; i++) {
			if(visited[i] == 0 && A[vertex][i] != 0){
				cout << i << "\t";
				visited[i] = 1;
				que.push(i);
			}
		}
		
	}
	cout << endl;
}

void DFS(int A[][V], int n, int start) {
	stack<int> st;
	static int visited[V] = {0};
	st.push(start);
	cout << start << "\t";
	visited[start] = 1;
	while(!st.empty()) {
		int vertex = st.top();
		st.pop();
		for(int i = 1; i < n; i++) {
			if(visited[i] == 0 && A[vertex][i] != 0){
				DFS(A, n, i);
				
			}
		}
	}
}


int main() {
	int G[V][V]={{0,0,0,0,0,0,0},
				{0,0,1,1,0,0,0},
				{0,1,0,0,1,0,0},
				{0,1,0,0,1,0,0},
				{0,0,1,1,0,1,1},
				{0,0,0,0,1,0,0},
				{0,0,0,0,1,0,0}};
	BFS(G, V, 4);
	DFS(G, V, 4);
	getchar();
	return 0;
}
