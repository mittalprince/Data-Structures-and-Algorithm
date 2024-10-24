package com.example.instagramfeed.patterns;

import com.example.instagramfeed.post.Post;

public interface Observer {
    void update(Post post);
}
