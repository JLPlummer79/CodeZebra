package com.librarydata.demo;

import javax.swing.plaf.metal.MetalBorders.ButtonBorder;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController

public class HomeController {
    String border = System.lineSeparator() + "<br/>========================================================";
    String search = System.lineSeparator() + "<br/>/search: display all books";
    String book = System.lineSeparator() + "<br/>/books: display catalog";
    String accounts_id = System.lineSeparator() + "<br/>/accounts/{id}: login by id";
    String accounts_name = System.lineSeparator() + "<br/>/accounts/name/{Last Name}: login by name";
    String librarian_accounts = System.lineSeparator() + "<br/>/librarian/accounts/: display all accounts";
    String librarian_accounts_id = System.lineSeparator() + "<br/>/librarian/accounts/{id}";
    String librarian_accounts_name = System.lineSeparator() + "<br/>/librarian/accounts/name/{last}";
    String librarian_books = System.lineSeparator() + "<br/>/librarian/search/id or title";
    String accounts_checkout = "<br/>/accounts/account id/checkout/{book} for checkout";
    
    @GetMapping("/")
    public String homeMessage() {
        return  "Ankmorpork Library Server"+border+book+search+accounts_id+accounts_name+
        librarian_accounts+librarian_accounts_id+librarian_accounts_name+librarian_books+border;
    }    
    
    @GetMapping("/accounts/")
    public String accountsHomeMessage() {
        return "Welcome to the Ankmorpork Library!<br/>"+border+accounts_id+
        accounts_name+accounts_checkout+border;
    }

    @RequestMapping("/librarian/")
    public String librarianHome() {
        return "Welcome to the Ankmorpork Library!<br/>" +border+
        "/librarian<br/>"+"/librarian/accounts: customer accounts<br/>"+
        "/librarian/book/: book transactions<br/>"+border;
    }

}