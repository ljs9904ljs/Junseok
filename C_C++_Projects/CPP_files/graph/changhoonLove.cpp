#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>

using namespace std;

typedef struct node {
    int from;
    int to;
    int weight;
} node;

typedef struct work {
    int curr;
    int level;
} work;

typedef struct p_node {
    int from;
    int to;
    int dist;
} p_node;

vector<vector<node> > graph; 
vector<bool> check;
vector<int> dist;

void dfs(int curr) {
    check[curr] = true;
    
    // something to do
    printf("%d\n", curr);

    for(auto e : graph[curr])
        if(!check[e.to])
            dfs(e.to);
}

void bfs(int curr) {
    queue<work> q;

    q.push(work{curr, 0});

    while(!q.empty()) {
        auto front = q.front();
        q.pop();
        if(check[front.curr]) continue;
        check[front.curr] = true;
        
        // something to do
        printf("%d : %d\n",front.curr, front.level);

        for(auto e : graph[front.curr])
            if(!check[e.to])
                q.push(work{e.to, front.level + 1});
    }
}

void dijkstra(int curr) {
    // 람다식을 이용해서 비교 연산자를 만든다?
    auto comp = [](const p_node& a, const p_node& b) -> bool {
        return a.dist < b.dist;
    };
    // decltype은 타입을 알려준다?
    priority_queue<p_node, vector<p_node>, decltype(comp)> pq(comp);

    // 시작점의 값은 0이다.
    dist[curr] = 0;

    
    for(auto e : graph[curr]) // 시작점과 이어져 있는 점들에 대해서
        pq.push(p_node{e.from, e.to, e.weight}); // 시작점으로부터 'e'라는 점까지의 거리값을 저장

    while(!pq.empty()) { 
        auto top = pq.top();
        pq.pop();
        if(dist[top.to] <= top.dist) continue;
        dist[top.to] = top.dist;

        for(auto e : graph[top.to])
            if(dist[e.to] >= e.weight + dist[e.from])
                pq.push(p_node{e.from, e.to, e.weight + dist[e.from]});
    }
}

int main() {
    int V, E;
    cin >> V;
    cin >> E;

    graph.assign(V, vector<node>());

    for(int e=0;e<E;e++) {
        int from, to, weight;
        cin >> from >> to >> weight;
    
        graph[from].push_back(node{from, to, weight});
        graph[to].push_back(node{to, from, weight});
    }

    check.assign(V, bool(false));
    

    for(int v=0;v<V;v++) 
        if(!check[v]) 
            dfs(v);


    printf("-------------bfs >< \n\n\n");

    check.clear();
    check.assign(V, bool(false));

    for(int v=0;v<V;v++)
        if(!check[v])
            bfs(v);

    printf("-------------dijkstra >< \n\n\n");

    dist.assign(V, INT_MAX);
    dijkstra(0);
    for(int v=0;v<V;v++)
        printf("%d : %d\n", v, dist[v]);
}