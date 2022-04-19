class Solution {
public:
    int racecar(int target) {
        queue<vector<int>>q;
        q.push({0,1,0});
        while(!q.empty())
        {
            vector<int>v=q.front();
            q.pop();
            int pos=v[0];
            int speed=v[1];
            int steps=v[2];
            if(pos==target)
                return steps;
            if(pos+speed<=10000 and pos+speed>0)
            {
                q.push({pos+speed,speed*2,steps+1});
            }
            if(speed>0 and pos+speed>target)
            {
                q.push({pos,-1,steps+1});
            }
            if(speed<0 and pos+speed<target)
            {
                q.push({pos,1,steps+1});
            }
        }
        return -1;
        
    }
};