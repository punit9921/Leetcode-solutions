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
    map<int,Employee*>mp;
    int dfs(int q_id)
    {
        Employee* emp=mp[q_id];
        int ans=emp->importance;
        for(auto it:emp->subordinates)
            ans+=dfs(it);
        return ans;
    }
    int getImportance(vector<Employee*> employees, int id) {
      for(auto it:employees)
      {
          mp[it->id]=it;
      }
        
        return dfs(id);
    }
};