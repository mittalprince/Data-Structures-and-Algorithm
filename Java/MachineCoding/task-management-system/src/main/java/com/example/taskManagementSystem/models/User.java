package com.example.taskManagementSystem.models;
import java.util.List;
import java.util.ArrayList;
public class User {
    private final String userId;
    private final String name;
    private final String password;
    private final List<Task> tasks;

    public User(String userId, String name, String password) {
        this.userId = userId;
        this.name = name;
        this.password = password;
        this.tasks = new ArrayList<>();
    }

    public java.lang.String getName() {return name;}
    public String getUserId(){return userId;}
    public boolean authenticate(String password){
        return this.password.equals(password);
    }
    public List<Task> getTasks() {
        return tasks;
    }

    public void assignTask(Task task) {
        tasks.add(task);
    }
    public void removeUserTask(Task task){
        tasks.remove(task);
    }
}
