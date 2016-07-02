#include <stdio.h>
#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int main(void)
{
	int N, result;
	bool visited[1000001] = {false ,};
	queue<pair<int, int> > q;

	scanf("%d", &N);

	q.push(make_pair(N, 0));
	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();

		if (p.first == 1) {
			result = p.second;
			break;
		}

		if (p.first % 3 == 0 && !visited[p.first / 3]) {
			visited[p.first / 3] = true;
			q.push(make_pair(p.first / 3, p.second + 1));
		}
		if (p.first % 2 == 0 && !visited[p.first / 2]) {
			visited[p.first / 2] = true;
			q.push(make_pair(p.first / 2, p.second + 1));
		}
		if (p.first - 1 > 0 && !visited[p.first - 1]) {
			visited[p.first - 1] = true;
			q.push(make_pair(p.first - 1, p.second + 1));
		}
	}

	printf("%d\n", result);

	return 0;
}
