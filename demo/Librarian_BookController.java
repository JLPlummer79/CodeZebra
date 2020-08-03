package com.librarydata.demo;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
//handles the librian/book request operations
public class Librarian_BookController {
    @Autowired
    BookService bookService;

    @RequestMapping("librarian/book")
    public String home() {
        return "librarian/book/search: entire catalogue<br/>"+System.lineSeparator()+
        "librarian/book/search{id}: search book by id<br/>"+System.lineSeparator()+
        "librarian/book/search/{title}: search book by title<br/>"+System.lineSeparator()+
        "librarian/book/search/{author}: search books by author<br/>"+System.lineSeparator()+
        "librarian/book/search/{genere}: search by genere<br/>"+System.lineSeparator()+
        "librarian/book/checked-out: all books checked out{true/false}<br/>"+System.lineSeparator()+
        "librarian/book: can update, delete, and check-in from here";
    }//add Ankmorpork & borders later

    //get all Books in library
    @RequestMapping("librarian/book/search")
    public ResponseEntity<List<Book>> getAllBooks(){
        return bookService.getAllBooks();
    }
    //search books by id number
    @RequestMapping("librarian/book/search/{id}")
    public ResponseEntity <Book> getBook(@PathVariable Long id) {
        return bookService.getBook(id);
    }
    //search books by title
    @RequestMapping("librarian/book/search/title/{title}")
    public ResponseEntity<Book> findByTitle(@PathVariable String title) {
        return bookService.findByTitle(title);
    }
    //search books by author
    @RequestMapping("librarian/book/search/author/{author}")
    public ResponseEntity<List<Book>> findByAuthor(@PathVariable String author){
        return bookService.findByAuthor(author);
    }
    //search books by genere
    @RequestMapping("librarian/book/search/genere/{genere}")
    public ResponseEntity<List<Book>> findAllByGenere(@PathVariable String genere) {
        return bookService.findAllByGenere(genere);
    }

    
    //update book information, including checked-in/check-out
    @PutMapping("librarian/book/{id}")
    public ResponseEntity<Book> updateBook(@RequestBody Book book, @PathVariable Long id) {
        return bookService.updateBook(book, id);
    }
    //delete a book record from the data base
    @DeleteMapping("librarian/book/{id}")
    public ResponseEntity<HttpStatus> deleteBook(@PathVariable Long id) {
        return  bookService.deleteBook(id);
     }
     
     @RequestMapping("librarian/book/checked-out/{checkOutStatus}")
     public ResponseEntity<List<Book>> findCheckedOut(@PathVariable Boolean checkOutStatus){
         return bookService.findAllByCheckOutStatus(checkOutStatus);
     }

}