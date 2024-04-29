public class Book {
    private int price;
    private String bookName;

    Book(int price, String name){
        this.price = price;
        this.bookName = name;
    }

    public int getPrice() {
        return price;
    }

    public String getBookName() {
        return bookName;
    }
}