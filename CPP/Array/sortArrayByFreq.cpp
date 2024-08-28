// Sort Elements of an Array by Frequency
// Problem link: - https://www.geeksforgeeks.org/problems/sorting-elements-of-an-array-by-frequency-1587115621/1
#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>
using namespace std;
vector<int> sortByFreq(vector<int> &arr, int n) {
    unordered_map<int, int>mp;
    vector<int>res;
    vector<pair<int, int>>vp;
    for(int i=0; i<n; i++)
        mp[arr[i]]++;
    for(auto it : mp)
        vp.push_back({it.first, it.second});
    sort(vp.begin(), vp.end(), [](pair<int, int>p1, pair<int, int>p2) {
        if(p1.second == p2.second)
            return p1.first < p2.first;
        return p1.second > p2.second;
    });
    for(int i=0; i<vp.size(); i++) {
        while(vp[i].second--)
            res.push_back(vp[i].first);
    }
    return res;
}
int main() {
    int n;
    cout << "Enter length of array: ";
    cin >> n;
    vector<int>arr(n);
    cout << "Enter array elements: ";
    for(int i=0; i<n; i++) 
        cin >> arr[i];
    vector<int>res = sortByFreq(arr, n);
    for(int i=0; i<res.size(); i++)
        cout << res[i] << " ";
}