// C++ program to find winner of the match 
#include <bits/stdc++.h> 
using namespace std; 

// Function to add edge between two nodes 
void add(vector<int> adj[], int u, int v) 
{ 
	adj[u].push_back(v); 
} 

// Function returns topological order of given graph 
vector<int> topo(vector<int> adj[], int n) 
{ 
	// Indeg vector will store 
	// indegrees of all vertices 
	vector<int> indeg(n, 0); 
	for (int i = 0; i < n; i++) { 
		for (auto x : adj[i]) 
			indeg[x]++; 
	} 
	// Answer vector will have our 
	// final topological order 
	vector<int> answer; 

	// Visited will be true if that 
	// vertex has been visited 
	vector<bool> visited(n, false); 

	// q will store the vertices 
	// that have indegree equal to zero 
	queue<int> q; 
	for (int i = 0; i < n; i++) { 
		if (indeg[i] == 0) { 
			q.push(i); 
			visited[i] = true; 
		} 
	} 

	// Iterate till queue is not empty 
	while (!q.empty()) { 
		int u = q.front(); 
		// Push the front of queue to answer 
		answer.push_back(u); 
		q.pop(); 

		// For all neighbours of u, decrement 
		// their indegree value 
		for (auto x : adj[u]) { 
			indeg[x]--; 

			// If indegree of any vertex becomes zero and 
			// it is not marked then push it to queue 
			if (indeg[x] == 0 && !visited[x]) { 
				q.push(x); 
				// Mark this vertex as visited 
				visited[x] = true; 
			} 
		} 
	} 

	// Return the resultant topological order 
	return answer; 
} 
// Function to return the winner between u and v 
int who_wins(vector<int> topotable, int u, int v) 
{ 
	// Player who comes first wins 
	for (auto x : topotable) { 
		if (x == u) 
			return u; 
		if (x == v) 
			return v; 
	} 
} 

// Driver code 
int main() 
{ 
	vector<int> adj[10]; 

	// Total number of players 
	int n = 7; 

	// Build the graph 
	// add(adj, x, y) means x wins over y 
	add(adj, 0, 1); 
	add(adj, 0, 2); 
	add(adj, 0, 3); 
	add(adj, 1, 5); 
	add(adj, 2, 5); 
	add(adj, 3, 4); 
	add(adj, 4, 5); 
	add(adj, 6, 0); 

	// Resultant topological order in topotable 
	vector<int> topotable = topo(adj, n); 

	// Queries 
	cout << who_wins(topotable, 3, 5) << endl; 
	cout << who_wins(topotable, 1, 2) << endl; 

	return 0; 
} 
