import java.net.*;
import java.io.*;

public class EchoServer {

    public static void main(String[] args) {

      try{
        
          ServerSocket server = new ServerSocket(5555); //listen to port 8080


        System.out.println("Waiting Incoming Connection...");
        Socket sock = server.accept();

        BufferedReader instream = new BufferedReader (new InputStreamReader (sock.getInputStream()));
        BufferedWriter outstream = new BufferedWriter(new OutputStreamWriter(sock.getOutputStream()));

        try {
        String strin = instream.readLine();
		while ((strin = instream.readLine()) != null) {
          		System.out.println(strin);

        	  if (strin.equals("Hello")){
        		  outstream.write("Hi");
        		  

        	  }else{
        		  
        	  System.out.println(strin);
        	  }
        	  
              if (strin.equals("Bye."))
                  break;
          }

           

        
        instream.close();
        outstream.close();
        sock.close();
        System.out.println("Connection Closing...");

        } catch (Exception ex){
            System.out.println("Error during I/O");
            ex.getMessage();
            ex.printStackTrace();
        }    
    } catch (Exception e) {

    }
}
}
