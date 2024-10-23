package com.example.instagramfeed;

import java.util.*;

public class InstagramFeed {
    private Map<String, Influencer> influencers;
    private Map<String, User> users;
    private Map<String, Set<User>> hashtagFollowers;

    public InstagramFeed() {
        this.influencers = new HashMap<>();
        this.users = new HashMap<>();
        this.hashtagFollowers = new HashMap<>();
    }

    public void createActor(String actorType, String name) {
        if (actorType.equalsIgnoreCase("Influencer")) {
            influencers.put(name, new Influencer(name));
        } else if (actorType.equalsIgnoreCase("User")) {
            users.put(name, new User(name));
        }
    }

    public void follow(String entityType, String entityName, String userName) {
        User user = users.get(userName);
        if (entityType.equalsIgnoreCase("Influencer")) {
            Influencer influencer = influencers.get(entityName);
            user.followInfluencer(influencer);
        } else if (entityType.equalsIgnoreCase("Hashtag")) {
            user.followHashtag(entityName);
            hashtagFollowers.computeIfAbsent(entityName, k -> new HashSet<>()).add(user);
        }
    }

    public void post(String influencerName, String message, String... hashTags) {
        Influencer influencer = influencers.get(influencerName);
        String hashTag = hashTags.length > 0 ? hashTags[0] : "";

        Post post = new Post(message, influencer, hashTag);
        influencer.addPost(post);

        for (User user : users.values()) {
            if (user.followedInfluencers.contains(influencer) || user.followedHashtags.contains(hashTag)) {
                user.addToFeed(post);
            }
        }
    }

    public void fetch(String userName) {
        User user = users.get(userName);
        List<Post> posts = user.getFeed();
        for (Post post : posts) {
            System.out.println(post);
        }
    }

    public void showStats(String entityType, String name) {
        if (entityType.equalsIgnoreCase("Influencer")) {
            Influencer influencer = influencers.get(name);
            System.out.println(influencer.getFollowersCount());
        } else if (entityType.equalsIgnoreCase("Hashtag")) {
            Set<User> followers = hashtagFollowers.get(name);
            System.out.println(followers == null ? 0 : followers.size());
        }
    }

    public void showPostStats(String influencerName, int postId) {
        Influencer influencer = influencers.get(influencerName);
        for (Post post : influencer.getPosts()) {
            if (post.getId() == postId) {
                System.out.println(post.getViewCount());
                return;
            }
        }
    }

    public static void main(String agrs[]) {
        InstagramFeed app = new InstagramFeed();
        app.createActor("Influencer", "Samay");
        app.createActor("User", "RK");
        app.createActor("User", "JSP");
        app.createActor("User", "AJ");

        app.follow("Influencer", "Samay", "RK");
        app.post("Samay", "This is Sparta", "#war");

        app.follow("Hashtag", "#war", "RK");
        app.fetch("RK");

        app.createActor("Influencer", "AIB");
        app.follow("Influencer", "AIB", "JSP");
        app.follow("Influencer", "AIB", "AJ");
        app.post("AIB", "A King may move a man...", "#war");

        app.fetch("RK");
        app.showStats("Influencer", "AIB");

        app.follow("Influencer", "AIB", "RK");
        app.showStats("Influencer", "Samay");
        app.showStats("Influencer", "AIB");
        app.showPostStats("AIB", 2);
    }
}
