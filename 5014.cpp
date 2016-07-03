#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, int> node;
bool visit[1000001];

int main(void)
{
	queue<node> q;
	int F, S, G, U, D;
	bool find = false;

	scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
	memset(visit, false, sizeof(visit));
	node n(S, 0); q.push(n);

	while (!q.empty()) {
		n = q.front(); q.pop();
		
		if (n.first < 1 || n.first > F || visit[n.first])
			continue;

		if (n.first == G) {
			find = true;
			break;
		}

		visit[n.first] = true;
		node n2(n.first + U, n.second + 1); q.push(n2);
		node n3(n.first - D, n.second + 1); q.push(n3);
	}
	
	if (find) printf("%d\n", n.second);
	else printf("use the stairs\n");

	return 0;
}

