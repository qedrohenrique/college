package Users;

public class LibrarianUserType extends User {
    public LibrarianUserType(String name, String id) {
        super(name, id);
    }

    @Override
    public int getMaxBooks() {
        return Integer.MAX_VALUE; // Sem limite
    }
}