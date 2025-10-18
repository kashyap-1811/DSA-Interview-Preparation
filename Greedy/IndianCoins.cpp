#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> makeChange(vector<int>&denominations, int &amt)
{
    int coins = 0;
    sort(denominations.begin(), denominations.end());
    vector<pair<int, int>>solution(denominations.size());
    for(int i=denominations.size()-1; i>=0; i--)
    {
        solution[i].first = denominations[i];
        if(amt < denominations[i]){
            solution[i].second = 0;
            continue;
        }
        int currCoin = amt/denominations[i];
        coins += currCoin;
        amt -= (currCoin * denominations[i]);
        solution[i].second = currCoin;
    }
    cout<<coins<<endl;
    return solution;
}

int main()
{
    vector<int>denominations = {1, 2, 5, 10, 20, 50, 100, 500, 2000};
    int amt = 12100;

    vector<pair<int, int>>ans = makeChange(denominations, amt);
    for(pair<int, int>i : ans)
        cout<<i.first<<" "<<i.second<<endl;
    return 0;
}