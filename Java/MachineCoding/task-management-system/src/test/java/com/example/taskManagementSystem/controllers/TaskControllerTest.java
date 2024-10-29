package com.example.taskManagementSystem.controllers;
import com.example.taskManagementSystem.models.Status;
import com.example.taskManagementSystem.models.Task;
import com.example.taskManagementSystem.models.TaskComponent;
import com.example.taskManagementSystem.models.User;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

import java.util.Calendar;
import java.util.Date;
import java.util.List;
import java.util.UUID;

public class TaskControllerTest {
    private TaskController taskController;
    private User user;
    Calendar date = Calendar.getInstance();
    @BeforeEach
    void setUp() {
        taskController = TaskController.getInstance();
        this.user = taskController.registerUser("prince", "Prince Mittall", "Password@123");
    }

    @Test
    void testCreateTask(){
        Task task = taskController.createTask("Design Database", "Design the database schema", date.getTime(), user);
        assertNotNull(task);
        assertEquals("Design Database", task.getTitle());
        assertEquals("Design the database schema", task.getDescription());
    }
    @Test
    void testUpdateTask() {
        try {
            Task task = taskController.createTask("Design Database", "Design the database schema", date.getTime(), user);
            taskController.updateTaskStatus(task.getId(), Status.ASSIGNED);
            TaskComponent updatedTask = taskController.getTaskById(task.getId());
            assertEquals(Status.ASSIGNED, task.getStatus());
        } catch (Exception e){
            System.out.println(e.getMessage());
        }
    }
}
