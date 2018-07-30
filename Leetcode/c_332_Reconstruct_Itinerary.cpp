//
// Created by Mr.Hu on 2018/7/30.
//
// leetcode 332 reconstruct itinerary
//
// 题目给定多个航班信息，要求从"JFK"开始，飞往下一个航班，将所有航班呢飞完，求满足航班信息在字符上最小的航班线路
//
// 这个题目是一个关于图的题目，给定的tickets信息能够构成一张有向图，需要在有向图进行求解。
// 对于每一条航班路线，就是从"JFK"节点开始，向下进行遍历直到叶子节点，所经过的所有节点构成线路，
// 并且遍历采用深度优先（DFS）。所以我们做这个题目第一步就是要建图，使用邻接链表或邻接矩阵构建节点之间的关系，
// 但是在在使用DFS上与我们平时使用的方法并不相同：平时我们是遍历所有节点，因此遍历过的节点我们就标记为true，不再访问，
// 在这里，当我们每次访问完一条路径后，需要重新选择上一个节点的另外一种情况，所以我们需要每次得到一条路径并与原路径进行对比，
// 进行回溯操作后，之前访问过的节点还是需要继续访问。
//
// 第二种方法：既然题目指出每一组票一定有一组正确的解答，而又需要航班信息在字符组合上最小，
// 用一个map来点与点之间的关系，想到与邻接链表，key值为from信息，value是to信息，而这里的to有多种信息，且可能相同，
// 而且题目又要求航班信息字符组合最小，所以我们使用multiset这样的数据结构来存储to信息，可以重复，且自动排序为从小到大，
// 图建完之后，我们从stack来存储路径当前所到达的节点，当stack不为空时，则说明还没有将所有tickets使用完，
// 如果当前节点的value值不为空，则说明还有结下的路可以走，而为了满足路径字符最小，所以我们去value.begin()的节点信息，往下继续走；
// 如果当前节点的value值为空，则说明路径已经规划完成，将stack.top()加入itinerary中，stack.pop()，继续循环。
// 循环结束后，将加入itinerary进行reverse即得到满足条件的路径。
// 这种解法妙在只需要一次遍历，就可以得到最终的结果，这是基于结果一定存在，且每次加入的节点都是字符最小的节点，这要归功于set，
// 这种方法可以避免使用回溯和手动去比较字符串大小。
//

//
// Created by Mr.Hu on 2018/7/30.
//
// leetcode 332 reconstruct itinerary
//
// 题目给定多个航班信息，要求从"JFK"开始，飞往下一个航班，将所有航班呢飞完，求满足航班信息在字符上最小的航班线路
//
// 这个题目是一个关于图的题目，给定的tickets信息能够构成一张有向图，需要在有向图进行求解。
// 对于每一条航班路线，就是从"JFK"节点开始，向下进行遍历直到叶子节点，所经过的所有节点构成线路，
// 并且遍历采用深度优先（DFS）。所以我们做这个题目第一步就是要建图，使用邻接链表或邻接矩阵构建节点之间的关系，
// 但是在在使用DFS上与我们平时使用的方法并不相同：平时我们是遍历所有节点，因此遍历过的节点我们就标记为true，不再访问，
// 在这里，当我们每次访问完一条路径后，需要重新选择上一个节点的另外一种情况，所以我们需要每次得到一条路径并与原路径进行对比，
// 进行回溯操作后，之前访问过的节点还是需要继续访问。
//
// 第二种方法：既然题目指出每一组票一定有一组正确的解答，而又需要航班信息在字符组合上最小，
// 用一个map来点与点之间的关系，想到与邻接链表，key值为from信息，value是to信息，而这里的to有多种信息，且可能相同，
// 而且题目又要求航班信息字符组合最小，所以我们使用multiset这样的数据结构来存储to信息，可以重复，且自动排序为从小到大，
// 图建完之后，我们从stack来存储路径当前所到达的节点，当stack不为空时，则说明还没有将所有tickets使用完，
// 如果当前节点的value值不为空，则说明还有结下的路可以走，而为了满足路径字符最小，所以我们去value.begin()的节点信息，往下继续走；
// 如果当前节点的value值为空，则说明路径已经规划完成，将stack.top()加入itinerary中，stack.pop()，继续循环。
// 循环结束后，将加入itinerary进行reverse即得到满足条件的路径。
// 这种解法妙在只需要一次遍历，就可以得到最终的结果，这是基于结果一定存在，且每次加入的节点都是字符最小的节点，这要归功于set，
// 这种方法可以避免使用回溯和手动去比较字符串大小。
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
        map<string, multiset<string>> graph;
        vector<string> itinerary;
        if (tickets.size() == 0) {
            return itinerary;
        }
        for (auto ticket:tickets) {
            graph[ticket.first].insert(ticket.second);
        }
        stack<string> dfs;
        dfs.push("JFK");
        while (!dfs.empty()) {
            if (graph[dfs.top()].empty()) {
                itinerary.push_back(dfs.top());
                dfs.pop();
            } else {
                string tmp = *(graph[dfs.top()].begin());
                //erase
                graph[dfs.top()].erase(graph[dfs.top()].begin());
                // add
                dfs.push(tmp);
            }
        }
        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }
};

int main() {
    vector<pair<string, string>> tickets;
    pair<string, string> a("MUC", "LHR");
    pair<string, string> b("JFK", "MUC");
    pair<string, string> c("SFO", "SJC");
    pair<string, string> d("LHR", "SFO");
    tickets.emplace_back(a);
    tickets.emplace_back(b);
    tickets.emplace_back(c);
    tickets.emplace_back(d);
    Solution solution;
    vector<string> itinerary = solution.findItinerary(tickets);
    for (auto const &n:itinerary) {
        cout << n << " ";
    }
    return 0;
}