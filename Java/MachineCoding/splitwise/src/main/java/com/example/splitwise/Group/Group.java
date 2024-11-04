package com.example.splitwise.Group;

import com.example.splitwise.Expense.Expense;
import com.example.splitwise.Expense.ExpenseController;
import com.example.splitwise.Expense.ExpenseSplitType;
import com.example.splitwise.Expense.Split.Split;
import com.example.splitwise.User.User;

import java.util.ArrayList;
import java.util.List;

public class Group {
    private String groupId;
    private String groupName;
    private List<User> groupMembers;
    private List<Expense> expenseList;
    ExpenseController expenseController;

    Group(){
        groupMembers = new ArrayList<>();
        expenseList = new ArrayList<>();
        expenseController = new ExpenseController();
    }
    //add member to group
    public void addMember(User member){
        groupMembers.add(member);
    }

    public String getGroupId() {
        return groupId;
    }

    public void setGroupId(String groupId) {
        this.groupId = groupId;
    }

    public void setGroupName(String groupName) {
        this.groupName = groupName;
    }
    public Expense createExpense(String expenseId, String description, double expenseAmount, List<Split> splitDetails, ExpenseSplitType splitType, User paidByUser){
        Expense expense = expenseController.createExpense(expenseId,description,expenseAmount,splitDetails,splitType,paidByUser);
        expenseList.add(expense);
        return expense;
    }
}
