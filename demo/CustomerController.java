package com.librarydata.demo;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class CustomerController {
    
    @Autowired
    CustomerService customerService;

    //customer's access their account by id number
    @RequestMapping("/accounts/{id}")
    public ResponseEntity<Customer> getCustomer(@PathVariable Long id){
        return customerService.getCustomer(id);
    }
    //Customer's access account by last name
    @RequestMapping("/accounts/name/{lastName}")
    public ResponseEntity <List<Customer>> getCustomerByName(@PathVariable String lastName) {
        return customerService.getAllCustomerByLastName(lastName);
    }
    /*
    @PostMapping("/accounts/id/checkout/")
    public ResponseEntity<String> bookCheckout(@RequestBody Book book, @PathVariable Long customer_id) {
        return customerService.bookCheckout(book, customer_id);
    }
    */
    
    
}