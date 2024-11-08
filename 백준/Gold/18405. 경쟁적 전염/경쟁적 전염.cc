#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, K, S, X, Y;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int graph[1001][1001];

struct cmp {
    bool operator()(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b){
        if (a.first != b.first)
            return a.first > b.first;
        else
            return graph[a.second.first][a.second.second] > graph[b.second.first][b.second.second];
    }
};

priority_queue <pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,cmp> pq;

void bfs(){

    while(!pq.empty()){
        int curx = pq.top().second.first;
        int cury = pq.top().second.second;
        int curt = pq.top().first;
        pq.pop();

        if(curt == S + 1)
            break;
        for(int k = 0 ; k < 4 ;k++){
            if(curx + dx[k] >=1 && curx + dx[k] <= N && cury + dy[k] >= 1 && cury + dy[k] <= N){
                if(!graph[curx + dx[k]][cury + dy[k]]){
                    graph[curx + dx[k]][cury + dy[k]] = graph[curx][cury];
                    pq.push({curt + 1, {curx + dx[k],cury+dy[k]}});
                }
            }
        }
    }
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    for(int i = 1 ; i <= N ;i++){
        for(int j = 1 ; j <= N ;j++){
            cin >> graph[i][j];
            if(graph[i][j]){
                pq.push({1,{i,j}});
            }
        }
    }
    cin >> S >> X >> Y;
    bfs();    
    cout << graph[X][Y];
}
