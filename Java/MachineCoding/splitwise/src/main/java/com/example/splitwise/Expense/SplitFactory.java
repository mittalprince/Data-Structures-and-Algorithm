package com.example.splitwise.Expense;

import com.example.splitwise.Expense.Split.EqualExpenseSplit;
import com.example.splitwise.Expense.Split.ExpenseSplit;
import com.example.splitwise.Expense.Split.PercentageExpenseSplit;
import com.example.splitwise.Expense.Split.UnequalExpenseSplit;

public class SplitFactory {
    public static ExpenseSplit getSplitObject(ExpenseSplitType splitType){
        switch (splitType){
            case EQUAL:
                return new EqualExpenseSplit();
            case UNEQUAL:
                return new UnequalExpenseSplit();
            case PERCENTAGE:
                return new PercentageExpenseSplit();
            default:
                return null;
        }
    }
}
