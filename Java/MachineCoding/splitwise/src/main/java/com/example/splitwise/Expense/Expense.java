package com.example.splitwise.Expense;

import com.example.splitwise.Expense.Split.Split;
import com.example.splitwise.User.User;

import java.util.ArrayList;
import java.util.List;

public class Expense {
    private final String expenseId;
    private String description;
    private double expenseAmount;
    private User paidByUser;
    private ExpenseSplitType splitType;
    private List<Split> splitDetails = new ArrayList<>();

    public Expense(String expenseId, double expenseAmount, String description,
                   User paidByUser, ExpenseSplitType splitType, List<Split> splitDetails) {

        this.expenseId = expenseId;
        this.expenseAmount = expenseAmount;
        this.description = description;
        this.paidByUser = paidByUser;
        this.splitType = splitType;
        this.splitDetails.addAll(splitDetails);

    }

}
