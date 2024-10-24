package com.example.instagramfeed.patterns;

import com.example.instagramfeed.post.Post;
import com.example.instagramfeed.actors.User;

public class Follower implements Observer {
    private User user;

    public Follower(User user) {
        this.user = user;
    }

    @Override
    public void update(Post post) {
        user.addToFeed(post);
    }
}
