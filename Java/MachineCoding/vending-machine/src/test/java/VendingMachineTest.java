import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.example.vendingMachine.*;

public class VendingMachineTest {

    private VendingMachine vendingMachine;

    @BeforeEach
    public void setUp() {
        vendingMachine = VendingMachine.getInstance(5); // Initialize with capacity of 5
        int[] prices = {10, 20, 30, 5, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26};
        vendingMachine.setPrices(prices);
    }

    @Test
    public void testSingletonInstance() {
        VendingMachine anotherInstance = VendingMachine.getInstance(10);
        assertSame(vendingMachine, anotherInstance, "VendingMachine should be a singleton instance");
    }

    @Test
    public void testInsertItem_Success() {
        vendingMachine.insertItem('A');
        assertEquals(1, vendingMachine.getCurrentItemCount());
    }

//    @Test
//    public void testInsertItem_InsufficientSpace() {
//        vendingMachine.insertItem('A');
//        vendingMachine.insertItem('B');
//        vendingMachine.insertItem('C');
//        vendingMachine.insertItem('D');
//        vendingMachine.insertItem('E');
//        vendingMachine.insertItem('F'); // This should exceed capacity
//        assertEquals(5, vendingMachine.getCurrentItemCount());
//    }
//
//    @Test
//    public void testDispenseItem_Success() {
//        vendingMachine.insertItem('A');
//        vendingMachine.insertItem('B');
//        vendingMachine.insertItem('C');
//        int initialEarnings = vendingMachine.getTotalEarnings();
//
//        vendingMachine.get(2, 30); // Should dispense A and B for 10 + 20 = 30
//        assertEquals(1, vendingMachine.getCurrentItemCount()); // Only C should remain
//        assertEquals(initialEarnings + 30, vendingMachine.getTotalEarnings());
//    }
//
//    @Test
//    public void testDispenseItem_InsufficientAmount() {
//        vendingMachine.insertItem('A');
//        vendingMachine.insertItem('B');
//
//        // Try to get item at slot 1 which costs 10 but pay only 5
//        vendingMachine.get(1, 5); // Insufficient amount for A
//        assertEquals(2, vendingMachine.getCurrentItemCount()); // Both items should remain
//    }
//
//    @Test
//    public void testDispenseItem_ItemNotAvailable() {
//        vendingMachine.insertItem('A');
//        vendingMachine.insertItem('B');
//
//        // Try to get item at slot 3 which does not exist
//        vendingMachine.get(3, 10); // Item not available
//        assertEquals(2, vendingMachine.getCurrentItemCount()); // Both items should remain
//    }
//
//    @Test
//    public void testPrintStatus() {
//        vendingMachine.insertItem('A');
//        vendingMachine.insertItem('B');
//
//        // Status should show available items and earnings
//        vendingMachine.status();
//        assertEquals(2, vendingMachine.getCurrentItemCount());
//        assertEquals(0, vendingMachine.getTotalEarnings());
//    }
//
//    @Test
//    public void testItemFactory() {
//        Item itemA = ItemFactory.createItem('A', 10);
//        assertEquals('A', itemA.getType());
//        assertEquals(10, itemA.getPrice());
//
//        Item itemB = ItemFactory.createItem('B', 20);
//        assertEquals('B', itemB.getType());
//        assertEquals(20, itemB.getPrice());
//    }
}
