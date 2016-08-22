

import ij.*;
import ij.process.*;
import ij.gui.NonBlockingGenericDialog;
import ij.gui.*;
import java.awt.*;
import ij.plugin.*;
import ij.plugin.tool.PlugInTool;
import java.awt.event.*;
import java.awt.Component;
import java.awt.event.ActionListener;

import java.awt.Dimension;

import java.util.Vector;

import java.util.*;

import javax.swing.JButton;

import java.awt.Button;


import java.awt.Dialog;

import	java.io.BufferedReader;
import	java.io.IOException;
import	java.io.InputStreamReader;

public class Dimensionality_Reduction_Task extends PlugInTool implements DialogListener{

    
    public NonBlockingGenericDialog gd;
    
    public double number;
    //public Dialog gd;
    
    public AWTEvent e;
    
    //public GenericDialog gd;
    
    
    Process p;
    //WindowEvent e;
    int callalg;
    
    
    public String getToolIcon() {
        return "C00fO22dd"; // blue circle
    }
    
    
    
    public void main(String[] args) throws Throwable {
       
        
        callalg = 0;
        System.out.println("Hello 2World!");
        getToolIcon();
        //showDialog();
        
    }
    

    
    public void run(String arg) {

        
        showDialog2();
        
    }

    public int showDialog2() {
        //gd = new NonBlockingGenericDialog("Radio Buttons");
        
        
        Dimension di;
        
        di = new Dimension(500,500);
        
        //di.width =500;
        //di.height =500;
        
        gd = new NonBlockingGenericDialog(" Dimensionality Reduction Task ");
        
       
        
        //Frame window = new Frame();
        // Create a modal dialog
        //gd = new Dialog(window, "Alert");
        //gd.setModal(false);
        //gd.hideCancelButton();
        //gd.hideOkButton();
        //gd.setLayout( new FlowLayout() );
        // Create an OK button
        //Button ok = new Button ("OK");
       
        //ok.addActionListener ( new ActionListener()
        //{
        //    public void actionPerformed( ActionEvent e )
        //    {
                // Hide dialog
        //        gd.setVisible(false);
        //    }
        //});
        //gd.add( new Label ("Click OK to continue"));
        //gd.add( ok );
        // Show dialog
        //gd.pack();
        //gd.setVisible(true);

        
        //Button[] buttons;
        
        //buttons = gd.getButtons();
        
        //int size = buttons.length;
        
        //buttons[1].setLabel("test");
        
        //gd.remove(buttons[1]);
        //gd.buttons[1];
        
        
        //if( buttons[1] != null) {
        
        //    System.out.println(buttons[1].getLabel());}
        
        //Button[] buttons;
        
        //buttons = gd.getButtons();
        
        //int size = buttons.length;
        
        //buttons[1].setLabel("test");
        
        //gd.remove(buttons[1]);
        
        //Button Button1 = new Button("Ok");
        //gd.add(Button1);
        
        //System.out.println(size);
        
        //buttons[0] = new Button("t");
        //gd.add(buttons[0]);
        
        //if( buttons[0] != null) {
        
        // buttons[0].setLabel("sfsfs");
        //}
        //System.out.println(buttons[0].getLabel());
        
        
        //gd = new GenericDialog(" Dimensionality Reduction Task ",IJ.getInstance());
        
        gd.setMinimumSize(di);
        
        
        //gd.addTextAreas("","",10,20);
         //gd.addStringField(" "," ");
        //gd.addCheckbox("add_noise", false);
        
        //gd.centerDialog(true);
        
        //gd.setSize(650, 630);
        
        //gd.setLocation(10, 10);
        
        gd.setResizable(true);
        
        //gd.addMessage(" Algorithms for Dimensionality Reduction  ");
        
        
        //gd.addMessage(" Algorithms for Dimensionality Reduction  ");
        
        gd.addMessage(" ");
        gd.addMessage(" ");
        
        gd.addMessage(" Dimensionality Reduction Methods - Matlab, R, C : Supervised, Unsupervised                                 ");
        
        gd.addMessage(" ");
        gd.addMessage(" ");

        
        
        String str;
       
        String[] anArray;
        
        // allocates memory for 10 integers
        anArray = new String[4];
        
        //gd.setCancelLabel("Stupid");
        //gd.setWindowBounds(100,100,400,400);
        
        //int[] refbut = new int[10];
        
        //Object[] buttons = null;
               //buttons[0];
        
        //str = buttons[2].getLabel();
        //try{
         //    buttons[1].setLocation(23,45);
        //}  catch (IOException e) {
            //PrintWriter pw = new PrintWriter(new File("file.txt"));
            //e.printStackTrace(pw);
            //System.out.println("There is an error, the Algorithm could not be started");
        //}
        
        //System.out.println(size );
        //buttons[1].setLabel("test");
        //buttons[0].toString();
        
        //buttons=gd.getButtons(16);
        
        
        //System.out.println("Button " + buttons.getText() );
        
        //refbut = gd.getButtons();
        
        //int button_X_Pos = button.getLocation().x;
        
        
        
        //String[] items = {"New York", "London", "Paris", "Tokyo"};
        //gd.addRadioButtonGroup("Cities", items, 2, 2, "Paris");
        
        //String[] items2 = {"Alfa Romeo ", "Ferrari", "Lamborghini", "Maserati", "Lancia"};
        //gd.addRadioButtonGroup("Italian Cars", items2, 5, 1, "Ferrari");
        
        String[] items2 = {" Canonical Variates Analysis - Matlab language - Processing 8 bit TIFF files - Supervised method (requires you to introduce a number of points by hand)"," Canonical Variates Analysis - Matlab language - Processing 16 bit TIFF files - Supervised method (requires you to introduce a number of points by hand)" ," Generalized Discriminant Analysis - Matlab language - Supervised method (requires you to introduce a number of points by hand)", " Linear Discriminant Analysis - Matlab language - Supervised method (requires you to introduce a number of points by hand)" ," Neighborhood Component Analysis - Matlab language - Supervised method (requires you to introduce a number of points by hand)"," Canonical Variates Analysis - C language - Processing 8 bit TIFF files - Supervised method (requires you to introduce a number of points by hand)"," Canonical Variates Analysis - C language - Processing 16 bit TIFF files - Supervised method (requires you to introduce a number of points by hand)"," Isomap - Matlab language - Supervised method (still requires you to introduce a number of points by hand)"," Landmark Isomap - Matlab language - Supervised method (still requires you to introduce a number of points by hand)"," Principal Component Analysis - Matlab language - Supervised method (still requires you to introduce a number of points by hand)", " Probabilistic Principal Component Analysis - Matlab language - Supervised method (still requires you to introduce a number of points by hand)"," Gaussian Process Latent Variable Model - Matlab language - Supervised method (still requires you to introduce a number of points by hand)" ," Principal Component Analysis - Matlab language - Unsupervised method (does not require you to introduce a number of points by hand)"};
        
        
         //gd.addMessage("                                                             ");
        
        //String[] items3 = {" Isomap - Matlab language"," Landmark Isomap - Matlab language"," Principal Component Analysis - Matlab language"," Probabilistic Principal Component Analysis - Matlab language"," Gaussian Process Latent Variable Model - Matlab language"};
        
        
        
        //String[] items4 = {" Principal Component Analysis - Matlab language - It is Matlab own function"};
        
        //gd.addRadioButtonGroup("Dimensionality Reduction Methods - Matlab, R, C : Supervised, Unsupervised", items2, 11, 1, " Canonical Variates Analysis - Matlab language - Supervised method (requires you to introduce a number of points by hand)");
       
        gd.addRadioButtonGroup(" ", items2, 13, 1, " Canonical Variates Analysis - Matlab language - Supervised method (requires you to introduce a number of points by hand)");
        
        
        //gd.addRadioButtonGroup("Supervised methods", items2, 5, 1, " Generalized Discriminant Analysis - Matlab language");
        
        //gd.addRadioButtonGroup("Supervised methods (requires you to introduce a number of points by hand)", items2, 5, 1," ");
        
        
        gd.addMessage("                                                             ");
        
        
        
        //gd.addRadioButtonGroup("Unsupervised methods", items3, 5, 1, " Isomap - Matlab language");
        
        //gd.addRadioButtonGroup("Unsupervised methods (requires you to introduce a number of points by hand)", items3, 5, 1, " ");
        
        
        gd.addMessage("                                       ");
        
        
        //gd.addRadioButtonGroup("Unsupervised methods (does not require you to introduce a number of points by hand)     ", items4, 1, 1, " ");
        
        
        
        
         gd.addMessage(" ");
         gd.addMessage(" ");
         gd.addMessage(" ");
        //String[] items3 = {"One", "Two", "Three"};
        //gd.addRadioButtonGroup("", items3, 1, 3, "One");
        
        //gd.setSize(550, 430);
        //gd.setResizable(true);
        
        //if (IJ.isMacintosh())
        //    gd.setResizable(true);
        
        
        //Button[] buttons;
        
        //buttons = gd.getButtons();
        //buttons = gd.getButtons();
        
        //System.out.println("Button " + buttons[1].getLabel() );
        //int size = buttons.length;
        
        //buttons[1].setLabel("test");
        
        //gd.setOKLabel("sdf");
        
        //gd.setResizable(true);
        
        //gd.setResizable(true);
        
        
        gd.addDialogListener(this);
        
        
     
        
        gd.showDialog();
       
        
        
        
        
        //Button[] buttons;
        
        //buttons = gd.getButtons();
        
        //int size = buttons.length;
        
        //buttons[1].setVisible(false);
        
        // gd.showDialog();
        
        //gd.validate();
        
        
        //gd.repaint();
        
        
        
        //gd.remove(buttons[1]);
        //buttons[1] = buttons[0];
        
        
        //if( buttons[1] != null) {
            
        //    System.out.println(buttons[1].getLabel());}
        

        //Button[] buttons;
        
        //buttons = gd.getButtons();
        
        //int size = buttons.length;
        
        //buttons[1].setLabel("test");
        
        //gd.remove(buttons[1]);
        
        
        
        //if( buttons[1] != null) {
        
        //System.out.println(buttons[2].getLabel());
        
        //setSelected(true)
        
        //str = gd.getNextRadioButton();
        
        //System.out.println(str);
       
        //str = gd.getNextRadioButton();
        
        //System.out.println(str);

        //str = gd.getNextRadioButton();
        
        //System.out.println(str);
        
        
        if (gd.wasCanceled()) return 0;
        //IJ.log("Algorithm chosen:   "+ gd.getNextRadioButton());
        //IJ.log("Cars: "+ gd.getNextRadioButton());
        //IJ.log("Numbers: "+ gd.getNextRadioButton());
        
        if (gd.wasOKed()) {
          
            str= gd.getNextRadioButton();
            
           if ( ( str == " Canonical Variates Analysis - Matlab language - Processing 8 bit TIFF files - Supervised method (requires you to introduce a number of points by hand)" ) && (callalg == 0) )
           {
            IJ.log("Algorithm chosen:   "+ " Canonical Variates Analysis - Matlab language - Processing 8 bit TIFF files - Supervised method (requires you to introduce a number of points by hand)");
            //gd.windowDeactivated(e);
            callalg = 1;
               
               //try {
               //PrintWriter writer = new PrintWriter("processrunning.txt", "UTF-8");
               //writer.println(" %d", callalg);
               //}catch(IOException e7)  {}
               
            startAlgorithmcva();
            callalg = 0;
           }
           else if ( ( str == " Canonical Variates Analysis - Matlab language - Processing 16 bit TIFF files - Supervised method (requires you to introduce a number of points by hand)" ) && (callalg == 0) )
           {
               IJ.log("Algorithm chosen:   "+ " Canonical Variates Analysis - Matlab language - Processing 16 bit TIFF files - Supervised method (requires you to introduce a number of points by hand)");
               startAlgorithmcva16();
               callalg = 0;
               // return 1;
           }
            else if ( ( str == " Generalized Discriminant Analysis - Matlab language - Supervised method (requires you to introduce a number of points by hand)" ) && (callalg == 0) )
            {
             IJ.log("Algorithm chosen:   "+ " Generalized Discriminant Analysis - Matlab language - Supervised method (requires you to introduce a number of points by hand)");
             startAlgorithmgda();
             callalg = 0;
                // return 1;
            }
            else if ( ( str ==  " Linear Discriminant Analysis - Matlab language - Supervised method (requires you to introduce a number of points by hand)") && (callalg == 0) )
            {
             IJ.log("Algorithm chosen:   "+ " Linear Discriminant Analysis - Matlab language - Supervised method (requires you to introduce a number of points by hand)");
             startAlgorithmlda();
             callalg = 0;
                //  return 1;
                
            }
            else if ( ( str ==  " Neighborhood Component Analysis - Matlab language - Supervised method (requires you to introduce a number of points by hand)") && (callalg == 0) )
            {
                IJ.log("Algorithm chosen:   "+ " Neighborhood Component Analysis - Matlab language - Supervised method (requires you to introduce a number of points by hand)");
                startAlgorithmnca();
                callalg = 0;
                //  return 1;
                
            }
            else if ( ( str == " Canonical Variates Analysis - C language - Processing 8 bit TIFF files - Supervised method (requires you to introduce a number of points by hand)" ) && (callalg == 0) )
            {
                IJ.log("Algorithm chosen:   "+ " Canonical Variates Analysis - C language - Processing 8 bit TIFF files - Supervised method (requires you to introduce a number of points by hand)");
                startAlgorithmcvac();
                callalg = 0;
                //  return 1;
                
            }
            else if ( ( str == " Canonical Variates Analysis - C language - Processing 16 bit TIFF files - Supervised method (requires you to introduce a number of points by hand)" ) && (callalg == 0) )
            {
                IJ.log("Algorithm chosen:   "+ " Canonical Variates Analysis - C language - Processing 16 bit TIFF files - Supervised method (requires you to introduce a number of points by hand)");
                startAlgorithmcvac16();
                callalg = 0;
                //  return 1;
                
            }
            
                else if ( ( str ==  " Isomap - Matlab language - Supervised method (still requires you to introduce a number of points by hand)") && (callalg == 0) )
                {
                    IJ.log("Algorithm chosen:   "+ " Isomap - Matlab language - Supervised method (still requires you to introduce a number of points by hand)");
                    startAlgorithmisomap();
                    callalg = 0;
                    //  return 1;
                    
                }
                else if ( ( str ==  " Landmark Isomap - Matlab language - Supervised method (still requires you to introduce a number of points by hand)") && (callalg == 0) )
                {
                    IJ.log("Algorithm chosen:   "+ " Landmark Isomap - Matlab language - Supervised method (still requires you to introduce a number of points by hand)");
                    startAlgorithmlisomap();
                    callalg = 0;
                    //  return 1;
                    
                }
                else if ( ( str ==  " Principal Component Analysis - Matlab language - Supervised method (still requires you to introduce a number of points by hand)") && (callalg == 0) )
                {
                    IJ.log("Algorithm chosen:   "+ " Principal Component Analysis - Matlab language - Supervised method (still requires you to introduce a number of points by hand)" );
                    startAlgorithmpca();
                    callalg = 0;
                    //  return 1;
                    
                }
                else if ( ( str ==  " Probabilistic Principal Component Analysis - Matlab language - Supervised method (still requires you to introduce a number of points by hand)") && (callalg == 0) )
                {
                    IJ.log("Algorithm chosen:   "+ " Probabilistic Principal Component Analysis - Matlab language - Supervised method (still requires you to introduce a number of points by hand)" );
                    startAlgorithmppca();
                    callalg = 0;
                    //  return 1;
                    
                }
                else if ( ( str ==  " Gaussian Process Latent Variable Model - Matlab language - Supervised method (still requires you to introduce a number of points by hand)") && (callalg == 0) )
                {
                    IJ.log("Algorithm chosen:   "+ " Gaussian Process Latent Variable Model - Matlab language - Supervised method (still requires you to introduce a number of points by hand)" );
                    startAlgorithmgplvm();
                    callalg = 0;
                    //  return 1;
                    
                }
                else if ( ( str ==  " Principal Component Analysis - Matlab language - Unsupervised method (does not require you to introduce a number of points by hand but the results are poor)") && (callalg == 0) )
                {
                    IJ.log("Algorithm chosen:   "+ " Principal Component Analysis - Matlab language - It is Matlab own function - Unsupervised method (does not require you to introduce a number of points by hand but the results are poor)" );
                    startAlgorithmgpcarand();
                    callalg = 0;
                    //  return 1;
                    
                }
            //} // from else
            
            
            //return 1;
 
        } //from if wasoked
        
        //*/
        return 1;
        
    }
    
    
    public void startAlgorithmgpcarand() {
        
        Runtime r = Runtime.getRuntime();
        
        try {
            p = r.exec("java HelloWorldpcarand");
            
            
            
        } catch (IOException e) {
            
            System.out.println("There is an error, the Algorithm could not be started");
        }
        BufferedReader is = new BufferedReader(new InputStreamReader(p.getInputStream()));
        String aLine;
        try {
            while ((aLine = is.readLine()) != null)
                IJ.log(aLine);
            System.out.println(aLine);
            System.out.println("The Algorithm finished to run");
        } catch (IOException e) {}
        
        
        
        return;
        
    }

    
    public void startAlgorithmgplvm() {
        
        
        Runtime r = Runtime.getRuntime();
        
        try {
            p = r.exec("java HelloWorldgplvm");
           
            
            
        } catch (IOException e) {
            
            System.out.println("There is an error, the Algorithm could not be started");
        }
        BufferedReader is = new BufferedReader(new InputStreamReader(p.getInputStream()));
        String aLine;
        try {
            while ((aLine = is.readLine()) != null)
                IJ.log(aLine);
            System.out.println(aLine);
            System.out.println("The Algorithm finished to run");
        } catch (IOException e) {}
        
        return;
        
        
    }
    
