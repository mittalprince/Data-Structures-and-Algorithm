package com.example.taskManagementSystem.models;

import java.util.Date;
import java.util.UUID;

public class TaskFactory {
    public static Task createTask(String title, String description, Date deadline, User assignedUser) {
        return new Task(UUID.randomUUID().toString(), title, description, deadline, assignedUser);
    }

    public static Subtask createSubtask(String title, String description, Date deadline, User assignedUser, String parenttaskId) {
        return new Subtask(UUID.randomUUID().toString(), title, description, deadline, assignedUser, parenttaskId);
    }
}
