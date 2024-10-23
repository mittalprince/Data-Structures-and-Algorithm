package com.example.instagramfeed;

import java.util.ArrayList;
import java.util.List;

public class Influencer extends Actor {
    private List<Post> posts;
    private int followersCount;

    public Influencer(String name) {
        super(name);
        posts = new ArrayList<>();
        followersCount = 0;
    }

    public void addPost(Post post) {
        posts.add(post);
    }

    public void removePost(int postId) {
        posts.removeIf(p -> p.getId() == postId);
    }

    public List<Post> getPosts() {
        return posts;
    }

    public int getFollowersCount() {
        return followersCount;
    }

    public void incrementFollowers() {
        this.followersCount++;
    }

    public void decrementFollowers() {
        if (followersCount > 0) {
            followersCount--;
        }
    }
}
