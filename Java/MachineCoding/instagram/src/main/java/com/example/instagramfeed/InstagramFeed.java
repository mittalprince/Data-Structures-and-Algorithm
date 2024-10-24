package com.example.instagramfeed;

import com.example.instagramfeed.actors.Actor;
import com.example.instagramfeed.actors.Influencer;
import com.example.instagramfeed.actors.User;
import com.example.instagramfeed.patterns.ActorFactory;
import com.example.instagramfeed.patterns.Follower;
import com.example.instagramfeed.post.Post;
import java.util.Scanner;

import java.util.HashMap;
import java.util.Map;

public class InstagramFeed {
    private static InstagramFeed instance;
    private Map<String, Influencer> influencers;
    private Map<String, User> users;
    private Map<String, Integer> hashtagFollowers;

    private ActorFactory actorFactory;

    private InstagramFeed() {
        this.influencers = new HashMap<>();
        this.users = new HashMap<>();
        this.hashtagFollowers = new HashMap<>();
        this.actorFactory = new ActorFactory();
    }

    public static InstagramFeed getInstance() {
        if (instance == null) {
            instance = new InstagramFeed();
        }
        return instance;
    }

    public void createActor(String actorType, String name) {
        Actor actor = actorFactory.createActor(actorType, name);
        if (actor instanceof Influencer) {
            influencers.put(name, (Influencer) actor);
        } else if (actor instanceof User) {
            users.put(name, (User) actor);
        }
    }

    public void follow(String entityType, String entityName, String userName) {
        User user = users.get(userName);
        Follower follower = new Follower(user);

        if (entityType.equalsIgnoreCase("Influencer")) {
            Influencer influencer = influencers.get(entityName);
            influencer.addFollower(follower);
            user.addFollower(follower); // Optional, for bidirectional management
        } else if (entityType.equalsIgnoreCase("Hashtag")) {
            hashtagFollowers.put(entityName, hashtagFollowers.getOrDefault(entityName, 0) + 1);
        }
    }

    public void post(String influencerName, String message, String... hashtags) {
        Influencer influencer = influencers.get(influencerName);
        String hashtag = hashtags.length > 0 ? hashtags[0] : "";

        Post newPost = new Post(message, influencer, hashtag);
        influencer.addPost(newPost);
    }

    public void fetch(String userName) {
        User user = users.get(userName);
        for (Post post : user.getFeed()) {
            System.out.println(post);
        }
    }

    public void showStats(String entityType, String name) {
        if (entityType.equalsIgnoreCase("Influencer")) {
            Influencer influencer = influencers.get(name);
            System.out.println(influencer.getFollowersCount());
        } else if (entityType.equalsIgnoreCase("Hashtag")) {
            System.out.println(hashtagFollowers.getOrDefault(name, 0));
        }
    }

    public void showPostStats(String influencerName, int postId) {
        Influencer influencer = influencers.get(influencerName);
        Post post = influencer.getPosts().stream()
                .filter(p -> p.getId() == postId)
                .findFirst()
                .orElse(null);

        if (post != null) {
            System.out.println(post.getViewCount());
        }
    }
    
    public static void main(String[] args) {
        InstagramFeed instagramFeed = InstagramFeed.getInstance();
        Scanner scanner = new Scanner(System.in);

        while (true) {
            String input = scanner.nextLine();
            String[] parts = input.split(" ");
            String command = parts[0];

            switch (command) {
                case "Create":
                    String actorType = parts[1];
                    String name = parts[2];
                    instagramFeed.createActor(actorType, name);
                    System.out.println("Created " + actorType + " " + name);
                    break;

                case "Follow":
                    String entityType = parts[1];
                    String entityName = parts[2];
                    String userName = parts[3];
                    instagramFeed.follow(entityType, entityName, userName);
                    System.out.println(userName + " followed " + entityType + " " + entityName);
                    break;

                case "Post":
                    String influencerName = parts[1];
                    String message = parts[2];
                    String hashtag = parts.length > 3 ? parts[3] : "";
                    instagramFeed.post(influencerName, message, hashtag);
                    System.out.println("Post created by " + influencerName);
                    break;

                case "Fetch":
                    String userToFetch = parts[1];
                    System.out.println("Fetching feed for " + userToFetch);
                    instagramFeed.fetch(userToFetch);
                    break;

                case "Stats":
                    if (parts.length == 3) {
                        String entity = parts[1];
                        String entityNameForStats = parts[2];
                        instagramFeed.showStats(entity, entityNameForStats);
                    } else if (parts.length == 4) {
                        influencerName = parts[1];
                        int postId = Integer.parseInt(parts[3]);
                        instagramFeed.showPostStats(influencerName, postId);
                    }
                    break;

                case "Exit":
                    System.out.println("Exiting application.");
                    return;

                default:
                    System.out.println("Unknown command.");
                    break;
            }
        }
    }
}
