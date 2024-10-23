package com.example.instagramfeed;

import java.util.*;

public class User extends Actor {
    public Set<Influencer> followedInfluencers;
    public Set<String> followedHashtags;
    private List<Post> feed;

    public User(String namme) {
        super(namme);
        this.followedInfluencers = new HashSet<>();
        this.followedHashtags = new HashSet<>();
        this.feed = new ArrayList<>();
    }

    public void followInfluencer(Influencer influencer) {
        followedInfluencers.add(influencer);
        influencer.incrementFollowers();
    }

    public void unFollowInfluencer(Influencer influencer) {
        followedInfluencers.remove(influencer);
        influencer.decrementFollowers();
    }

    public void followHashtag(String hashtag) {
        followedHashtags.add(hashtag);
    }

    public void addToFeed(Post post) {
        feed.add(post);
    }

    public List<Post> getFeed() {
        feed.sort((a, b) -> b.getCreationTime().compareTo(a.getCreationTime()));
        return feed;
    }
}
