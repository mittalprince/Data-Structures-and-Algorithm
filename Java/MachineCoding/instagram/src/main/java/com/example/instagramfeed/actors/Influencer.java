package com.example.instagramfeed.actors;

import com.example.instagramfeed.post.Post;

import java.util.ArrayList;
import java.util.List;

public class Influencer extends Actor {
    private List<Post> posts;

    public Influencer(String name) {
        super(name);
        this.posts = new ArrayList<>();
    }

    public void addPost(Post post) {
        posts.add(post);
        notifyFollowers(post);
    }

    public void removePost(int postId) {
        posts.removeIf(p -> p.getId() == postId);
    }

    public List<Post> getPosts() {
        return posts;
    }

    public int getFollowersCount() {
        return followers.size();
    }
}
