#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

class node {
public :
	node() {}
	node(int _y, int _x, int _d) : y(_y), x(_x), d(_d) {}
	int y; int x; int d;
};

int p_y[4] = {0, -1, 0, 1};
int p_x[4] = {-1, 0, 1, 0};
int map[55][55] = {0, };
int cp_map[55][55] = {0, };
int water[55][55] = {0, };
bool visit[55][55];
int R, C;
int main(void) 
{
	queue<node> q, water_q;
	int start_y, start_x, target_y, target_x;
	char ch;
	
	freopen("input_3055", "r", stdin);
	scanf("%d%d\n", &R, &C);
	memset(visit, false, sizeof(visit));
	for (int i = 1; i <= R; i ++) {
		for (int j = 1; j <= C; j++) {
			scanf("%c", &ch);
			if (ch == 'D') { map[i][j] = 'D'; target_y = i; target_x = j;}
			else if (ch == 'S') { map[i][j] = '.'; start_y = i; start_x = j;}
			else map[i][j] = ch;
			water[i][j] = 0x7fffffff;
		}
		scanf("\n");
	}

	for (int i = 1; i <= R; i++) 
		for (int j = 1; j <= C; j++) 
			if (map[i][j] == '*')
				water_q.push(node(i, j, 0));

	memcpy(cp_map, map, sizeof(cp_map));
	while (!water_q.empty()) {
		node n = water_q.front(); water_q.pop();
		
		if (water[n.y][n.x] != 0x7fffffff)
			continue;

		water[n.y][n.x] = n.d;
		for (int i = 0; i < 4; i++) {
			if (cp_map[n.y + p_y[i]][n.x + p_x[i]] == '.') {
				water_q.push(node(n.y + p_y[i], n.x + p_x[i], n.d + 1));
				cp_map[n.y + p_y[i]][n.x + p_x[i]] = '*';
			}
		}
	}

	bool find = false;
	int cnt = 0;
	q.push(node(start_y, start_x, 0));
	while (!q.empty()) {
		node n = q.front(); q.pop();
	
		if (n.y < 1 || n.y > R || n.x < 1 || n.x > C)
			continue; 
		
		if (visit[n.y][n.x])
			continue;

		if (map[n.y][n.x] == 'X' || map[n.y][n.x] == '*')
			continue;

		if (map[n.y][n.x] == 'D') {
			find = true;
			cnt = n.d;
			break;
		}

	
		if (n.d >= water[n.y][n.x]) {
			continue;
		}
		
		visit[n.y][n.x] = true;
		for (int i = 0; i < 4; i++) 
			q.push(node(n.y + p_y[i], n.x + p_x[i], n.d + 1));
			
	}
	if (find) printf("%d\n", cnt);
	else printf("KAKTUS\n");

	return 0;
}

