


import java.awt.*;
import java.awt.event.*;
import java.io.IOException;
import java.io.*;

public class HelloWorld {
    private native void print();
    public static void main(String[] args) throws Throwable {
      
        new HelloWorld().print();
        
      
        
    }
    static {
        
        System.loadLibrary("HelloWorld");
        
    }
    
    
    
    
    
}