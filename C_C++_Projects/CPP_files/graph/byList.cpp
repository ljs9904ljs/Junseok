#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> graph[n+1];

    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }









    return 0;
}