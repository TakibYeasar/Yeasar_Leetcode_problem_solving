
// Problem Link ====>>https://leetcode.com/problems/count-and-say/description/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    string countAndSay(int n){
        switch(n){
            case 1:
                return "1";
            case 2:
                return "11";
        }

        string str = "11";
        int counter = 1;
        string temp = "";

        for (int i = 3; i <= n; ++i){
            str += "&";
            for (int j = 1; j < str.length(); ++j){
                if(str[j] != str[j-1]){
                    temp += to_string(counter) + str[j - 1];
                    counter = 1;
                } else {
                    ++counter;
                }
            }
            counter = 1;
            str = move(temp);
            temp.clear();
        }
        return str;
    }
};

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    Solution solution;
    string result = solution.countAndSay(n);

    cout << "The " << n << "th term in the count-and-say sequence is: " << result << endl;

    return 0;
}