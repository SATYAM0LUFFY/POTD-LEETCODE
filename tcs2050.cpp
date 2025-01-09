#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <tuple>
#include <string>

using namespace std;

// Function to count infected neighboring cities
int count(const vector<vector<int>>& board, int x, int y) {
    int size = board.size();
    int infectedCount = 0;
    
    vector<pair<int, int>> directions = {{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}};
    
    for (const auto& dir : directions) {
        int dx = dir.first;
        int dy = dir.second;
        
        int nx = x + dx;
        int ny = y + dy;
        
        if (nx >= 0 && nx < size && ny >= 0 && ny < size && board[nx][ny] == 1) {
            infectedCount++;
        }
    }
    
    return infectedCount;
}

// Function to simulate plague spread for one day
vector<vector<int>> plagueSimulation(const vector<vector<int>>& board) {
    int size = board.size();
    vector<vector<int>> newBoard = board;
    
    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            int infectedCount = count(board, x, y);
            
            if (board[x][y] == 0 && infectedCount == 3) {
                newBoard[x][y] = 1;  // City becomes infected
            }
            else if (board[x][y] == 1 && (infectedCount < 2 || infectedCount > 3)) {
                newBoard[x][y] = 0;  // City becomes uninfected
            }
        }
    }
    
    return newBoard;
}

// Find minimum days to reach herb location
int findPath(int gridSize, const vector<vector<char>>& initialBoard) {
    // Convert board to integer representation
    vector<vector<int>> board(gridSize, vector<int>(gridSize, 0));
    int startX = -1, startY = -1, endX = -1, endY = -1;
    
    for (int x = 0; x < gridSize; x++) {
        for (int y = 0; y < gridSize; y++) {
            if (initialBoard[x][y] == '1') {
                board[x][y] = 1;
            }
            if (initialBoard[x][y] == 's') {
                startX = x;
                startY = y;
                board[x][y] = 0;
            }
            if (initialBoard[x][y] == 'd') {
                endX = x;
                endY = y;
                board[x][y] = 0;
            }
        }
    }
    
    // Define a struct to hold our state
    struct State {
        int x, y, days;
        vector<vector<int>> board;
        
        // Custom comparator for set to avoid duplicates
        bool operator<(const State& other) const {
            return tie(x, y, board) < tie(other.x, other.y, other.board);
        }
    };
    
    // Queue to store state
    queue<State> q;
    q.push({startX, startY, 0, board});
    
    // Set to track visited states to avoid loops
    set<State> visited;
    
    // Possible moves: stay or move to adjacent cities
    vector<pair<int, int>> moves = {{0,0}, {-1,0}, {1,0}, {0,-1}, {0,1}};
    
    while (!q.empty()) {
        State current = q.front();
        q.pop();
        
        // Reached destination
        if (current.x == endX && current.y == endY) {
            return current.days;
        }
        
        // Check if state is already visited
        if (visited.count(current)) continue;
        visited.insert(current);
        
        // Simulate plague spread for next day
        vector<vector<int>> nextBoard = plagueSimulation(current.board);
        
        // Try all possible moves
        for (const auto& move : moves) {
            int dx = move.first;
            int dy = move.second;
            
            int nx = current.x + dx;
            int ny = current.y + dy;
            
            if (nx >= 0 && nx < gridSize && ny >= 0 && ny < gridSize) {
                // Skip if next city will be infected
                if (nextBoard[nx][ny] == 1) continue;
                
                q.push({nx, ny, current.days + 1, nextBoard});
            }
        }
    }
    
    return -1;  // No path found
}

int main() {
    int N;
    cin >> N;
    
    vector<vector<char>> initialBoard(N, vector<char>(N));
    
    // Read input board
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> initialBoard[i][j];
        }
    }
    
    // Find minimum days to get herb
    int result = findPath(N, initialBoard);
    cout << result+1 << endl;
    
    return 0;
}