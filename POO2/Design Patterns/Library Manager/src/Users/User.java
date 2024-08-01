package Users;

import java.util.List;
import java.util.ArrayList;
import ExternalCatalog.*;

public abstract class User {
    private String id;
    private String name;
    private List<Book> borrowedBooks;
    private List<Book> loanHistory;  // Lista para manter o histórico de empréstimos

    public User(String name, String id) {
        this.id = id;
        this.name = name;
        this.borrowedBooks = new ArrayList<>();
        this.loanHistory = new ArrayList<>();
    }

    public String getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public void borrowBook(Book book) {
        borrowedBooks.add(book);
    }

    public void returnBook(Book book) {
        borrowedBooks.remove(book);
        loanHistory.add(book);  // Adiciona o livro ao histórico de empréstimos ao devolvê-lo
    }

    public List<Book> getBorrowedBooks() {
        return borrowedBooks;
    }

    public List<Book> getLoanHistory() {
        return new ArrayList<>(loanHistory);  // Retorna uma cópia da lista para evitar modificações externas
    }

    public abstract int getMaxBooks();
}