import java.util.List;
import ExternalCatalog.*;
import Handlers.*;
import Users.*;

public class LibraryFacade {
    private ExternalCatalogAdapter catalogAdapter;
    private LibraryMediator mediator;
    private BookAvailabilityNotifier notifier;

    public LibraryFacade(ExternalCatalogAdapter adapter, LibraryMediator mediator) {
        this.catalogAdapter = adapter;
        this.mediator = mediator;
        this.notifier = notifier;
    }

    public List<Book> searchBooks(String criteria, String value) {
        return catalogAdapter.searchBooks(criteria, value);
    }

    public boolean borrowBook(User user, Book book) {
        return mediator.borrowBook(user, book);
    }

    public boolean returnBook(User user, Book book) {
        return mediator.returnBook(user, book);
    }

    public User getUserDetails(String userId) {
        return mediator.getUserDetails(userId);
    }
}
