//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
int findlow(vector<vector<int>> &mat) {
    int low = INT_MAX;
    int n = mat.size();
    for (int i = 0; i < n; i++) {
        low = min(low, mat[i][0]);
    }
    return low;
}

int findhigh(vector<vector<int>> &mat) {
    int high = INT_MIN;
    int n = mat.size();
    int n2 = mat[0].size();
    for (int i = 0; i < n; i++) {
        high = max(high, mat[i][n2 - 1]);
    }
    return high;
}

int upperBound(vector<int> &mat, int x, int n) {
    int low = 0, high = n - 1;
    int ans = n;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (mat[mid] > x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int blackbox(vector<vector<int>> &mat, int mid) {
    int cnt = 0;
    int n = mat.size();
    for (int i = 0; i < n; i++) {
        cnt += upperBound(mat[i], mid, mat[i].size());
    }
    return cnt;
}

class Solution {
public:
    int median(vector<vector<int>> &mat) {
        int m = mat.size();
        int n = mat[0].size();
        int low = findlow(mat);
        int high = findhigh(mat);
        int comp = (m * n) / 2;
        
        while (low <= high) {
            int mid = (low + high) / 2;
            int smallequals = blackbox(mat, mid);
            
            if (smallequals > comp) 
                high = mid - 1;
            else 
                low = mid + 1;
        }
        return low;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                cin >> matrix[i][j];
        Solution obj;
        int ans = -1;
        ans = obj.median(matrix);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends