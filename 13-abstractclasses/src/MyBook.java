
public class MyBook extends Book {
	private int price;
	MyBook(String title, String author, int price){
		super(title,author);
		this.price = price;
	}
	
	void display() {
		System.out.println("Title: " + this.title);
		System.out.println("Author: " + this.author);
		System.out.println("Price: " + this.price);
	}
}
