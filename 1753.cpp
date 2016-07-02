#include <stdio.h>
#include <string.h>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

typedef struct _edge {
	int to;
	int weight;
} edge;

typedef struct _node {
	int vertex;
	int distance;
} node;

bool operator< (node a, node b) {
	return a.distance > b.distance;
}

vector<edge> edge_list[20001];
bool visit[20001];
unsigned long long d[20001];

int main(void)
{
	priority_queue<node> pq;
	int v, e, k, from, to, weight;

	freopen("input_1753", "r", stdin);
	memset(visit, false, sizeof(visit));
	scanf("%d %d %d", &v, &e, &k);
	for (int i = 0; i < e; i++) {
		scanf("%d %d %d", &from, &to, &weight);
		edge input_edge; input_edge.weight = weight;
		input_edge.to = to; edge_list[from].push_back(input_edge);
		// directed graph
		//input_edge.to = from; edge_list[to].push_back(input_edge);
	}

	node n; n.vertex = k; n.distance = 0;
	pq.push(n);
	while (!pq.empty()) {
		n = pq.top(); pq.pop();
	
		if (visit[n.vertex])
			continue;
		d[n.vertex] = n.distance;
		visit[n.vertex] = true;
		for (int i = 0; i < edge_list[n.vertex].size(); i++) {
			edge tmp = edge_list[n.vertex][i];
			node n2; n2.vertex = tmp.to;
			n2.distance = n.distance + tmp.weight;
			pq.push(n2);
		}
	}

	for (int i = 1; i <= v; i++) {
		if (i == k) {
			printf("0\n");
			continue;
		}

		if (d[i] == 0)
			printf("INF\n");
		else
			printf("%llu\n", d[i]);
	}

	return 0;
}
