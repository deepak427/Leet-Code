/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    void dfs(int &id, unordered_map<int, Employee*> &employees, int &max_importance){
        max_importance = max_importance+employees[id]->importance;

        for(auto emp: employees[id]->subordinates){
            dfs(emp, employees, max_importance);
        }
    }

    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> um;

        for(Employee* e: employees){
            um[e->id] = e;
        }

        int max_importance = 0;

        dfs(id, um, max_importance);

        return max_importance;
    }
};