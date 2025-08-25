class Twitter {
    int timestamp; 

    // userId -> list of {timestamp, tweetId}
    unordered_map<int, vector<pair<int,int>>> tweets;

    // followerId -> set of followeeIds
    unordered_map<int, unordered_set<int>> followers;

public:
    Twitter() {
        timestamp = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId});
    }

    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;

        // max-heap to get tweets by most recent timestamp
        auto cmp = [](pair<int,int> &a, pair<int,int> &b) {
            return a.first < b.first; // max-heap by timestamp
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);

        for(auto &t : tweets[userId])
            pq.push(t);

        for(int followeeId : followers[userId]) {
            for(auto &t : tweets[followeeId])
                pq.push(t);
        }

        int count = 0;
        while(!pq.empty() && count < 10) {
            ans.push_back(pq.top().second);
            pq.pop();
            count++;
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {
        if(followerId != followeeId)
            followers[followerId].insert(followeeId);
    }


    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};
