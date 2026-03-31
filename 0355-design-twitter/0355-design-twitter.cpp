class Twitter {
public:
    int time;
    unordered_map<int, vector<pair<int,int>>> tweets;
    unordered_map<int, unordered_set<int>> following;

    Twitter() {
        time = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> res;

        // Max heap: {time, tweetId, userId, index}
        priority_queue<vector<int>> pq;

        // Ensure user follows himself
        following[userId].insert(userId);

        for (int user : following[userId]) {
            if (tweets[user].size() > 0) {
                int idx = tweets[user].size() - 1;
                auto &t = tweets[user][idx];
                pq.push({t.first, t.second, user, idx});
            }
        }

        while (!pq.empty() && res.size() < 10) {
            auto curr = pq.top(); pq.pop();

            int time = curr[0];
            int tweetId = curr[1];
            int user = curr[2];
            int idx = curr[3];

            res.push_back(tweetId);

            if (idx > 0) {
                auto &prev = tweets[user][idx - 1];
                pq.push({prev.first, prev.second, user, idx - 1});
            }
        }

        return res;
    }

    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId)
            following[followerId].erase(followeeId);
    }
};