public class BookIterator implements Iterator{
    private List<Book> books;
    private int index = 0;

    public BookIterator(List<Book> books){
        this.books = books;
    }
    public boolean hasNext(){
        return index < books.size();
    }

    public Object next(){
        if(this.hasNext()){
            return books.get(index++);
        }
    }
}