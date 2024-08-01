package ExternalCatalog;

public class Book {
  private String name;
  private String author;
  private String category;
  private boolean isAvailable;

  public Book(String name, String author, String category){
    this.name = name;
    this.author = author;
    this.category = category;
    this.isAvailable = true;
  }

  public String getCategory(){
    return this.category;
  }

  public String getAuthor(){
    return this.author;
  }

  public String getTitle(){
    return this.name;
  }

  public boolean borrow(){
    if(this.isAvailable){
      this.isAvailable = false;
      return true;
    }

    return false;
  }

  public boolean returnBook(){
    if(!this.isAvailable){
      this.isAvailable = true;
      return true;
    }

    return false;
  }
}