package com.example.taskManagementSystem.models;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

public class Task extends TaskComponent{
    private final List<Subtask> subtasks;

    public Task(String id, String title, String description, Date deadline, User assignedUser) {
        super(id, title, description, deadline, assignedUser, "-1");
        this.subtasks = new ArrayList<>();
    }
    @Override
    public void update(String title, String description, Date deadline, Status status, String parentTaskId) {
        this.title = title;
        this.description = description;
        this.deadline = deadline;
        this.status = status;
        this.parentTaskId = parentTaskId;
    }

    public List<Subtask> getSubtasks() {
        return subtasks;
    }

    public void removeSubtask(Subtask task){
        subtasks.remove(task);
    }
    public void addSubtask(Subtask task){
        subtasks.add(task);
    }
}
