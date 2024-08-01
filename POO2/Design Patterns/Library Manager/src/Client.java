import java.util.List;
import Users.*;
import Handlers.*;
import ExternalCatalog.*;
import Configurations.*;

public class Client {
    public static void main(String[] args) {
        ExternalCatalogAdapter catalogAdapter = new ExternalCatalogAdapterImpl();
        LibraryMediator mediator = new LibraryMediator();
        LibraryFacade libraryFacade = new LibraryFacade(catalogAdapter, mediator);
        
        User user = libraryFacade.getUserDetails("1");
        if (user != null) {
            System.out.println("User found: " + user.getName() + " (ID: " + user.getId() + ")");
            
            List<Book> books = libraryFacade.searchBooks("title", "Effective Java");
            if (!books.isEmpty()) {
                Book book = books.get(0);

                // Empréstimo de livro
                if (libraryFacade.borrowBook(user, book)) {
                    System.out.println(user.getName() + " borrowed book: " + book.getTitle());
                }

                // Devolução de livro
                if (libraryFacade.returnBook(user, book)) {
                    System.out.println(user.getName() + " returned book: " + book.getTitle());

                    // Verificar o histórico de empréstimos após a devolução
                    List<Book> loanHistory = mediator.getLoanHistory(user);
                    System.out.println("Loan History for " + user.getName() + ":");
                    for (Book loanedBook : loanHistory) {
                        System.out.println("- " + loanedBook.getTitle() + " by " + loanedBook.getAuthor());
                    }
                }
            } else {
                System.out.println("Book not found.");
            }
        } else {
            System.out.println("User not found.");
        }

        List<Book> books = libraryFacade.searchBooks("title", "Effective Java");
        for (Book book : books) {
            System.out.println("Found book: " + book.getTitle() + " by " + book.getAuthor());
        }

        User newUser = new StudentUserType("Pedro", "1");
        Book book = books.get(0);

        borrowSameBookTwice(libraryFacade, newUser, book);

        if(libraryFacade.returnBook(newUser, book)){
            System.out.println("Book returned!");
        }

        borrowSameBookTwice(libraryFacade, newUser, book);

        User student = new StudentUserType("Pedro", "1");
        User teacher = new TeacherUserType("Ana", "2");
        User librarian = new LibrarianUserType("Maria", "3");

        Book testBook = new Book("Effective Java", "Joshua Bloch", "Programming");

        testBorrowingLimit(libraryFacade, student, testBook);
        testBorrowingLimit(libraryFacade, teacher, testBook);
        testBorrowingLimit(libraryFacade, librarian, testBook);
    }

    private static void testBorrowingLimit(LibraryFacade libraryFacade, User user, Book book) {
        for (int i = 0; i < user.getMaxBooks() + 1; i++) {
            if (libraryFacade.borrowBook(user, book)) {
                System.out.println(user.getName() + " borrowed book " + (i + 1) + " successfully!");
            } else {
                System.out.println(user.getName() + " failed to borrow book " + (i + 1) + ".");
            }
        }
    }

    private static void borrowSameBookTwice(LibraryFacade libraryFacade, User user, Book book){
        if (libraryFacade.borrowBook(user, book)) {
            System.out.println("Book borrowed successfully!");
        } else {
            System.out.println("Failed to borrow the book.");
        }

        if (libraryFacade.borrowBook(user, book)) {
            System.out.println("Book borrowed successfully!");
        } else {
            System.out.println("Failed to borrow the book.");
        }
    }
}