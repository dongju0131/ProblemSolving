#include <stdio.h>
#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int main(void)
{
	int N, K, result;
	bool visited[100001] = {false, };
	queue<pair<int, int> > q;

	scanf("%d %d", &N, &K);
	q.push(make_pair(N, 0));
	visited[N] = true;

	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();
		
		int cur = p.first;
		int cnt = p.second;
		if (cur == K) {
			result = cnt;
			break;
		}

		if (cur != 100000 && !visited[cur + 1]) {
			visited[cur + 1] = true;
			q.push(make_pair(cur + 1, cnt + 1));
		}
		if (cur != 0 && !visited[cur - 1]) {
			visited[cur - 1] = true;
			q.push(make_pair(cur - 1, cnt + 1));
		}
		if (2 * cur <= 100000 && !visited[2 * cur]) {
			visited[2 * cur] = true;
			q.push(make_pair(2 * cur, cnt + 1));
		}
			
	}

	printf("%d\n", result);

	return 0;
}
