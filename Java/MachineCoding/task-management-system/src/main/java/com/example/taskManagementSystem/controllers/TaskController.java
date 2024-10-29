package com.example.taskManagementSystem.controllers;

import com.example.taskManagementSystem.models.*;

import java.util.Date;
import java.util.HashMap;
import java.util.Map;

public class TaskController {
    private static TaskController instance;
    private Map<String, User> users;
    private Map<String, TaskComponent> tasks;
    private Map<String, Story> stories;

    private TaskController() {
        this.users = new HashMap<>();
        this.tasks = new HashMap<>();
        this.stories = new HashMap<>();
    }

    public static TaskController getInstance(){
        if (instance == null) {
            instance = new TaskController();
        }
        return instance;
    }

    public User registerUser(String userId, String name, String password){
        User user = new User(userId, name, password);
        users.put(userId, user);
        return user;
    }

    public User loginUser(String userId, String password){
        User user = users.get(userId);
        return (user != null && user.authenticate(password)) ? user : null;
    }

    public Task createTask(String title, String description, Date deadline, User assignedUser){
        Task task = TaskFactory.createTask(title, description, deadline, assignedUser);
        tasks.put(task.getId(), task);
        assignedUser.assignTask(task);
        return task;
    }

    public Subtask createSubtask(String parentTaskId, String title, String description, Date deadline, User assignedUser){
        Task parentTask = (Task) tasks.get(parentTaskId);
        if (parentTask == null) return null;
        Subtask subtask = TaskFactory.createSubtask(description, title, deadline, assignedUser, parentTaskId);
        parentTask.addSubtask(subtask);
        tasks.put(subtask.getId(), subtask);
        return subtask;
    }

    public Story createStory(String storyId, String name){
        Story story = new Story(storyId, name);
        stories.put(storyId, story);
        return story;
    }
    public void moveTask(String taskId, String newParentId) throws Exception{
        TaskComponent task = getTaskById(taskId);
        TaskComponent parentTask = tasks.get(newParentId);
        Story parentStory = stories.get(newParentId);

        if(task == null) return;
        if(parentTask == null && parentStory == null) {
            System.out.println("Invalid parentId");
            throw new Exception("Invalid parentId");
        }
        if(parentTask != null) moveSubTaskToTask(taskId, newParentId);
        else moveTaskToStory(taskId, newParentId);
    }

    private void moveTaskToStory(String taskId, String newStoryId) throws Exception{
        TaskComponent task = getTaskById(taskId);
        Story story = stories.get(newStoryId);

        if (task instanceof Task && story != null) {
            for (Story s : stories.values()) {
                s.getTasks().remove(task);
            }
            story.addTask((Task) task);
        }
    }
    private void moveSubTaskToTask(String subtaskId, String newParentTaskId) throws Exception{
        Subtask subtask = (Subtask) getTaskById(subtaskId);
        Task oldParent = (Task) getTaskById(subtask.getParentTaskId());
        Task newParent = (Task) getTaskById(newParentTaskId);

        oldParent.removeSubtask(subtask);
        newParent.addSubtask(subtask);
        updateTaskParentId(subtaskId, newParentTaskId);
    }

    public void updateTaskStatus(String taskId, Status status) throws Exception{
        TaskComponent task = getTaskById(taskId);
        task.update(task.getTitle(), task.getDescription(), task.getDeadline(), status, task.getParentTaskId());
    }

    public void updateTaskParentId(String taskId, String parentTaskId) throws Exception{
        TaskComponent task = getTaskById(taskId);
        task.update(task.getTitle(), task.getDescription(), task.getDeadline(), task.getStatus(), parentTaskId);
    }
    public TaskComponent getTaskById(String taskId) throws Exception{
        TaskComponent task = tasks.get(taskId);
        if(task == null){
            System.out.println("Invalid task Id");
            throw new Exception("Invalid TaskId, task doesn't exist");
        }
        return task;
    }
}
