public class Library implements Aggregate {
    private List<Book> bookList;
    public Library(List<Book> bookList){
        this.bookList = bookList;
    }
    public Iterator createIterator(){
        return new BookIterator(bookList);
    }
}