package com.example.instagramfeed.patterns;

import com.example.instagramfeed.actors.Actor;
import com.example.instagramfeed.actors.Influencer;
import com.example.instagramfeed.actors.User;

public class ActorFactory {
    public Actor createActor(String actorType, String name) {
        if (actorType.equalsIgnoreCase("Influencer")) {
            return new Influencer(name);
        } else if (actorType.equalsIgnoreCase("User")) {
            return new User(name);
        }
        throw new IllegalArgumentException("Unknown actor type: " + actorType);
    }
}
