package com.example.splitwise;

import com.example.splitwise.Expense.Split.Split;
import com.example.splitwise.User.User;

import java.util.List;
import java.util.Map;

public class BalanceSheetController {
    public void updateUserExpenseBalanceSheet(User expensePaidBy, List<Split> splits, double totalExpenseAmount){
        UserExpenseBalanceSheet paidByUserExpenseSheet = expensePaidBy.getUserExpenseBalanceSheet();
        // update paid user ki total payment,, usme kitna pay kia ajj tak total (include other share)
        paidByUserExpenseSheet.setTotalPayment(paidByUserExpenseSheet.getTotalPayment() + totalExpenseAmount);

        for(Split split: splits){
            User userOwe = split.getUser();
            UserExpenseBalanceSheet oweUserExpenseSheet = userOwe.getUserExpenseBalanceSheet();
            double oweAmount = split.getAmountOwe();

            if(expensePaidBy.getUserId().equals(userOwe.getUserId())){
                // if paying user same hai toh just uska total expense update kardo (exclude others)
                paidByUserExpenseSheet.setTotalYourExpense(paidByUserExpenseSheet.getTotalYourExpense() + oweAmount);
            } else {
                //update the balance of paid user
                //1. paid user ko total vapis kitne lena hai voh update karo
                paidByUserExpenseSheet.setTotalYouGetBack(paidByUserExpenseSheet.getTotalYouGetBack() + oweAmount);
                Balance userOweBalance;
                //2. check in userBalance map mein ki owe user se alrea kuch lena hai ya nahi
                if(paidByUserExpenseSheet.getUserVsBalance().containsKey(userOwe.getUserId())){
                    userOweBalance = paidByUserExpenseSheet.getUserVsBalance().get(userOwe.getUserId());
                } else {
                    userOweBalance = new Balance();
                    paidByUserExpenseSheet.getUserVsBalance().put(userOwe.getUserId(), userOweBalance);
                }
                userOweBalance.setAmountGetBack(userOweBalance.getAmountGetBack() + oweAmount);

                //update the balance sheet of owe user
                oweUserExpenseSheet.setTotalYouOwe(oweUserExpenseSheet.getTotalYouOwe() + oweAmount);
                oweUserExpenseSheet.setTotalYourExpense(oweUserExpenseSheet.getTotalYourExpense() + oweAmount);

                Balance userPaidBalance;
                if(oweUserExpenseSheet.getUserVsBalance().containsKey(expensePaidBy.getUserId())){
                    userPaidBalance = oweUserExpenseSheet.getUserVsBalance().get(expensePaidBy.getUserId());
                } else {
                    userPaidBalance = new Balance();
                    oweUserExpenseSheet.getUserVsBalance().put(expensePaidBy.getUserId(), userPaidBalance);
                }
                userPaidBalance.setAmountOwe(userPaidBalance.getAmountOwe() + oweAmount);
            }
        }
    }
    public void showBalanceSheetOfUser(User user){
        System.out.println("---------------------------------------");
        System.out.println("Balance sheet of user : " + user.getUserId());
        UserExpenseBalanceSheet userExpenseBalanceSheet = user.getUserExpenseBalanceSheet();
        System.out.println("TotalYourExpense: " + userExpenseBalanceSheet.getTotalYourExpense());
        System.out.println("TotalGetBack: " + userExpenseBalanceSheet.getTotalYouGetBack());
        System.out.println("TotalYourOwe: " + userExpenseBalanceSheet.getTotalYouOwe());
        System.out.println("TotalPaymentMade: " + userExpenseBalanceSheet.getTotalPayment());

        for(Map.Entry<String, Balance> entry: userExpenseBalanceSheet.getUserVsBalance().entrySet()){
            String userID = entry.getKey();
            Balance balance = entry.getValue();

            System.out.println("userID:" + userID + " YouGetBack:" + balance.getAmountGetBack() + " YouOwe:" + balance.getAmountOwe());
        }
        System.out.println("---------------------------------------");
    }
}
