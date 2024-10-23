package com.example.instagramfeed;

import java.util.Date;

public class Post {
    private static int idCounter = 1;
    private int id;
    private String message;
    private String hashtag;
    private Influencer influencer;
    private Date creationTime;
    private int viewCount;

    public Post(String message, Influencer influencer, String hashtag) {
        this.id = idCounter++;
        this.message = message;
        this.influencer = influencer;
        this.hashtag = hashtag;
        this.creationTime = new Date();
        this.viewCount = 0;
    }

    public int getId() {
        return id;
    }

    public String getMessage() {
        return message;
    }

    public String getHashtag() {
        return hashtag;
    }

    public Influencer getInfluencer() {
        return influencer;
    }

    public Date getCreationTime() {
        return creationTime;
    }

    public void incrementViewCount() {
        viewCount++;
    }

    public int getViewCount() {
        return viewCount;
    }

    @Override
    public String toString() {
        return "Post Id " + id + ": " + influencer.getName() + ": \"" + message + "\"";
    }
}
