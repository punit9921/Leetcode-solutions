class Encrypter {
public:
    set<string>s;
    map<char,string>mp1;
    map<string,int>mp2;
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
       
          
        for(int i=0;i<keys.size();i++)
        {
            mp1[keys[i]]=values[i];
            
        }
        for(auto it:dictionary)
        {
            string s=encrypt(it);
            mp2[s]++;
        }
    }
    
    string encrypt(string word1) {
        string ans;
        for(auto it:word1)
            ans+=mp1[it];
        return ans;
    }
    
    int decrypt(string word2) {
        if(mp2.find(word2)==mp2.end())
            return 0;
        return mp2[word2];
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */