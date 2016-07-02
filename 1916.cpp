#include <stdio.h>
#include <string.h>
#include <iostream>
#include <queue>

using namespace std;
typedef struct _node {
	int vertex;
	unsigned long long distance;
} node;
typedef struct _edge {
	int to;
	int weight;
} edge;

vector<edge> edge_list[1010];
bool visit[1010];

bool operator< (node a, node b) {
	return a.distance > b.distance;
}

int main(void)
{
	priority_queue<node> pq;
	int n, m, from, to, weight, start, end;

	freopen("input_1916", "r", stdin);
	memset(visit, false, sizeof(visit));
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &from, &to, &weight);
		edge e; e.to = to; e.weight = weight;
		edge_list[from].push_back(e);
	}
	scanf("%d %d", &start, &end);

	node n1; n1.vertex = start; n1.distance = 0; pq.push(n1);
	while (!pq.empty()) {
		n1 = pq.top(); pq.pop();
		
		if (n1.vertex == end) 
			break;

		if (visit[n1.vertex])
			continue;

		visit[n1.vertex] = true;

		for (int i = 0; i < edge_list[n1.vertex].size(); i++) {
			edge e = edge_list[n1.vertex][i];
			node n2; n2.vertex = e.to; 
			n2.distance = n1.distance + e.weight;
			pq.push(n2);
		}
	}

	printf("%llu\n", n1.distance);
	return 0;
}
