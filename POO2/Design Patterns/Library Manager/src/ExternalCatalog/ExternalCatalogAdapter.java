package ExternalCatalog;

import java.util.List;

public interface ExternalCatalogAdapter {
    List<Book> searchBooks(String criteria, String value);
}
