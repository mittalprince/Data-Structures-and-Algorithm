package com.example.taskManagementSystem.models;

import java.util.Date;
import java.util.List;

public abstract class TaskComponent {
    protected String id;
    protected String title;
    protected String description;
    protected Date deadline;
    protected Status status;
    protected User assignedUser;
    protected String parentTaskId;

    public TaskComponent(String id, String title, String description, Date deadline, User assignedUser, String parentTaskId) {
        this.id = id;
        this.title = title;
        this.description = description;
        this.deadline = deadline;
        this.status = Status.PENDING;
        this.assignedUser = assignedUser;
        this.parentTaskId = parentTaskId;
    }

    public String getId() {
        return id;
    }

    public String getTitle() {
        return title;
    }

    public String getDescription() {
        return description;
    }

    public Date getDeadline() {
        return deadline;
    }

    public Status getStatus() {
        return status;
    }

    public User getAssignedUser() {
        return assignedUser;
    }

    public void assignUser(User user) {
        this.assignedUser = user;
    }
    public String getParentTaskId(){ return parentTaskId; }
    public abstract void update(String title, String description, Date deadline, Status status, String parentTaskId);
//    public abstract List<TaskComponent> getSubtasks();
}
