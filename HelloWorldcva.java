

import java.awt.*;
import java.awt.event.*;
import java.io.IOException;
import java.io.*;
import java.util.*;
import java.io.File;

import	java.io.BufferedReader;

import	java.io.InputStreamReader;


public class HelloWorldcva {
    public static void main(String[] args) {
        
Process p2;
        Runtime r = Runtime.getRuntime();
        System.out.println("Hello, this is line 15432");
        try {
           
            
            p2 = r.exec("/Applications/Matlab_R2015aSP1.app/bin/matlab -r -nosplash do_canonical_variatescva3");//VERY VERY GOOD VARIANT
            
            
            
            BufferedReader in = new BufferedReader(
                                                   new InputStreamReader(p2.getInputStream()));
            
            OutputStream out = p2.getOutputStream();
            String line = null;
            line = in.readLine();
            
            while ((line = in.readLine()) != null) {
                System.out.println(line);
            }
            in.close();

            
        } catch (IOException e) {
            try{
                PrintWriter writer = new PrintWriter("the-file-name2.txt", "UTF-8");
                e.printStackTrace(writer);
            System.out.println("That is all, folks!45345????");
            }catch(IOException e7)
            {}
        }
        
        System.out.println("Hello, this is line 1");
        System.out.println("Hello, this is line 2");
        String s;
        s="erd";
        System.console().writer().println(s);
    }
}


    
    
