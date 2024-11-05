package com.example.splitwise;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Main {
    public static void main(String[] args) {
        Splitwise splitwise = new Splitwise();
        splitwise.demo();
    }
    public int simplyDebts(int[][] transactions){
        Map<Integer, Integer> membersVsBalanceMap = new HashMap<>();
        for(int[] transaction: transactions){
            int from = transaction[0];
            int to = transaction[1];
            int amt = transaction[2];

            membersVsBalanceMap.put(from, membersVsBalanceMap.getOrDefault(from, 0) - amt);
            membersVsBalanceMap.put(to, membersVsBalanceMap.getOrDefault(to, 0) - amt);
        }

        List<Integer>balances = new ArrayList<>();
        for(int amt: membersVsBalanceMap.values()){
            if(amt != 0) balances.add(amt);
        }
        return dfs(balances, 0);
    }
    private int dfs(List<Integer> balanceList, int currentIndex){
        if(balanceList.isEmpty() || currentIndex>balanceList.size())return 0;
        if(balanceList.get(currentIndex) == 0) return 0;
        int currentVal = balanceList.get(currentIndex);
        int minTnxCount = Integer.MAX_VALUE;
        for(int i=currentIndex+1; i<balanceList.size(); i++){
            int nextVal = balanceList.get(i);
            if(nextVal * currentVal < 0){
                balanceList.set(i, currentVal + nextVal);
                minTnxCount = Math.min(minTnxCount, 1 + dfs(balanceList, currentIndex+1));
                balanceList.set(i, nextVal);

                if(nextVal + currentVal == 0)break;
            }
        }
        return minTnxCount;
    }
}