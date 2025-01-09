#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

// Function to calculate minimum number of presses required
int minBrushPresses(const vector<pair<int, int>>& vertices, int M) {
    // Initialize minimum and maximum coordinates
    int minX = INT_MAX, maxX = INT_MIN;
    int minY = INT_MAX, maxY = INT_MIN;

    // Find bounding rectangle coordinates
    for (const auto& vertex : vertices) {
        minX = min(minX, vertex.first);
        maxX = max(maxX, vertex.first);
        minY = min(minY, vertex.second);
        maxY = max(maxY, vertex.second);
    }

    // Calculate dimensions of the bounding rectangle
    int width = maxX - minX;
    int height = maxY - minY;

    // Calculate number of presses in each direction
    int pressesX = ceil((double)width / M);
    int pressesY = ceil((double)height / M);

    // Total number of presses
    return pressesX * pressesY;
}

int main() {
    int N; // Number of vertices
    cin >> N;

    vector<pair<int, int>> vertices(N);
    for (int i = 0; i < N; ++i) {
        cin >> vertices[i].first >> vertices[i].second; // Input vertices
    }

    int M; // Size of the brush
    cin >> M;

    // Output the minimum number of presses
    cout << minBrushPresses(vertices, M) << endl;

    return 0;
}