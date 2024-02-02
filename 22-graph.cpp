#include <iostream>
#include<queue>
#include<stack>
using namespace std;
const int V = 7;
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
	int track[n];
	for(int i = 0; i < n; i++) track[i] = I;
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
	track[u] = track[v] = 0;
	
	// loop
	for(int i = 1; i < V-2; i++) {
		//update track
		for(int j = 1; j < n; j++) {
			
			if(track[j] != 0 && G[j][result[0][i-1]] < G[j][result[1][i-1]]) {
				track[j] = result[0][i-1];
			} else if (track[j] != 0){
				track[j] = result[1][i-1];
			}
		}
		
		min = I;
		for(int j = 1; j < n; j++) {
			if(track[j] != 0 && min > G[j][track[j]]) {
				min = G[j][track[j]];
				u = j; v = track[j];
			}
		}
		result[0][i] = u;
		result[1][i] = v;
		track[u] = track[v] = 0;
	}
	printPrimAlgolithm(result);
}

void merge(int* arr, int u, int v) {
	if(u > v) {
		arr[u] += arr[v];
		arr[v] = u;
	} else {
		arr[v] += arr[u];
		arr[u] = v;
	}
}

int findParent(int* arr, int u) {
	int x = u;
	while(arr[x] >0) {
		x = arr[x];
	}
	return x;
}

void KruskalAlgolithm(int edges[3][9], int n) {
	int result[2][n-1]; // n-1 = number of edges
	int check[n]; // n = number of vertex
	int included[9]; // 9 = number of edges full graph
	for(int i = 0; i < 9; i++) included[i] = 0;
	for(int i = 0; i < n; i++) check[i] = -1;
	
	int u, v, k, i = 0;
	while(i < n-1) {
		int min = I;
		for(int j = 0; j < 9; j++) {
			if(included[j]==0 && edges[2][j] < min) {
				min = edges[2][j];
				u = edges[0][j];
				v = edges[1][j];
				k = j;
			}
		}
		included[k] = 1;
		if(findParent(check, u) != findParent(check, v)) {
			merge(check, findParent(check, u), findParent(check, v));
			result[0][i] = u;
			result[1][i] = v;
			i++; 
		}
	}
	
	//print
	for(int i = 0; i < n-1; i++) {
		cout << result[0][i] << " - " << result[1][i] << endl;
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
//	BFS(G, V, 4);
//	DFS(G, V, 4);
//	int cost [V][V] = {
//            {I, I, I, I, I, I, I, I},
//            {I, I, 25, I, I, I, 5, I},
//            {I, 25, I, 12, I, I, I, 10},
//            {I, I, 12, I, 8, I, I, I},
//            {I, I, I, 8, I, 16, I, 14},
//            {I, I, I, I, 16, I, 20, 18},
//            {I, 5, I, I, I, 20, I, I},
//            {I, I, 10, I, 14, 18, I, I},
//    };
//	PrimAlgolithm(cost,V);

	int edges [3][9] = {
            {1, 1, 2, 2, 3, 4, 4, 5, 5},
            {2, 6, 3, 7, 4, 5, 7, 6, 7},
            {25, 5, 12, 10, 8, 16, 14, 20, 18}
    };
    KruskalAlgolithm(edges, V);
	getchar();
	return 0;
}
