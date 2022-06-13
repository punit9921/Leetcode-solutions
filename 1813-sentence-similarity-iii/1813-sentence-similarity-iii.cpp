class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        string longest=sentence1;
        string shortest=sentence2;
        if(longest.size()<shortest.size())
        {
            longest=sentence2;
            shortest=sentence1;
            
        }
        vector<string>arr1,arr2;
        string curr="";
        for(int i=0;i<longest.size();i++)
        {
            if(longest[i]==' ')
            {
                arr1.push_back(curr);
                curr="";
                continue;
            }
            curr+=longest[i];
        }
        arr1.push_back(curr);
        curr="";
        for(int i=0;i<shortest.size();i++)
        {
            if(shortest[i]==' ')
            {
                arr2.push_back(curr);
                curr="";
                continue;
            }
            curr+=shortest[i];
        }
        arr2.push_back(curr);
        int start1=0,start2=0;
        int end1=arr1.size()-1,end2=arr2.size()-1;
        while(start1<=end1 and start2<=end2)
        {
            if(arr1[start1]==arr2[start2])
                start1++,start2++;
            else if(arr1[end1]==arr2[end2])
                end1--,end2--;
            else
                return false;
        }
        return true;
        
    }
};