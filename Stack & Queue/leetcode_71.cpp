// Problem Link ====>>https://leetcode.com/problems/simplify-path/description/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string simplifyPath(string path)
    {
        stack<string> st;
        string res;

        for (int i = 0; i < path.size(); i++){
            if(path[i] == '/'){
                continue;
            }

            string temp;
            while(i<path.size() && path[i] !='/'){
                temp += path[i];
                ++i;
            }

            if(temp=="."){
                continue;
            }
            else if(temp==".."){
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                st.push(temp);
            }
        }

        while (!st.empty())
        {
            res = "/" + st.top() + res;
            st.pop();
        }

        if (res.size() == 0)
        {
            return "/";
        }

        return res;
    }
};

int main(){
    string inputPath;
    cout << "Enter a path to simplify: ";
    getline(cin, inputPath);

    Solution solution;

    string simplifiedPath = solution.simplifyPath(inputPath);

    cout << "Simplified path: " << simplifiedPath << endl;

    return 0;
}