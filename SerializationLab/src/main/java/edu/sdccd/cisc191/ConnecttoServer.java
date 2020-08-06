package edu.sdccd.cisc191;

import java.net.URL;
import java.net.URLConnection;
import java.util.Scanner;

import com.fasterxml.jackson.core.JsonParser;
import com.fasterxml.jackson.core.JsonToken;
import com.fasterxml.jackson.databind.ObjectMapper;
import com.fasterxml.jackson.databind.node.ObjectNode;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;

public class ConnecttoServer {

    public static void main(String[] args){
        String url;    // The url from the command line or from user input.
        String urlLC;  // The url transformed to lower case.
        boolean check = false;
        String exit = "Y";
        Scanner stdin = new Scanner(System.in);

        while (!check) {
            if (args.length == 0) {
                //Scanner stdin = new Scanner(System.in);
                System.out.print("Enter a url: ");
                url = stdin.nextLine();
            }
            else {
                url = args[0];
            }
            urlLC = url.toLowerCase();
            if ( ! (urlLC.startsWith("http://") || urlLC.startsWith("ftp://") || 
                    urlLC.startsWith("file://") || urlLC.startsWith("https://") )) {
                url = "http://" + url;
                System.out.println("Using: " + url);
            }
            System.out.println();
            try {
                readTextFromURL(url);
            }
            catch (IOException e) {
                System.out.println("\n*** Sorry, an error has occurred ***\n");
                e.printStackTrace();
                System.out.println(e);
                System.out.println();
            }
            catch (IllegalStateException e){
                System.out.println("*** Sorry, an error occurred during the Json stuff ***\n");
                e.printStackTrace();
            }
            System.out.println("Enter Q to exit:");
            System.out.println("Or hit enter to continue");
            exit = stdin.nextLine();

            if(exit.equals("Q") || exit.equals("q") ) {
                System.out.println("Exiting...");
                check = true;
            }

        }//end control while
    }

    static void readTextFromURL( String urlString ) throws IOException, IllegalStateException {

        /* Open a connection to the URL, and get an input stream
           for reading data from the URL. */

        URL url = new URL(urlString);
        URLConnection connection = url.openConnection();
        InputStream urlData = connection.getInputStream();
        BufferedReader in;  // For reading from the connection's input stream.
        String line;
        /* Check that the content is some type of text.  Note: 
           connection.getContentType() should be called after
           connction.getInputStream(). */

        String contentType = connection.getContentType();
        System.out.println("Stream opened with content type: " + contentType);
        System.out.println();
        if (contentType.startsWith("text") == true) {
            System.out.println("Fetching context from " + urlString + " ...");  
            System.out.println();
            in = new BufferedReader( new InputStreamReader(urlData) );
            while (true) {
                 line = in.readLine();
                if (line == null)
                    break;
                System.out.println(line);
            }
            in.close();
        }
        else if(contentType.startsWith("application/json") == true) {
            System.out.println("Fetching context from: " + urlString);
            System.out.println();
            in = new BufferedReader( new InputStreamReader(urlData) );
            while (true) {
                line = in.readLine();
                if (line == null)
                    break;
                System.out.println(line);
            }
            in.close();
           /*
            ObjectMapper mapper = new ObjectMapper();
            JsonParser parser = mapper.getFactory().createParser(line);
            if(parser.nextToken() != JsonToken.START_ARRAY) {
                throw new IllegalStateException("Expected an array");
            }
            while (parser.nextToken() == JsonToken.START_OBJECT) {
                //read everything from this START_OBJECT to the END_OBJECT
                //return it as a tree model ObjectNode
                ObjectNode node = mapper.readTree(parser);
                Book book = mapper.convertValue(node, Book.class);
                System.out.println("" + book);
            }
            parser.close();
            */
        }
        else {
            throw new IOException("URL does not seem to refer to a text or json file.");
        }
        /* Copy lines of text from the input stream to the screen, until
           end-of-file is encountered  (or an error occurs). */

    } // end readTextFromURL()
    
}