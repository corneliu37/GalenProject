
This software reads a number of multispectral images - 8 bit files - located in ImageJ directory , applies the Canonical Variates Analysis algorithm and produces a number of enhanced colour images using the produced 8 bit grayscale images.  The software is using the GSL GNU and OpenCV libraries and it was written for MAC OS X - Yosemite but with minor modifications should run on any platforms.

This code was written by Dr Corneliu Arsene while in the Faculty of Humanities at the University of Manchester, Manchester, United Kingdom between September 2015 and August 2016 on the project financed by Arts and Humanities Research Council (AHRC) of UK entitled "The Syriac Galen Palimpsest : Galen's On Simple Drugs and the Recovery of Lost Texts through Sophisticated Imaging Techniques" (project reference number AH/M005704/1).

Please acknowledge the project financed by AHRC of UK and Mr Corneliu Arsene if you are going to use this software anywhere in your work.  This is in addition to the license for this software which is in a different file. 

It is provided here with no warranty. Direct all questions and requests to galenpalimpsestproject@gmail.com.


Technical details (not to be confused by the name of the files):

1) The Dimensionality_Reduction_Task.java and Dimensionality_Reduction_Task.class files must be put in the subdirectory ImageJ/Plugins/Tools

2) The rest of the files must be put in the ImageJ directory: HelloWorld.c , HelloWorld.o , libhelloworld.jnilib , ClassManuscript.txt  , ClassOverwriting.txt , ClassUnderwriting.txt , ClassBothUO.txt , HelloWorld.h , HelloWorld.class , HelloWorldcva.java , HelloWorld.class , HelloWorld.java 

3) You can re-compile the HelloWorld.c in the TERMINAL window of the MAC OS X with the following commands (you will have to add the name of your computer below). 

g++ -I"$Name_of_your_computer_here/Library/Java/JavaVirtualMachines/jdk1.7.0_71.jdk/Contents/Home/include" -I"$Name_of_your_computer_here/Library/Java/JavaVirtualMachines/jdk1.7.0_71.jdk/Contents/Home/include/darwin"  -c HelloWorld.c

g++ -I"$Name_of_your_computer_here/opt/local/lib" -dynamiclib -lopencv_highgui -lopencv_imgcodecs -lopencv_imgproc -lopencv_core -lopencv_features2d -lopencv_flann   -lgsl -o  libhelloworld.jnilib  HelloWorld.o


4) HelloWorldcva.java calls Matlab software in order to run the Canonical Variates Analysis implemented in Matlab in the file do_canonical_variatescva3.m.

5) do_canonical_variatescva3.m file implementing the Canonical Variates Analysis method
written by Geoff Bohling - March 2006, from the University of Kansas, US. 

6) HelloWorld.java calls the C library called libhelloworld.jnilib (processing 8 bit image files) implementing the Canonical Variates Analysis method written by Corneliu Arsene - August 2016, University of Manchester, UK (the C version of the above Matlab function).

7) ClassManuscript.txt  , ClassOverwriting.txt , ClassUnderwriting.txt , ClassBothUO.txt examples of text files produced with ImageJ based on the selection of points from a multispectral image of the folio/page 102v-107r_B of the Syriac Galen Palimpsest available at the web address digitalgalen.net .

8) Obviously the Canonical Variates Analysis method is implemented in the C file called HelloWorld.c



  
