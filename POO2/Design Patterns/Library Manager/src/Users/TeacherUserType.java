package Users;

public class TeacherUserType extends User {
    public TeacherUserType(String name, String id) {
        super(name, id);
    }

    @Override
    public int getMaxBooks() {
        return 2;
    }
}