    public void startAlgorithmppca() {
        
        Runtime r = Runtime.getRuntime();
        
        try {
            p = r.exec("java HelloWorldppca");
            
            
            
        } catch (IOException e) {
            
            System.out.println("There is an error, the Algorithm could not be started");
        }
        BufferedReader is = new BufferedReader(new InputStreamReader(p.getInputStream()));
        String aLine;
        try {
            while ((aLine = is.readLine()) != null)
                IJ.log(aLine);
            System.out.println(aLine);
            System.out.println("The Algorithm finished to run");
        } catch (IOException e) {}
        
        
        
        return;
        
    }
    
    
    public void startAlgorithmpca() {
        
        Runtime r = Runtime.getRuntime();
        
        try {
            p = r.exec("java HelloWorldpca");
            
            
            
        } catch (IOException e) {
            
            System.out.println("There is an error, the Algorithm could not be started");
        }
        BufferedReader is = new BufferedReader(new InputStreamReader(p.getInputStream()));
        String aLine;
        try {
            while ((aLine = is.readLine()) != null)
                IJ.log(aLine);
            System.out.println(aLine);
            System.out.println("The Algorithm finished to run");
        } catch (IOException e) {}
        
        
        
        return;
        
    }
    
    public void startAlgorithmlisomap() {
        
        Runtime r = Runtime.getRuntime();
        
        try {
            p = r.exec("java HelloWorldlisomap");
            
            
            
        } catch (IOException e) {
            
            System.out.println("There is an error, the Algorithm could not be started");
        }
        BufferedReader is = new BufferedReader(new InputStreamReader(p.getInputStream()));
        String aLine;
        try {
            while ((aLine = is.readLine()) != null)
                IJ.log(aLine);
            System.out.println(aLine);
            System.out.println("The Algorithm finished to run");
        } catch (IOException e) {}
        
        
        return;
        
    }
    
