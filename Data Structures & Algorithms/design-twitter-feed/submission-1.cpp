class Twitter {
    int time;
    unordered_map<int,vector<pair<int,int>>> posts;
    unordered_map<int,set<int>> followers;
public:
    Twitter() {
        time=0;
    }
    
    void postTweet(int userId, int tweetId) {
        posts[userId].push_back({time++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<pair<int,int>> pp=posts[userId];
        for(int followerId:followers[userId]){
            pp.insert(pp.end(),posts[followerId].begin(),posts[followerId].end());
        }
        sort(pp.begin(),pp.end(),[](auto &a,auto &b){
            return a.first > b.first;
        });
        vector<int> res;
        for(int i=0;i<min((int)pp.size(),10);i++){
            res.push_back(pp[i].second);
        }
        return res;

    }
    
    void follow(int followerId, int followeeId) {
        if(followerId!=followeeId)
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};
