class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n=deck.size();
        sort(begin(deck),end(deck));
        deque<int>dq;
         if(deck.size()<=2)
             return deck;
        dq.push_back(deck.back());
        deck.pop_back();
        while(!deck.empty())
        {
            int temp=dq.back();
            dq.pop_back();
            dq.push_front(temp);
            dq.push_front(deck.back());
            deck.pop_back();
        }
        return vector<int>(dq.begin(),dq.end());
    }
};