    public void startAlgorithmisomap() {
        
        Runtime r = Runtime.getRuntime();
        
        try {
            p = r.exec("java HelloWorldisomap");
            
            
            
        } catch (IOException e) {
            
            System.out.println("There is an error, the Algorithm could not be started");
        }
        BufferedReader is = new BufferedReader(new InputStreamReader(p.getInputStream()));
        String aLine;
        try {
            while ((aLine = is.readLine()) != null)
                IJ.log(aLine);
            System.out.println(aLine);
            System.out.println("The Algorithm finished to run");
        } catch (IOException e) {}
        
        
        return;
        
    }
    
    public void startAlgorithmcvac() {
        
        Runtime r = Runtime.getRuntime();
        
        try {
            p = r.exec("java HelloWorld");
            
            
            
        } catch (IOException e) {
            
            System.out.println("There is an error, the Algorithm could not be started");
        }
        BufferedReader is = new BufferedReader(new InputStreamReader(p.getInputStream()));
        String aLine;
        try {
            while ((aLine = is.readLine()) != null)
                IJ.log(aLine);
            System.out.println(aLine);
            System.out.println("The Algorithm finished to run");
        } catch (IOException e) {}

        return;
        
    }
    
    
    public void startAlgorithmcvac16() {
        
        Runtime r = Runtime.getRuntime();
        
        try {
            p = r.exec("java HelloWorld16");
            
            
            
        } catch (IOException e) {
            
            System.out.println("There is an error, the Algorithm could not be started");
        }
        BufferedReader is = new BufferedReader(new InputStreamReader(p.getInputStream()));
        String aLine;
        try {
            while ((aLine = is.readLine()) != null)
                IJ.log(aLine);
            System.out.println(aLine);
            System.out.println("The Algorithm finished to run");
        } catch (IOException e) {}
        
        return;
        
    }

    
    
