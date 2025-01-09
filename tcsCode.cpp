#include <bits/stdc++.h>
using namespace std;
int V[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};


bool canMove(int a, int b, int n, const vector<vector<char>>& grid) {
    if(a <0 || a >= n )
        {return false;}
    if(b < 0 || b >= n){
        return false;
    }
    if(grid[a][b] == 'M')
        {return false;}
    return true;
}

int minWater(int n, pair<int, int>  s, pair<int, int> e ,  const vector<vector<char>>& grid) {

    vector<vector<int>> newvector(n, vector<int>(n, INT_MAX));

    queue<pair<int, int>> w;

    w.push(s);

    newvector[s.first][s.second] = 0;

    while (!w.empty()) {

        int a  = w.front().first;
        int b  = w.front().second;

        w.pop();

        for (int d = 0; d < 4; d++) {
            int X = a + V[d][0];
            int Y = b + V[d][1];

            if (canMove(X, Y, n, grid)) {
                int val ;

                if(grid[a][b] == 'T' && grid[X][Y] == 'T'){
                     val = 0;
                }
                else{
                     val = 1;
                }    

                if (newvector[a][b] + val < newvector[X][Y]) {
                    newvector[X][Y] = newvector[a][b] + val;
                    w.push({X, Y});
                }
            }
        }
    }
    return newvector[e.first][e.second];
}

int main() {
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    pair<int, int>  s, e;

   
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S')  s = {i, j};
            if (grid[i][j] == 'E') e = {i, j};
            
        }
    }

 
    int result = minWater(n,   s, e , grid);

    cout << result << endl;

    return 0;
}
