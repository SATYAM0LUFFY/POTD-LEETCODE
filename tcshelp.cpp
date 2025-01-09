#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;

pair<int, int> getMax(const string& snew, const string& final, int initialIdx) {

    size_t subIdx = 0, finalIdx = initialIdx, length_error = 0;
    
    while (subIdx < snew.length() && finalIdx < final.length()) {
        if (snew[subIdx] == final[finalIdx]) {
            length_error++;
            finalIdx++;
        }
        subIdx++;
    }
    

    int Deletions = static_cast<int>(snew.length() - length_error);
    return make_pair(static_cast<int>(length_error), Deletions);
}

void find() {
    int input;
    cin >> input;
    
    vector<string> del(input);
    for (int i = 0; i < input; i++) {
        cin >> del[i];
    }
    
    string fString;
    cin >> fString;
    
    int Deletions;
    cin >> Deletions;
    
    int size = fString.length();
    const int infy = INT_MAX;
    
    vector<int> minimumDeletions(size + 1, infy);
    minimumDeletions[0] = 0;
    
    for (int idx = 0; idx < size; idx++) {
        if (minimumDeletions[idx] == infy) continue;
        
        for (const auto& patt : del) {
            pair<int, int> result = getMax(patt, fString, idx);
            int preLength = result.first;
            int deletions = result.second;
            
            if (preLength == 0) continue;
            
            int newIdx = idx + preLength;
            
            if (newIdx <= size) {
                minimumDeletions[newIdx] = min(minimumDeletions[newIdx], minimumDeletions[idx] + deletions);
            }
        }
    }
    
    if (minimumDeletions[size] <= Deletions) {
        cout << "Possible" << endl;
    } 
    else if (minimumDeletions[size] == infy) {
        cout << "Impossible" << endl;
    } 
    else {
        int maxkis = -1;
        for (int idx = size; idx >= 0; idx--) {
            if (minimumDeletions[idx] <= Deletions) {
                maxkis = idx;
                break;
            }
        }
        
        if (maxkis > 0) {
            cout << fString.substr(0, maxkis) << endl;
        } 
        else {
            cout << "Nothing" << endl;
        }
    }
}

int main() {
    find();
    return 0;
}