    public void startAlgorithmnca() {
        
        Runtime r = Runtime.getRuntime();
        
        try {
            p = r.exec("java HelloWorldnca");
            
            
            
        } catch (IOException e) {
            
            System.out.println("There is an error, the Algorithm could not be started");
        }
        BufferedReader is = new BufferedReader(new InputStreamReader(p.getInputStream()));
        String aLine;
        try {
            while ((aLine = is.readLine()) != null)
                IJ.log(aLine);
            System.out.println(aLine);
            System.out.println("The Algorithm finished to run");
        } catch (IOException e) {}
        
        
        return;
        
    }
    
    public void startAlgorithmlda() {
        
        Runtime r = Runtime.getRuntime();
        
        try {
            p = r.exec("java HelloWorldlda");
            
            
            
        } catch (IOException e) {
            
            System.out.println("There is an error, the Algorithm could not be started");
        }
        BufferedReader is = new BufferedReader(new InputStreamReader(p.getInputStream()));
        String aLine;
        try {
            while ((aLine = is.readLine()) != null)
                IJ.log(aLine);
            System.out.println(aLine);
            System.out.println("The Algorithm finished to run");
        } catch (IOException e) {}
        
        
        return;
        
    }
    
    public void startAlgorithmgda() {
        
        Runtime r = Runtime.getRuntime();
        
        try {
            p = r.exec("java HelloWorldgda");
            
            
            
        } catch (IOException e) {
            
            System.out.println("There is an error, the Algorithm could not be started");
        }
        BufferedReader is = new BufferedReader(new InputStreamReader(p.getInputStream()));
        String aLine;
        try {
            while ((aLine = is.readLine()) != null)
                IJ.log(aLine);
            System.out.println(aLine);
            System.out.println("The Algorithm finished to run");
        } catch (IOException e) {}
        
        return;
        
    }

