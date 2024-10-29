package com.example.taskManagementSystem.models;

import java.util.Collections;
import java.util.Date;
import java.util.List;

public class Subtask extends TaskComponent{

    public Subtask(String id, String title, String description, Date deadline, User assignedUser, String parentId) {
        super(id, title, description, deadline, assignedUser, parentId);
    }
    @Override
    public void update(String title, String description, Date deadline, Status status, String parentTaskId) {
        this.title = title;
        this.description = description;
        this.deadline = deadline;
        this.status = status;
        this.parentTaskId = parentTaskId;
    }
}
