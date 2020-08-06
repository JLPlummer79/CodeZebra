package edu.sdccd.cisc191;

import java.io.IOException;

import com.fasterxml.jackson.databind.ObjectMapper;

public class DeSerializationLab {
    public static void main(String[] args) {
        String json =  "object";

        ObjectMapper mapper = new ObjectMapper();

        try {
            Book book = mapper.readValue(json, Book.class);
            System.out.println(book);
        }
        catch(IOException e){
           System.out.println("**** Sorry, an error occurred ****");
            e.printStackTrace();
        }
    }
}