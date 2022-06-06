class Solution {
public:
    string entityParser(string text) {
         unordered_map<string,string> mp;
        int n=text.size();
        mp["&quot;"]="\"";
        mp["&apos;"]="'";
        mp["&amp;"]="&";
        mp["&gt;"]=">";
        mp["&lt;"]="<";
        mp["&frasl;"]="/";
        string ans="";
        for(int i=0;i<n;i++)
        {
            if(text[i]=='&'&&i+3<n&&isalpha(text[i+1]))
            {
                int j=i;
                string word="";
                while(text[j]!=';'&&(j-i)<=6)
                {
                    word+=text[j];
                    j++;
                }
                word+=';';
                if(mp.find(word)!=mp.end())
                {
                    ans+=mp[word];
                    i=j;
                }
                else
                ans+='&';
            }
            else
            ans+=text[i];
        }
        return ans;
    }
    
};