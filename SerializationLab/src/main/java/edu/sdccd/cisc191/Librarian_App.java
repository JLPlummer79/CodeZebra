package edu.sdccd.cisc191;

import java.io.IOException;
import java.io.InterruptedIOException;
import java.io.StringWriter;
import java.net.URI;
import java.net.URISyntaxException;
import java.net.http.HttpClient;
import java.net.http.HttpRequest;
import java.net.http.HttpResponse;
import java.net.http.HttpRequest.BodyPublisher;
import java.net.http.HttpRequest.BodyPublishers;
import java.net.http.HttpRequest.Builder;
import java.util.List;
import java.util.Scanner;
import java.util.HashMap;

import com.fasterxml.jackson.core.JsonParseException;
import com.fasterxml.jackson.core.type.TypeReference;
import com.fasterxml.jackson.databind.DeserializationFeature;
import com.fasterxml.jackson.databind.ObjectMapper;
import com.fasterxml.jackson.databind.exc.MismatchedInputException;

public class Librarian_App {

    public static void main(String[] args) throws IOException, InterruptedException {
        HttpClient client = HttpClient.newHttpClient();
        String url;
        Scanner stdin = new Scanner(System.in);

        HttpRequest request = HttpRequest.newBuilder().GET().uri(URI.create("http://localhost:8085")).build();
        HttpResponse<String> response = client.send(request, HttpResponse.BodyHandlers.ofString());

        System.out.println(response.body());

        while (true) {
            System.out.println("Enter path/url: ");
            System.out.println("Press Enter to bring up home menu");
            System.out.println("Enter Q and press enter to quit.");
            url = stdin.nextLine();

            if (url.equals("Q") || url.equals("q")) {
                System.out.println("Exiting...");
                break;
            }
            // calls the search method for a book
            else if (url.contains("/book/search") || url.contains("books/") || url.contains("search/")) {
                try {
                    bookJsonResponseMethod(url);
                } catch (IllegalArgumentException e) {
                    e.printStackTrace();
                } catch (IllegalStateException e) {
                    e.printStackTrace();
                } catch (JsonParseException e) {
                    e.printStackTrace();
                } catch (MismatchedInputException e) {
                    e.printStackTrace();
                }
            }
            // calls the post/add method for a book object
            else if (url.contains("librarian/book/new")) {
                try {
                    bookJsonPostMethod(url);
                } catch (IOException e) {
                    e.printStackTrace();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                } catch (IllegalArgumentException e) {
                    e.printStackTrace();
                }

            } else if (url.contains("librarian/book/delete")) {
                try {
                    bookDeleteMethod(url);
                } catch (IOException e) {
                    e.printStackTrace();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                catch (URISyntaxException e) {
                    e.printStackTrace();
                }
            } 
            else if(url.contains("librarian/book/update")) {
                try {
                    bookJsonUpdateMethod(url);
                }
                catch(IOException e) {
                    e.printStackTrace();
                }
                catch(InterruptedException e) {
                    e.printStackTrace();
                }
            }
            else {
                request = HttpRequest.newBuilder().GET().uri(URI.create("http://localhost:8085/" + url)).build();

                response = client.send(request, HttpResponse.BodyHandlers.ofString());

                System.out.println(response.body());
            }

        } // end while

    } // end main

    public static void bookJsonResponseMethod(String url) throws IOException, InterruptedException, JsonParseException {
        HttpClient client = HttpClient.newHttpClient();
        HttpRequest request = HttpRequest.newBuilder().GET().header("accept", "application/json")
                .uri(URI.create("http://localhost:8085/" + url)).build();
        HttpResponse<String> response = client.send(request, HttpResponse.BodyHandlers.ofString());
        ObjectMapper mapper = new ObjectMapper();
        mapper.enable(DeserializationFeature.ACCEPT_SINGLE_VALUE_AS_ARRAY);
        List<Book> books = mapper.readValue(response.body(), new TypeReference<List<Book>>() {
        });

        books.forEach(System.out::println);
    }

    public static void bookDeleteMethod(String url)
            throws IOException, InterruptedException, IllegalArgumentException, URISyntaxException {
        //send a delete request with the given id
        Scanner stdin = new Scanner(System.in);
        String entryObject;
        long id = 1L;
        boolean check = false;
            while (!check) {
                System.out.println("Deletion menu:\n" + "***************************************");
                System.out.println("Enter Q to quit");
                entryObject = stdin.nextLine();
    
                switch (entryObject) {
                    case ("Q"):
                        check = true;
                        break;
                    case ("q"):
                        check = true;
                        break;
                    default:
                        System.out.println("Enter id: ");
                        //entryObject = stdin.nextLine();
                        id = (long) stdin.nextInt();
                        check = true;
                        break;
                }
            }
        
        //1st need to get the specific record
        HttpClient getClient = HttpClient.newHttpClient();
        HttpRequest getRequest = HttpRequest.newBuilder()
        .GET()
        .header("accept", "application/json")
        .uri(URI.create("http://localhost:8085/librarian/book/search/"+id))
        .build();
        HttpResponse<String> getResponse = getClient.send(getRequest,
         HttpResponse.BodyHandlers.ofString());
         ObjectMapper mapper = new ObjectMapper();
        mapper.enable(DeserializationFeature.ACCEPT_SINGLE_VALUE_AS_ARRAY);
        List<Book> books = mapper.readValue(getResponse.body(), new TypeReference<List<Book>>() {
        });
        books.forEach(System.out::println);
        //2nd make the Delete request
        String requestBody = "";
        requestBody = mapper.writeValueAsString(books);
        HttpClient client = HttpClient.newHttpClient();
        HttpRequest request = HttpRequest.newBuilder()
        .method("DELETE", HttpRequest.BodyPublishers.ofString(requestBody))
        .uri(new URI("http://localhost:8085/"+url+id)) 
        .build();
        HttpResponse<String> response = client.send(request, 
        HttpResponse.BodyHandlers.ofString());
        System.out.println(response.body()); 
    }

    public static void bookJsonPostMethod(String url) throws IOException, InterruptedException, JsonParseException {
        Book book = new Book();
        Long id = 1L;
        String title = "";
        String author = "";
        String genere = "";
        String entryObject;
        Scanner stdin = new Scanner(System.in);
        boolean check = false;
        while (!check) {
            System.out.println("New Book entry menu:\n" + "***************************************");
            System.out.println("Enter Q to quit");
            entryObject = stdin.nextLine();

            switch (entryObject) {
                case ("Q"):
                    check = true;
                    break;
                case ("q"):
                    check = true;
                    break;
                default:
                    System.out.println("Enter id:");
                    entryObject = stdin.nextLine();
                    id = Long.getLong(entryObject);
                    System.out.println("Enter Title:");
                    title = stdin.nextLine();
                    System.out.println("Enter Author: ");
                    author = stdin.nextLine();
                    System.out.println("Enter Genere: ");
                    genere = stdin.nextLine();
                    break;
            }
        }
        book.setId(id);
        book.setTitle(title);
        book.setAuthor(author);
        book.setGenere(genere);
        book.setCheckOutStatus(false); // new book default

        String requestBody;

        ObjectMapper objectMapper = new ObjectMapper();
        requestBody = objectMapper.writeValueAsString(book);
        System.out.println(requestBody + " resulting json string");

        HttpClient client = HttpClient.newHttpClient();
        HttpRequest request = HttpRequest.newBuilder().POST(BodyPublishers.ofString(requestBody))
                .header("Content-Type", "application/json").uri(URI.create("http://localhost:8085/" + url)).build();
        HttpResponse<String> response = client.send(request, HttpResponse.BodyHandlers.ofString());
        System.out.println(response.body());
    }
    //Is a put, but ends up being a post
    public static void bookJsonUpdateMethod(String url) throws IOException, InterruptedException, JsonParseException {
        Long id = 1L;
        Book book = new Book();
        String attributeToChange = "",title = "", author = "", genere = "", checkedOut = "";
        boolean check = false;
        Scanner stdin = new Scanner(System.in);

        while(!check) {
            System.out.println("Book Update Menu:\n" + "***************************************");
            System.out.println("Enter T for title, A for author, G for genere, C for Checked-Out-Status,"+
            "Q to quit.");
            attributeToChange = stdin.nextLine();
            switch(attributeToChange) {
                case("Q"):
                    check = true;
                    break;
                case("q"):
                    check = true;
                    break;
                case("T"):
                    System.out.println("Enter book id: ");
                    id = (long) stdin.nextInt();
                    stdin.nextLine();
                    System.out.println("Enter new title: ");
                    title = stdin.nextLine();
                    check = true;
                    break;
                case("A"):
                    System.out.println("Enter book id: ");
                    id = (long) stdin.nextInt();
                    stdin.nextLine();
                    System.out.println("Enter new author: ");
                    author = stdin.nextLine();
                    check = true;
                    break;
                case("G"):
                    System.out.println("Enter book id: ");
                    id = (long) stdin.nextInt();
                    stdin.nextLine();
                    System.out.println("Enter new genere: ");
                    genere = stdin.nextLine();
                    check = true;
                    break;
                case("C"):
                    System.out.println("Enter book id: ");
                    id = (long) stdin.nextInt();
                    stdin.nextLine();
                    System.out.println("Enter F/T: ");
                    checkedOut = stdin.nextLine();
                    check = true;
                    break;
                default:
                    System.out.println("Entry invalid.");
                    break;
            }//end switch
        }//end while
        //1st get the book object that we need to alter
    
        HttpClient getClient = HttpClient.newHttpClient();
        HttpRequest getRequest = HttpRequest.newBuilder()
        .GET()
        .header("accept", "application/json")
        .uri(URI.create("http://localhost:8085/librarian/book/search/"+id))
        .build();
        HttpResponse<String> getResponse = getClient.send(getRequest,
         HttpResponse.BodyHandlers.ofString());
         ObjectMapper mapper = new ObjectMapper();
        mapper.enable(DeserializationFeature.ACCEPT_SINGLE_VALUE_AS_ARRAY);
        List<Book> books = mapper.readValue(getResponse.body(), new TypeReference<List<Book>>() {
        });
        books.forEach(System.out::println);
        //2nd update the record with the change
        if(!title.equals("")) {
            book = books.get(0);
            book.setTitle(title);
        }
        else if(!author.equals("")) {
            book = books.get(0);
            book.setAuthor(author);
        }
        else if(!genere.equals("")) {
            book = books.get(0);
            book.setGenere(genere);
        }
        else if(!checkedOut.equals("")) {
            book = books.get(0);
            if(checkedOut.equals("F")) {
                book.setCheckOutStatus(false);
            }
            else {
                
                book.setCheckOutStatus(true);
            }
        }
        //3rd update the record
        String requestBody = "";
        requestBody = mapper.writeValueAsString(book);
        HttpClient client = HttpClient.newHttpClient();
        HttpRequest request = HttpRequest.newBuilder().PUT(BodyPublishers.ofString(requestBody))
                .header("Content-Type", "application/json")
                .uri(URI.create("http://localhost:8085/" + url+id)).build();
        HttpResponse<String> response = client.send(request, HttpResponse.BodyHandlers.ofString());
        System.out.println(response.body());

        
    }//end function 

}