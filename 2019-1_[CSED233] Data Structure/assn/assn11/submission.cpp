#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define p(x,y) pair<int,int>((x),(y))

struct node {
	int first, second;
};

bool operator<(node x, node y) {
	return x.second > y.second;
}

int dist[100];
vector<pair<int, int>> edge[100];
vector<pair<int, int>>::iterator it;
priority_queue<node> Q;
node a;

int main() {
	int v = 5;  // the number of vertex
	int e = 7;  // the number of edge
	int start = 1;  // starting vertex

	cout << "Starting vertex is 1" << endl;

	// building graph
	edge[1].push_back(p(2, 1));
	edge[1].push_back(p(4, 5));
	edge[2].push_back(p(3, 3));
	edge[2].push_back(p(4, 4));
	edge[2].push_back(p(5, 7));
	edge[3].push_back(p(5, 2));
	edge[4].push_back(p(5, 6));

	// Dijkstra's Algorithm
	/* BEGIN_YOUR_CODE */
	int u;
	int vertex;
	int weight;

	for (int i = 0; i < 100; i++) {
		dist[i] = 10000;
	}
	dist[1] = 0;
	Q.push(node({ 1, dist[1] }));

	while (!Q.empty()) {
		u = Q.top().first;
		Q.pop();

		for (it = edge[u].begin(); it != edge[u].end(); ++it) {
			vertex = (*it).first;
			weight = (*it).second;
			if (dist[vertex] > dist[u] + weight) {
				dist[vertex] = dist[u] + weight;
				Q.push(node({ vertex, weight }));
			}
		}
	}

	

	/* END_YOUR_CODE */

	for (int i = 1; i <= v; i++) {
		cout << "The cost to vertex " << i << " is ";
		if (!dist[i] && i != start) cout << "INF" << endl;
		else cout << dist[i] << endl;
	}
	return 0;
}