#include <iostream>
#include<queue>
#include<stack>
using namespace std;
const int V = 8;
const int I = 32166;

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

void printPrimAlgolithm(int result[2][V-2]) {
	for(int i = 0; i < V-2; i++) {
		cout << result[0][i] << " - " << result[1][i] << endl;
	}
}

void PrimAlgolithm(int G[][V], int n) {
	int result[2][V-2];
	int near[n];
	for(int i = 0; i < n; i++) near[i] = I;
	int u, v; 
	int min = G[1][1];
	// find min edge
	for(int i = 1; i < n; i++) {
		for(int j = i+1; j < n; j++) {
			if(G[i][j] < min) {
				min = G[i][j];
				u = i; v = j;
			}
		}
	}
	result[0][0] = u;
	result[1][0] = v;
	near[u] = near[v] = 0;
	
	// loop
	for(int i = 1; i < V-2; i++) {
		for(int j = 1; j < n; j++) {
			
			if(near[j] != 0 && G[j][result[0][i-1]] < G[j][result[1][i-1]]) {
				near[j] = result[0][i-1];
			} else if (near[j] != 0){
				near[j] = result[1][i-1];
			}
		}
		
		min = I;
		for(int j = 1; j < n; j++) {
			if(near[j] != 0 && min > G[j][near[j]]) {
				min = G[j][near[j]];
				u = j; v = near[j];
			}
		}
		result[0][i] = u;
		result[1][i] = v;
		near[u] = near[v] = 0;
		
		for(int i = 1; i < n; i++) {
			if(near[i] != 0 && G[i][u] < G[i][near[u]]) near[i] = u;
		}
	}
	printPrimAlgolithm(result);
}





int main() {
	int G[V][V]={{0,0,0,0,0,0,0},
				{0,0,1,1,0,0,0},
				{0,1,0,0,1,0,0},
				{0,1,0,0,1,0,0},
				{0,0,1,1,0,1,1},
				{0,0,0,0,1,0,0},
				{0,0,0,0,1,0,0}};
//	BFS(G, V, 4);
//	DFS(G, V, 4);
	int cost [V][V] = {
            {I, I, I, I, I, I, I, I},
            {I, I, 25, I, I, I, 5, I},
            {I, 25, I, 12, I, I, I, 10},
            {I, I, 12, I, 8, I, I, I},
            {I, I, I, 8, I, 16, I, 14},
            {I, I, I, I, 16, I, 20, 18},
            {I, 5, I, I, I, 20, I, I},
            {I, I, 10, I, 14, 18, I, I},
    };
	PrimAlgolithm(cost,V);
	getchar();
	return 0;
}
