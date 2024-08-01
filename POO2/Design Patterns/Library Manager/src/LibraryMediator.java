import java.util.List;
import ExternalCatalog.*;
import Handlers.*;
import Users.*;
import java.util.ArrayList;

public class LibraryMediator {
    private BookAvailabilityHandler bookAvailabilityHandler;
    private LoanLimitHandler loanLimitHandler;
    private UserEligibilityHandler userEligibilityHandler;
    private ArrayList<User> userList;
    private BookAvailabilityNotifier notifier;

    public LibraryMediator() {
        this.bookAvailabilityHandler = new BookAvailabilityHandler();
        this.userEligibilityHandler = new UserEligibilityHandler();
        this.loanLimitHandler = new LoanLimitHandler();
        this.notifier = new BookAvailabilityNotifier();
        this.userList = new ArrayList<>();
        userList.add(new StudentUserType("Pedro", "1"));
        userList.add(new TeacherUserType("Ana", "2"));
    }

    public void addUser(User user) {
        userList.add(user);
    }

    public boolean borrowBook(User user, Book book) {
        if (user.getBorrowedBooks().size() < user.getMaxBooks()) {
            boolean success = book.borrow();
            if (success) {
                user.borrowBook(book);
                notifier.notifyUser(user, new Notification("Book borrowed: " + book.getTitle()));
                return true;
            }
        }
        return false;
    }

    public boolean returnBook(User user, Book book) {
        boolean success = book.returnBook();
        if (success) {
            user.returnBook(book);
            notifier.notifyUser(user, new Notification("Book returned: " + book.getTitle()));
        }
        return success;
    }

    public List<Book> getLoanHistory(User user) {
        return user.getLoanHistory();
    }

    private boolean checkHandlers(Book book, User user) {
        if (!bookAvailabilityHandler.handle(user, book)) return false;
        if (!loanLimitHandler.handle(user, book)) return false;
        if (!userEligibilityHandler.handle(user, book)) return false;
        return true;
    }

    public User getUserDetails(String userId) {
        for (User user : userList) {
            if (user.getId().equals(userId)) {
                return user;
            }
        }
        return null;
    }
}

