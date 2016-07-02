#include <iostream>  
#include <cstdio>  
#include <cstring>  
using namespace std;  
int N, M, X;  
const int MAXN = 1001, MAXM = 100001, INF = 0x3f3f3f3f;  
  
int d[MAXN][MAXN];  
  
void Floyd()  
{  
    for(int k = 1; k <= N; k++)  
        for(int i = 1; i <= N; i++)  
            for(int j = 1; j <= N; j++)  
                if(d[i][k]+d[k][j] < d[i][j])  
                    d[i][j] = d[i][k]+d[k][j];  
}  
  
int main()  
{  
	freopen("input_1238", "r", stdin);
    scanf("%d%d%d", &N, &M, &X);  
    memset(d, 0x3f, sizeof(d));  
    for(int i = 0; i < M; i++)  
    {  
        int u, v, w;  
        scanf("%d%d%d", &u, &v, &w);  
        d[u][v] = w;  
    }  
    Floyd();  
    int Max = 0;  
    for(int i = 1; i <= N; i++)  
    {  
        int t = 0;  
        if(i!=X)  
            t = d[i][X] + d[X][i];  
        if(t > Max)  
            Max = t;  
    }  
    printf("%d\n", Max);  
    return 0;  
}  
