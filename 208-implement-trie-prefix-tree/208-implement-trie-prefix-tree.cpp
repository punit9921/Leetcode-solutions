struct Node{
    Node* child[26];
    bool isend;
    Node()
    {
        for(int i=0;i<26;i++)
            child[i]=NULL;
        isend=false;
    }
};
class Trie {
    Node* root=new Node();
public:
    Trie() {
        
    }
    
    void insert(string word) {
        Node* curr=root;
        for(auto it:word)
        {
            int ind=it-'a';
            if(curr->child[ind]==NULL)
                curr->child[ind]=new Node();
            curr=curr->child[ind];
        }
        curr->isend=true;
    }
    
    bool search(string word) {
        Node* curr=root;
        for(auto it:word)
        {
            int ind=it-'a';
            if(curr->child[ind]==NULL)
                return false;
            curr=curr->child[ind];
        }
        return curr->isend;
    }
    
    bool startsWith(string prefix) {
        Node* curr=root;
        for(auto it:prefix)
        {
            int ind=it-'a';
            if(curr->child[ind]==NULL)
                return false;
            curr=curr->child[ind];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */