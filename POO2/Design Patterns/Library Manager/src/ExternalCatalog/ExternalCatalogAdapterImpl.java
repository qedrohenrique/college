package ExternalCatalog;

import java.util.ArrayList;
import java.util.List;

public class ExternalCatalogAdapterImpl implements ExternalCatalogAdapter {

    @Override
    public List<Book> searchBooks(String criteria, String value) {
        List<Book> catalog = new ArrayList<>();
        catalog.add(new Book("Effective Java", "Joshua Bloch", "Programming"));
        catalog.add(new Book("Clean Code", "Robert C. Martin", "Programming"));
        catalog.add(new Book("Design Patterns", "Erich Gamma, Richard Helm, Ralph Johnson, John Vlissides", "Software Engineering"));

        List<Book> result = new ArrayList<>();

        for (Book book : catalog) {
            if (criteria.equalsIgnoreCase("title") && book.getTitle().equalsIgnoreCase(value)) {
                result.add(book);
            } else if (criteria.equalsIgnoreCase("author") && book.getAuthor().equalsIgnoreCase(value)) {
                result.add(book);
            } else if (criteria.equalsIgnoreCase("category") && book.getCategory().equalsIgnoreCase(value)) {
                result.add(book);
            }
        }

        return result;
    }
}
