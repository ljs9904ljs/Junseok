#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    int n, m, i, j;
    cin >> n >> m; // n은 정점 개수, m은 간선 개수
    
    int graph[n+1][n+1];

    for(i=0;i<=n;i++){
        for(j=0;j<=n;j++){
            graph[i][j] = -1;
        }
    }

    for(i=0;i<m;i++){
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = graph[v][u] = 1; // 방향 x , 가중치가 없는 경우
    }
















    return 0;
}
