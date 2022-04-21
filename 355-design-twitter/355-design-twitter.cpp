class Twitter {
public:
    unordered_map<int,unordered_set<int>>followers_map;
   
    priority_queue<vector<int>>tweets;
    int timer;
    Twitter() {
        timer=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets.push({timer,userId,tweetId});
        timer++;
        
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>ans;
        int n=0;
        priority_queue<vector<int>>feed=tweets;
        while(!feed.empty() and n<10)
        {
            auto it=feed.top();
            if(it[1]==userId or followers_map[userId].find(it[1])!=followers_map[userId].end())
            {
                n++;
                ans.push_back(it[2]);
            }
            feed.pop();
        }
        return ans;
            
    }
    
    void follow(int followerId, int followeeId) {
        followers_map[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followers_map[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
