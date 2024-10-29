package com.example.taskManagementSystem.models;

import java.util.ArrayList;
import java.util.List;

public class Story {
    private final String storyId;
    private final String name;
    private final List<Task> tasks;

    public Story(String storyId, String name){
        this.storyId = storyId;
        this.name = name;
        tasks = new ArrayList<>();
    }

    public String getStoryId() {
        return storyId;
    }

    public String getName(){
        return name;
    }

    public void addTask(Task task) {
        tasks.add(task);
    }

    public List<Task> getTasks() {
        return tasks;
    }
    public void removeTask(Task task){
        tasks.remove(task);
    }
}
