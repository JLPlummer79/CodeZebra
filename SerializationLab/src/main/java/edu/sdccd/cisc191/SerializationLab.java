package edu.sdccd.cisc191;

import java.io.File;

public class SerializationLab {

    public static void main(String[] args) {
        Book book = new Book((long) 19, "Einstein", "Walter Isaacson", "Non-Fiction", false);

        File bookFile = new File("customer.json");
        try {
            Book.saveJSON(bookFile, book);
            Book loadedBook = Book.loadJSON(bookFile);
            System.out.println(loadedBook.toString());
        } catch(Exception e) {
            e.printStackTrace();
        }
    }
}