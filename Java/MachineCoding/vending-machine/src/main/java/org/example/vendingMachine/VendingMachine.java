package org.example.vendingMachine;
import java.util.*;
import org.example.vendingMachine.Item;

public class VendingMachine {
    private static VendingMachine vendingMachine;
    private int capacity;
    private List<Item> items;
    private Map<Character, Integer> prices;
    private int cashEarned;

    public VendingMachine(int capacity){
        this.capacity = capacity;
        this.items = new ArrayList<>();
        this.prices = new HashMap<>();
        this.cashEarned = 0;
    }

    public static VendingMachine getInstance(int capacity){
        if(vendingMachine == null){
            vendingMachine = new VendingMachine(capacity);
        }
        return vendingMachine;
    }

    public void setPrices(int[] priceArray) {
        char type = 'A';
        for(int i=0; i<26; i++){
            prices.put(type, priceArray[i]);
            type++;
        }
        System.out.println("Prices set: " + prices);
    }

    public void insertItem(char type){
        if(items.size() >= capacity){
            System.out.println("Insufficient space");
            return;
        }
        try {
            Item item = ItemFactory.createItem(type, prices.get(type));
            items.add(item);
            System.out.println("Inserted item at " + (items.size()) + " " + type);
        } catch (IllegalArgumentException e){
            System.out.println(e.getMessage());
        }
    }

    public void get(int slotIndex, int payment){
        if(slotIndex > items.size() || slotIndex < 1){
            System.out.println("Item not available");
            return;
        }
        int totalCost = 0;
        for(int i=0; i<slotIndex; i++){
            totalCost += items.get(i).getPrice();
        }
        if(payment < totalCost){
            System.out.println("Insufficient amount for " + items.get(slotIndex - 1).getType());
            return;
        }
        System.out.print("Dispensing");
        for (int i = 0; i < slotIndex; i++) {
            System.out.print(" " + items.get(i).getType());
        }
        System.out.println();

        items.subList(0, slotIndex).clear();
        cashEarned += totalCost;
    }

    public int getCurrentItemCount() {
        return items.size();
    }

    public int getTotalEarnings() {
        return cashEarned;
    }

    public void status() {
        System.out.println("Available: " + getCurrentItemCount());
        System.out.println("Can earn: " + calculateRemainingCash());
        System.out.println("Has earned: " + getTotalEarnings());
    }

    public int calculateRemainingCash(){
        int total = 0;
        for(Item i: items){
            total += i.getPrice();
        }
        return  total;
    }
}
