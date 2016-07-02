#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;
bool visit[10000];

class node {
public :
	node() {}
	node(int v, int d) : value(v), depth(d) {}
	int value;
	int depth;
};

bool is_prime(int n)
{
	for (int i = 2; i < n; i++)
		if (n % i == 0)
			return false;

	return true;
}

int make_number(int a, int b, int c, int d)
{
	return a * 1000 + b * 100 + c * 10 + d;
}

int main(void)
{
	int T;

	freopen("input_1963", "r", stdin);
	scanf("%d", &T);
	while (T--) {
		int source, target, result;
		bool find = false;
		queue<node> q;

		scanf("%d %d", &source, &target);
		memset(visit, false, sizeof(visit));

		q.push(node(source, 0));
		while (!q.empty()) {
			node n = q.front(); q.pop();

			if (n.value == target) {
				find = true; result = n.depth;
				break;
			}

			if (!is_prime(n.value) || visit[n.value])
				continue;

			visit[n.value] = true;

			int d[4];
			d[0] = n.value / 1000; d[1] = (n.value - d[0] * 1000) / 100;
			d[2] = (n.value - d[0] * 1000 - d[1] * 100) / 10;
			d[3] = (n.value - d[0] * 1000 - d[1] * 100 - d[2] * 10);

			for (int i = 0; i <= 9; i++) {
				if (d[0] != i && i != 0) q.push(node(make_number(i, d[1], d[2], d[3]), n.depth + 1));
				if (d[1] != i) q.push(node(make_number(d[0], i, d[2], d[3]), n.depth + 1));
				if (d[2] != i) q.push(node(make_number(d[0], d[1], i, d[3]), n.depth + 1));
				if (d[3] != i) q.push(node(make_number(d[0], d[1], d[2], i), n.depth + 1));
			}

		}

		if (find) printf("%d\n", result);
		else printf("Impossible\n");
	}

	return 0;
}
