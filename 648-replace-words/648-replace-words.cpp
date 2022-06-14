class Trie{
        public:
        Trie *child[26];
        bool isend;
        Trie()
        {
            this->isend=false;
            for(int i=0;i<26;i++)
                this->child[i]=NULL;
        }
    };
class Solution {
    Trie* root;
public:
    string check(string word)
    {
        Trie* temp=root;
        string s="";
        for(auto it:word)
        {
            if(temp->child[it-'a']==NULL)
                break;
            s+=it;
            temp=temp->child[it-'a'];
            if(temp->isend)
                return s;
        }
        return word;
    }
    void insert(string word)
    {
        Trie* temp=root;
        for(auto it:word)
        {
            if(temp->child[it-'a']==NULL)
              temp->child[it-'a']=new Trie();
            temp=temp->child[it-'a'];
        }
        temp->isend=true;
    }
    string replaceWords(vector<string>& dictionary, string sentence)     {
        root=new Trie();
        for(auto it:dictionary)
        {
            insert(it);
        }
        istringstream ss(sentence);
        string word="",ans="";
        for(;ss>>word;)
        {
            ans+=check(word);
            ans+=' ';
        }
        ans.pop_back();
        return ans;
    }
};