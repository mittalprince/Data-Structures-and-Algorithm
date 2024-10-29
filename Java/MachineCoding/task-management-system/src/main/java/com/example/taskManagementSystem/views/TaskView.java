package com.example.taskManagementSystem.views;

import com.example.taskManagementSystem.models.Story;
import com.example.taskManagementSystem.models.Task;
import com.example.taskManagementSystem.models.TaskComponent;
import com.example.taskManagementSystem.models.User;

import java.text.SimpleDateFormat;
import java.util.Date;

public class TaskView {
    private static final SimpleDateFormat DATE_FORMAT = new SimpleDateFormat("dd-MM-yyyy HH:mm");
    public void displayTaskDetails(Task task){
        System.out.println("Task ID: " + task.getId());
        System.out.println("Title: " + task.getTitle());
        System.out.println("Description: " + task.getDescription());
        System.out.println("Deadline: " + formatDate(task.getDeadline()));
        System.out.println("Status: " + task.getStatus());
        if (task.getAssignedUser() != null) {
            System.out.println("Assigned User: " + task.getAssignedUser().getName());
        }
        System.out.println("Subtasks: " + task.getSubtasks().size());
        for (TaskComponent subtask : task.getSubtasks()) {
            displaySubtaskDetails(subtask);
        }
        System.out.println("--------------------------------------------------");
    }

    private void displaySubtaskDetails(TaskComponent subtask) {
        System.out.println("   - Subtask ID: " + subtask.getId());
        System.out.println("     Title: " + subtask.getTitle());
        System.out.println("     Description: " + subtask.getDescription());
        System.out.println("     Deadline: " + formatDate(subtask.getDeadline()));
        System.out.println("     Status: " + subtask.getStatus());
    }

    public void displayStoryDetails(Story story) {
        System.out.println("Story ID: " + story.getStoryId() + " Name: " + story.getName());
        for (Task task : story.getTasks()) {
            displayTaskDetails(task);
        }
    }

    public void displayUserWorkload(User user) {
        System.out.println("User ID: " + user.getUserId());
        System.out.println("User Name: " + user.getName());
        System.out.println("Workload: " + user.getTasks().size() + " tasks assigned");

        int assigned = 0, pending = 0, inProgress = 0, completed = 0;
        for (Task task : user.getTasks()) {
            switch (task.getStatus()) {
                case ASSIGNED:
                    assigned++;
                    break;
                case PENDING:
                    pending++;
                    break;
                case IN_PROGRESS:
                    inProgress++;
                    break;
                case COMPLETED:
                    completed++;
                    break;
                default:
                    break;
            }
        }

        System.out.println("Assigned Tasks: " + assigned);
        System.out.println("Pending Tasks: " + pending);
        System.out.println("In-Progress Tasks: " + inProgress);
        System.out.println("Completed Tasks: " + completed);
        System.out.println("--------------------------------------------------");
    }
    private String formatDate(Date date) {
        return DATE_FORMAT.format(date);
    }
}
