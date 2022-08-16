class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string>s;
        bool ispresent=false;
        for(auto it:wordList)
        {
            if(it==endWord)
                ispresent=true;
            s.insert(it);
        }
        if(!ispresent)
            return 0;
        int ans=0;
        queue<string>q;
        q.push(beginWord);
        while(!q.empty())
        {
            ans++;
            int sz=q.size();
            while(sz--)
            {
                string word=q.front();
                q.pop();
                for(int i=0;i<word.size();i++)
                {
                    string temp=word;
                    for(char ch='a';ch<='z';ch++)
                    {
                        temp[i]=ch;
                        if(temp==word)
                            continue;
                        if(temp==endWord)
                            return ans+1;
                        if(s.find(temp)!=s.end())
                        {
                            q.push(temp);
                            s.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
        
    }
};