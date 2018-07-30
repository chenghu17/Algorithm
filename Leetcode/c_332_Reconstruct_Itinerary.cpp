//
// Created by Mr.Hu on 2018/7/30.
//
// leetcode 332 reconstruct itinerary
//
//
//
//
//


#include <iostream>
#include <set>
#include <map>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        map<string,multiset<string>> graph;
        vector<string> itinerary;
        if(tickets.size()==0){
            return itinerary;
        }
        for(auto ticket:tickets){
            graph[ticket.first].insert(ticket.second);
        }
        stack<string> dfs;
        dfs.push("JFK");
        while(!dfs.empty()){
            if(graph[dfs.top()].empty()){
                itinerary.push_back(dfs.top());
                dfs.pop();
            }
            else{
                string tmp = *(graph[dfs.top()].begin());
                //erase
                graph[dfs.top()].erase(graph[dfs.top()].begin());
                // add
                dfs.push(tmp);
            }
        }
        reverse(itinerary.begin(),itinerary.end());
        return itinerary;
    }
};

int main(){
    vector<pair<string,string>> tickets;
    pair<string,string> a("MUC", "LHR");
    pair<string,string> b("JFK", "MUC");
    pair<string,string> c("SFO", "SJC");
    pair<string,string> d("LHR", "SFO");
    tickets.emplace_back(a);
    tickets.emplace_back(b);
    tickets.emplace_back(c);
    tickets.emplace_back(d);
    Solution solution;
    vector<string> itinerary = solution.findItinerary(tickets);
    for(auto const& n:itinerary){
        cout<<n<<" ";
    }
    return 0;
}