    //try {
    //PrintWriter writer = new PrintWriter("the-file-name2.txt", "UTF-8");
    //e1.printStackTrace(writer);
    //writer.println("The first line");
    //writer.println("The second line");
    //writer.close();
    // }catch(IOException e7)  {}


    public void startAlgorithmcva() {

        //IJ.log(" Algorithms ");

        Runtime r = Runtime.getRuntime();
        
        try {
            p = r.exec("java HelloWorldcva");
           // p = r.exec("java");
            
            // p = r.exec("java HelloWorldApp");
            //p = r.exec("matlab");
            
            
        } catch (IOException e) {
            //PrintWriter pw = new PrintWriter(new File("file.txt"));
            //e.printStackTrace(pw);
            System.out.println("There is an error, the Algorithm could not be started");
        }
        BufferedReader is = new BufferedReader(new InputStreamReader(p.getInputStream()));
        String aLine;
        try {
            while ((aLine = is.readLine()) != null)
                IJ.log(aLine);
            System.out.println(aLine);
            System.out.println("The Algorithm finished to run");
        } catch (IOException e) {}
        return;
    
    
}

    public void startAlgorithmcva16() {
        
        //IJ.log(" Algorithms ");
        
        Runtime r = Runtime.getRuntime();
        
        try {
            p = r.exec("java HelloWorldcva16");
            // p = r.exec("java");
            
            // p = r.exec("java HelloWorldApp");
            //p = r.exec("matlab");
            
            
        } catch (IOException e) {
            //PrintWriter pw = new PrintWriter(new File("file.txt"));
            //e.printStackTrace(pw);
            System.out.println("There is an error, the Algorithm could not be started");
        }
        BufferedReader is = new BufferedReader(new InputStreamReader(p.getInputStream()));
        String aLine;
        try {
            while ((aLine = is.readLine()) != null)
                IJ.log(aLine);
            System.out.println(aLine);
            System.out.println("The Algorithm finished to run");
        } catch (IOException e) {}
        return;
        
        
    }

    
    
    
    public boolean dialogItemChanged(GenericDialog gd, AWTEvent e) {
        if (gd.wasCanceled())
        {return false;}
        else{
            
            //String eee;
            //number = gd.getNextNumber();
            
            //Vector vec =   gd.getRadioButtonGroups();
            
            //int command ;
            //command = e.getID();
        
            // eee = e.toString();
            
            //System.out.println("Size of the vector: "+vec.size());
    
            //System.out.println(number);
            
            //IJ.log( gd.getNextRadioButton());
            //IJ.log( gd.getNextRadioButton());
            
            //vec.elementAt(0).setSelected(true);
            
            //System.out.println(command);
                   // IJ.log("Numbers: "+ gd.getNextRadioButton());
            return true;}
        //return (!gd.invalidNumber());}
    }
    
    //@Override
    //public void actionPerformed(ActionEvent ae) {
        // do something
        //if (gd.wasCanceled()) return false;
    //    IJ.log("Cities: ");
       // IJ.log("Cars: "+ gd.getNextRadioButton());
        //IJ.log("Numbers: "+ gd.getNextRadioButton());
       
    //}
    
    //@Override
    //public void actionPerformed(NonBlockingGenericDialog gd, AWTEvent e) {
    //    if (gd.wasCanceled()) return false;
    //    IJ.log("Cities: "+ gd.getNextRadioButton());
    //    IJ.log("Cars: "+ gd.getNextRadioButton());
    //    IJ.log("Numbers: "+ gd.getNextRadioButton());
    //    return true;
        
    //    // do something
        
    //}
    
   

}
