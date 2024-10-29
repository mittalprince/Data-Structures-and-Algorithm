package com.example;

import com.example.taskManagementSystem.controllers.TaskController;
import com.example.taskManagementSystem.models.*;
import com.example.taskManagementSystem.views.TaskView;

import java.util.Calendar;
import java.util.UUID;

public class Main {
    public static void main(String[] args) {
        TaskController controller = TaskController.getInstance();
        TaskView taskView = new TaskView();
        User user = controller.registerUser("prince", "Prince Mittal", "Password@123");

        try {
            if (controller.loginUser("prince", "Password@123") != null) {
                System.out.println("Login successful for user: " + user.getUserId());

                Calendar date = Calendar.getInstance();
                Task task = controller.createTask("Task 1", "A random task with random desc", date.getTime(), user);

                Subtask subTask = controller.createSubtask(task.getId(), "Subtask 1", "subtask 1 under task1", date.getTime(), user);
                Story story = controller.createStory(UUID.randomUUID().toString(), "Story 1");
                story.addTask(task);
                Story story2 = controller.createStory(UUID.randomUUID().toString(), "Story 2");

                System.out.println("Before moving task");
                taskView.displayStoryDetails(story);
                taskView.displayStoryDetails(story2);
                controller.moveTask(task.getId(), story2.getStoryId());

                System.out.println("After moving task");
                taskView.displayStoryDetails(story);
                taskView.displayStoryDetails(story2);

                taskView.displayUserWorkload(user);
                controller.updateTaskStatus(task.getId(), Status.ASSIGNED);
                System.out.println("Task Status Changed");
                taskView.displayUserWorkload(user);

                Task task2 = controller.createTask("Task 2", "A random task2 with random desc", date.getTime(), user);
                Subtask subTask2 = controller.createSubtask(task2.getId(), "Subtask 2", "subtask 2 under task1", date.getTime(), user);
                story.addTask(task2);
                System.out.println("Before moving task");
                taskView.displayStoryDetails(story);
                taskView.displayStoryDetails(story2);
                controller.moveTask(subTask2.getId(), task.getId());

                System.out.println("After moving task");
                taskView.displayStoryDetails(story);
                taskView.displayStoryDetails(story2);
                taskView.displayUserWorkload(user);

                System.out.println("After moving task to another story");
                controller.moveTask(task.getId(), story.getStoryId());
                taskView.displayStoryDetails(story);
                taskView.displayStoryDetails(story2);

            } else {
                System.out.println("Login failed");
            }
        } catch (Exception e){
            System.out.println(e.getMessage());
        }
    }
}