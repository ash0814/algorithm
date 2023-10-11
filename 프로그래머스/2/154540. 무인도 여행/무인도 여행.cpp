#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int visited[104][104];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int bfs(vector<string> maps, int i, int j) {
    queue<pair<int, int>> qu;
    qu.push({i, j});
    visited[i][j] = 1;
    
    int food = 0;
    
    while (!qu.empty()) {
        int x = qu.front().first;
        int y =qu.front().second;
        
        food += maps[x][y] - '0';
        qu.pop();
        
        for (int k = 0; k < 4; k++) {
            int nx = dx[k] + x;
            int ny = dy[k] + y;
            if (nx < 0 || ny < 0 || nx >= maps.size() || ny >= maps[i].length() || visited[nx][ny])
                continue;
            if (maps[nx][ny] != 'X') {
                visited[nx][ny] = 1;
                qu.push({nx, ny});
            }
        }
    }
    return food;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0; j < maps[i].length(); j++) {
            if (maps[i][j] != 'X' && visited[i][j] != 1)
                answer.push_back(bfs(maps, i, j));
        }
    }
    sort(answer.begin(), answer.end());
    if (answer.size() <= 0)
        answer.push_back(-1);
    return answer;
}