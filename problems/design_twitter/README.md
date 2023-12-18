# Design Twitter

## Leetcode Link: [Design Twitter](https://leetcode.com/problems/design-twitter/)
### Language: C++

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Relation
{
public:
    int userId;
    int tweetId;
    Relation(int a, int b)
    {
        userId = a;
        tweetId = b;
    }

    Relation()
    {
        userId = 0;
        tweetId = 0;
    }
    // Comparator for set
    bool operator<(const Relation &a) const
    {
        return tweetId < a.tweetId;
    }
    bool operator==(const Relation &a) const
    {
        return tweetId == a.tweetId;
    }
    bool operator>(const Relation &a) const
    {
        return tweetId > a.tweetId;
    }
};

class Twitter
{
public:
    // pair<int, struct Relation> is used to store the tweetId and the Relation object
    set<pair<int, struct Relation>, greater<pair<int, struct Relation>>> tweets;
    // map of userId to set of userIds that the user follows
    map<int, set<int>> followingRelations;
    // currPostId is used to assign a unique id to each tweet
    int currPostId;

    Twitter()
    {
        currPostId = 0;
    }

    void postTweet(int userId, int tweetId)
    {
        // Create a Relation object and insert it into the set
        struct Relation tweetUserRelation = Relation(userId, tweetId);
        pair<int, struct Relation> tweetUserRelationWithId = make_pair(currPostId++, tweetUserRelation);
        tweets.insert(tweetUserRelationWithId);
        return;
    }

    vector<int> getNewsFeed(int userId)
    {
        vector<int> ans;
        // Get the set of userIds that the user follows
        auto following = followingRelations[userId];
        int currCount = 0;

        // Iterate over the set of tweets and add the tweetId to the ans vector
        // if the user is following the user who posted the tweet
        for (auto i = tweets.begin(); i != tweets.end(); i++)
        {
            if (currCount >= 10)
                break;
            int userIdOfPost = (*i).second.userId;
            int tweetIdOfPost = (*i).second.tweetId;

            // If the user is following the user who posted the tweet or
            // the user is the one who posted the tweet
            bool isPostedByUser = userIdOfPost == userId;
            bool isTheUserFollowing = following.count(userIdOfPost) == 1;
            if ( isPostedByUser or isTheUserFollowing )
            {
                ans.push_back(tweetIdOfPost);
                currCount++;
            }
        }

        return ans;
    }

    void follow(int followerId, int followeeId)
    {
        // Insert the followeeId into the set of userIds that the follower follows
        followingRelations[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        // Remove the followeeId from the set of userIds that the follower follows
        followingRelations[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */```



