#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
using namespace std;

class Twitter {
private:
    int timestamp;
    unordered_map<int, vector<pair<int,int>>> tweets;
    unordered_map<int, unordered_set<int>> following;

public:
    Twitter() : timestamp(0) {}

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        // (timestamp, tweetId, userId, index)
        priority_queue<tuple<int,int,int,int>> pq;
        if (tweets.count(userId) && !tweets[userId].empty()) {
            int idx = tweets[userId].size() - 1;
            auto& [ts, tid] = tweets[userId][idx];
            pq.push({ts, tid, userId, idx});
        }
        if (following.count(userId)) {
            for (int followee : following[userId]) {
                if (tweets.count(followee) && !tweets[followee].empty()) {
                    int idx = tweets[followee].size() - 1;
                    auto& [ts, tid] = tweets[followee][idx];
                    pq.push({ts, tid, followee, idx});
                }
            }
        }

        vector<int> result;
        while (!pq.empty() && result.size() < 10) {
            auto [ts, tid, uid, idx] = pq.top();
            pq.pop();
            result.push_back(tid);
            if (idx > 0) {
                int newIdx = idx - 1;
                auto& [nts, ntid] = tweets[uid][newIdx];
                pq.push({nts, ntid, uid, newIdx});
            }
        }
        return result;
    }

    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
int main() {
    Spreadsheet sp(3);

    cout << "=5+7  -> " << sp.getValue("=5+7") << endl;   // 12

    sp.setCell("A1", 10);
    cout << "=A1+6 -> " << sp.getValue("=A1+6") << endl;  // 16

    sp.setCell("B2", 15);
    cout << "=A1+B2 -> " << sp.getValue("=A1+B2") << endl; // 25

    sp.resetCell("A1");
    cout << "=A1+B2 (A1 reset) -> " << sp.getValue("=A1+B2") << endl; // 15

    return 0;
}


/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
