package com.example.instagramfeed.actors;

import com.example.instagramfeed.post.Post;
import com.example.instagramfeed.patterns.Observer;

import java.util.ArrayList;
import java.util.List;

public abstract class Actor {
    private String name;
    protected List<Observer> followers;

    public Actor(String name) {
        this.name = name;
        this.followers = new ArrayList<>();
    }

    public String getName() {
        return name;
    }

    public void addFollower(Observer follower) {
        followers.add(follower);
    }

    public void removeFollower(Observer follower) {
        followers.remove(follower);
    }

    protected void notifyFollowers(Post post) {
        for (Observer follower : followers) {
            follower.update(post);
        }
    }
}
