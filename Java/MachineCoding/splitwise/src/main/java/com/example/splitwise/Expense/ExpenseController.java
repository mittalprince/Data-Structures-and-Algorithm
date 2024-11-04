package com.example.splitwise.Expense;
import java.util.List;

import com.example.splitwise.BalanceSheetController;
import com.example.splitwise.Expense.Split.ExpenseSplit;
import com.example.splitwise.Expense.Split.Split;
import com.example.splitwise.User.User;

public class ExpenseController {
    BalanceSheetController balanceSheetController;
    public ExpenseController(){
        balanceSheetController = new BalanceSheetController();
    }

    public Expense createExpense(String expenseId, String description, double expenseAmount, List<Split> splitDetails, ExpenseSplitType splitType, User paidByUser){
        ExpenseSplit expenseSplit = SplitFactory.getSplitObject(splitType);
        expenseSplit.validateSplitRequest(splitDetails, expenseAmount);

        Expense expense = new Expense(expenseId, expenseAmount, description, paidByUser, splitType, splitDetails);
        balanceSheetController.updateUserExpenseBalanceSheet(paidByUser, splitDetails, expenseAmount);
        return expense;
    }
}
