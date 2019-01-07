//
// Created by Mr.Hu on 2019/1/7.
//
// leetcode 690 employee importance
//
//
//

#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};

class Solution {
public:
    int getImportance(vector<Employee *> employees, int id) {
        queue<int> all_sub;
        all_sub.push(id);
        map<int, int> id_imp;
        map<int, vector<int>> id_sub;
        for (auto employ:employees) {
            id_imp[employ->id] = employ->importance;
            id_sub[employ->id].assign(employ->subordinates.begin(), employ->subordinates.end());
        }
        int importances = 0;
        int sid;
        while (!all_sub.empty()) {
            sid = all_sub.front();
            all_sub.pop();
            importances += id_imp[sid];
            if (id_sub[sid].size() != 0) {
                for (auto i:id_sub[sid]) {
                    all_sub.push(i);
                }
            }
        }
        return importances;
    }
};

int main() {
    vector<Employee *> employees;

    Employee a;
    a.id = 1;
    a.importance = 5;
    a.subordinates = {2, 3};

    Employee b;
    b.id = 2;
    b.importance = 3;
    b.subordinates = {4};

    Employee c;
    c.id = 3;
    c.importance = 1;
    c.subordinates = {};

    Employee d;
    d.id = 4;
    d.importance = 1;
    d.subordinates = {};

    employees = {&a, &b, &c, &d};

    Solution solution;
    int importances = solution.getImportance(employees, 1);
    cout << "the all importance = " << importances;
    return 0;


}