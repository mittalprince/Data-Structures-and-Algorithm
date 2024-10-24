package com.example.instagramfeed.actors;

import com.example.instagramfeed.post.Post;

import java.util.ArrayList;
import java.util.List;

public class User extends Actor {
    private List<Post> feed;

    public User(String name) {
        super(name);
        this.feed = new ArrayList<>();
    }

    public void addToFeed(Post post) {
        feed.add(post);
    }

    public List<Post> getFeed() {
        feed.sort((a, b) -> b.getCreationTime().compareTo(a.getCreationTime()));
        return feed;
    }
}
