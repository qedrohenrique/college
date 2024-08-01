package Users;

public class StudentUserType extends User {
    public StudentUserType(String name, String id) {
        super(name, id);
    }

    @Override
    public int getMaxBooks() {
        return 1;
    }
}