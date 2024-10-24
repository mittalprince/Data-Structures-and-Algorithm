package org.example.vendingMachine;
import java.util.*;

public class ItemFactory {
    public static Item createItem(char type, int price) {
        return new Item(type, price);
    }
}
/*
The ItemFactory class creates an Item based on the type and the corresponding price.
This helps abstract the creation process, which is useful if the process of creating items becomes more complex in the future
 */