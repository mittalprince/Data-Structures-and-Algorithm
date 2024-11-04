package com.example.splitwise.Expense.Split;

import java.util.List;

public interface ExpenseSplit {
    void validateSplitRequest(List<Split> splitList, double totalAmount);
}
