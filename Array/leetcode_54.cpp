
// Problem link ===>> https://leetcode.com/problems/spiral-matrix/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> result;
        int top = 0, bottom = matrix.size() - 1;
        int left = 0, right = matrix[0].size() - 1;

        while (top <= bottom && left <= right){

            // Traverse top row
            for (int j = left; j <= right; j++){
                result.push_back(matrix[top][j]);
            }
            top++;

            // Traverse right column
            for (int i = top; i <= bottom; i++){
                result.push_back(matrix[i][right]);
            }
            right--;

            // Traverse bottom row (if valid)
            if(top<= bottom){
                for (int j = right; j >= left; j--){
                    result.push_back(matrix[bottom][j]);
                }
                bottom--;
            }

            // Traverse left column (if valid)
            if(left <= right){
                for (int i = bottom; i >= top; i--)
                {
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return result;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;

        
    }
    return 0;
}