/*
 * HelloWorld.cpp
 *
 *  Created on: 22 August 2016
 *      Author: Dr. Corneliu Arsene
 *
 *   This software implements the Canonical Variates Analysis method (libhelloworld.jnilib file) for image
 *   processing: it reads the multispectral images from the same directory as where the libhelloworld.jnilib 
 *   file is located  and then produces a number of improved colour images in comparison to the original 
 *   multispectral images.
 *
 *
 *
 *
 *
 */

#include "jni.h"
#include <stdio.h>
#include "HelloWorld.h"

#include <math.h>
#include <assert.h>

#include <dirent.h>

#include </usr/local/Cellar/libiomp/20150701/include/libiomp/omp.h>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui.hpp>

#include <opencv/cv.h>
#include <opencv/highgui.h>

#include <time.h>



#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>




#include <iostream>


#include "gsl/matrix/gsl_matrix.h"
#include "gsl/specfunc/gsl_sf_bessel.h"
#include "gsl_math.h"
#include "gsl/gsl_blas.h"
#include <gsl/gsl_vector.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_eigen.h>
#include <gsl/gsl_sort_vector.h>
#include <gsl/eigen/gsl_eigen.h>





using namespace cv;
using namespace std;


// * THIS FILE IS COMPILED TO A LIBRARY WHICH IS CALLED BY A JAVA LIBRARY

JNIEXPORT void JNICALL
Java_HelloWorld_print(JNIEnv *env, jobject thisObj){
    
    
    
    
    
    int i,j,k;
    int grp1[9];//,grouping_vector[200] ;
    
    
    
    char *dir;
    int depth;
    
    dir ="/home";
    depth=0;
    
    DIR * dp1,*dp3;
    struct dirent* ep,*ep3;
    
   
    
    char* text;
    char pattern[6];
    char* text2;
    pattern[0]='\0';
    pattern[1]='\0';
    pattern[2]='\0';
    pattern[3]='\0';
    pattern[4]='\0';
    pattern[5]='\0';
    
    
    clock_t start, end;
    double cpu_time_used;
    
    start = clock();
    // * DETECT HOW MANY CLASS TEXT FILES EXIST (E.G. CLASS MANUSCRIPT, CLASS UNDERWRITING, ETC)
    
    
    text="Class";
    
    dp1 = opendir ("./");
    
    int acindex,newacindex;
    acindex = 0;
    newacindex =0;
    
    while (ep = readdir (dp1))
    {
        text2 = ep->d_name;
        
        pattern[0] = text2[0];//ep->d_name[0];
        pattern[1] = text2[1];//ep->d_name[1];
        pattern[2] = text2[2];//ep->d_name[2];
        pattern[3] = text2[3];//ep->d_name[3];
        pattern[4] = text2[4];//ep->d_name[4];
        pattern[5] ='\0';
        
        if( strcmp(text, pattern) == 0  )
        {
            acindex = acindex +1;
        }
        
    }
    
    (void) closedir (dp1);
    
    
    
    // * ONCE I KNOW HOW MANY CLASSES THERE ARE THEN I MEMORIZE THE PATH TO THE RESPECTIVE CLASS FILES
    
    
    char arrayclass[acindex][2024];
    dp3 = opendir ("./");
    
    
    
    while (ep3 = readdir (dp3))
        
    {
        
        text2 = ep3->d_name;
        
        pattern[0] = text2[0];//ep->d_name[0];
        
        pattern[1] = text2[1];//ep->d_name[1];
        
        pattern[2] = text2[2];//ep->d_name[2];
        
        pattern[3] = text2[3];//ep->d_name[3];
        
        pattern[4] = text2[4];//ep->d_name[4];
        
        pattern[5] ='\0';
        
        if( strcmp(text, pattern) == 0  )
        {
            
            strcpy(arrayclass[newacindex],ep3->d_name);
            
            newacindex = newacindex +1;
           
        }
    }
    
   
    
    // * I AM PREPARING TO READ THE CLASS TEXT FILES WHICH I DETECTED ABOVE
    
   
    (void) closedir (dp3);
    char cwd[1024],cwdtemp[1024];
    getcwd(cwd, sizeof(cwd));
    
    strcat(cwd,"/");
    
    FILE *file[acindex];
   
    for (int j=0; j < acindex; j=j+1)
    {
        strcpy(cwdtemp,cwd);
        
        strcat(cwdtemp,arrayclass[j]);
        if((file[j] = fopen(cwdtemp, "r"))==NULL)       /* open a text file for reading */
            exit(1);
        printf("%s\n",cwdtemp);
    }
    
    
    int over,over1,over2,over3,over4,over5,over6;
    
    int xx=0;
    double dd=0;
    char str[256],str1[256],str2[256],str3[256],str4[256],str5[256],str6[256],str7[256],str8[256];
    
    int classoverwriting[50][7];
    
    double classoverwriting1[1][7];
    
    
    int classunderwriting[50][7];
    int classmanuscript[50][7];
    int classbothuo[50][7];
    
    
    
    int i1;
    
    int nrclass[acindex];
    
    
    // * I AM DETECTING HOW MANY POINTS HAS EACH CLASS, FOR EXAMPLE CLASS MANUSCRIPT MIGHT HAVE 100 POINTS WHILE CLASS OVERWRITING MIGHT HAVE 120 POINTS, ETC
   
    
    
    for (int j=0; j < acindex; j=j+1)
    {
        fscanf(file[j], "  %s %s %s %s %s %s \n", &str,&str1, &str2,&str3,&str4,&str5);
        
        i1=0;
        
        while (!feof(file[j]))
        {
            fscanf(file[j], "  %lf %lf %lf %lf %lf %lf %lf\n", &classoverwriting1[1][1], &classoverwriting1[1][2], &classoverwriting1[1][3], &classoverwriting1[1][4], &classoverwriting1[1][5], &classoverwriting1[1][6], &classoverwriting1[1][7]);
            
            
           
            
            i1 =i1+1;
            
        }
        nrclass[j]=i1;
       
        
      
    }
    
  
    
    int sumtotalnrclass;
    sumtotalnrclass = 0;
    
    //exit(1);
    
    for (int j=0; j < acindex; j=j+1)
    {
        sumtotalnrclass  = sumtotalnrclass  +  nrclass[j];
    }
    
    

    
    int dummyvar;
    
    int **classtotal = new int*[sumtotalnrclass];
    for (int i = 0; i < sumtotalnrclass; i++)
    {
        classtotal[i] = new int[7];
    }
    
    printf(" \n");
    
    double testclass1,testclass2;
    
    // * I AM READING THE POINTS FROM EACH CLASS FILES
    
    
    
    i1=0;
    for (int j=0; j < acindex; j=j+1)
    {
        fseek( file[j], 0, SEEK_SET );
        fscanf(file[j], "  %s %s %s %s %s %s \n", &str,&str1, &str2,&str3,&str4,&str5);
        //printf ("%s\n", str);
        while (!feof(file[j]))
        {
         
            
              fscanf(file[j], "  %s %s %s %s %s %s %s\n", &str,&str1, &str2,&str3,&str4,&str5,&str6);
            
             testclass1 = atof(str5);
             testclass2 = atof(str6);
            
            classtotal[i1][6] = round(testclass1);
            classtotal[i1][7] = round(testclass2);
            
            
            
            i1 =i1+1;
         
        }
        
        fclose(file[j]);
    }
    
    
    
    
    
    
    
    char arraytiff[50][2024];//maximum number of images is 50
    
    
    
    
   // * I AM DETECTING THE NUMBER OF MULTISPECTRAL IMAGES AS THERE COULD BE 10 , 16, 23 , ETC MULTISPECTRAL IMAGES
    
   
    
    
    DIR * dp2;
    struct dirent* ep2;
    char* text1;
    char pattern1[6];
    char* text22;
    pattern1[0]='\0';
    pattern1[1]='\0';
    pattern1[2]='\0';
    pattern1[3]='\0';
    pattern1[4]='\0';
    pattern1[5]='\0';
    text1=".tif";
    dp2 = opendir ("./");
    int acindex1, sn1;
    acindex1 = 0;
    
   
    
    while (ep2 = readdir (dp2))
    {
        text22 = ep2->d_name;
        
        sn1 = strlen(text22);;//sizeof(text22);
        
        pattern1[0] = text22[sn1-4];//ep->d_name[0];
        
        pattern1[1] = text22[sn1-3];//ep->d_name[1];
        
        pattern1[2] = text22[sn1-2];//ep->d_name[2];
        
        pattern1[3] = text22[sn1-1];//ep->d_name[3];
        
        pattern1[4] ='\0';
        if( strcmp(text1, pattern1) == 0  )
        {
          
            strcpy(arraytiff[acindex1],ep2->d_name);
            printf("%s\n",arraytiff[acindex1]);
            acindex1 = acindex1 +1;
           
        }
    }
    
    char tiffext[4];
    
    char namefile[40];
    
    strncpy(namefile,arraytiff[0],strlen(arraytiff[0])-4);
    
    
     printf(" TEST 3333333 \n ");
    
    
    
    // *  I AM COPYING THE PATH TO THE MULTISPECTRAL IMAGES
    
    (void) closedir (dp2);
    
    char cwd1[1024],cwdtemp1[1024],*dfg;
    getcwd(cwd1, sizeof(cwd1));
    
    strcat(cwd1,"/");
    char arrayimage[acindex1][2024];
    
    char *arrayimage2[acindex1];
    
    printf("%s\n",cwd);
    printf("%s\n",cwd1);
    
    for (int j=0; j < acindex1; j=j+1)
    {
        
        strcpy(cwdtemp1,cwd1);
        
        strcat(cwdtemp1,arraytiff[j]);
        
        strcpy(arrayimage[j],cwdtemp1);
      
        printf("%s \n",arrayimage[j]);
       
    }
   
    
    
    
    
    double data_matrix[sumtotalnrclass][acindex1];
    
    
    
    //#pragma omp parallel for private(j,i)
    for (int i=0; i < sumtotalnrclass; i=i+1)
    {
        for (int j=0; j < acindex1; j=j+1)
        {
            data_matrix[i][j] = 0;
        }
    }

    
    
   std::vector<Mat> image(acindex1);
    
    
    
    std::vector<Mat> various_images;
    
 
   // * I AM READING THE IMAGES AND I PUT THEM IN THE VECTOR OF IMAGES CALLED VARIOUS_IMAGES
    
    for (int i=0; i < acindex1; i=i+1)
    {
        
            image[i] = imread(arrayimage[i], 0);
    
            various_images.push_back(image[i]);
        
    }
    
  
    
    s1 = image[0].rows;
    s2 = image[0].cols;
    
    //int s1s2;
    
    s1s2 = s1*s2;
    
    if(! image[0].data )                              // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
        // return -1;
    }
    
    
    
    // p o u b
    
    
    int *grouping_vector = new int[sumtotalnrclass] ;
    
    for (int k = 0; k < sumtotalnrclass; k++) {
        grouping_vector[k] = 0;
        
    }
    
    
    
    
    int *grp = new int[sumtotalnrclass] ;
    
    for (int k = 0; k < sumtotalnrclass; k++) {
        grp[k] = 0;
        
    }
    
    // * FROM THE MULTISPECTRAL IMAGES I AM SELECTING THE POINTS BASED ON THE CLASS FILES
    
    
    int indexonc;
    for (int j = 0; j < acindex1; j++) {
        
        indexonc = 0;
        for (int k = 0; k < acindex; k++) {
            
            for (int ss = 0; ss < nrclass[k]; ss++)
            {
                
                data_matrix[indexonc][j] =  (double) various_images[j].at<uchar>(classtotal[indexonc][7]-1,classtotal[indexonc][6]-1);
                
                indexonc = indexonc +1 ;
             
              
                
            }
        }
    }
  
    
       // * I AM COUNTING THE POINTS FROM EACH CLASS
    
    
    indexonc = 0;
    for (int k = 0; k < acindex; k=k+1) {
        
        for (int ss = 0; ss < nrclass[k]; ss=ss+1)
        {
            grouping_vector[indexonc] = 1+k;
            grp[indexonc]=1+k;
            indexonc = indexonc +1 ;
            
        }
    }
    
    printf("  \n ");

 
    
    double X[sumtotalnrclass][acindex1];
   
    
    for (int i = 0; i < sumtotalnrclass; i++) {
        for (int j = 0; j < acindex1; j++) {
          
            X[i][j] = data_matrix[i][j];
            
        }
        
        
    }
   
    
    int N,D,K;
    
    float nk[acindex1];
    float alpha,xmg[acindex1],xmk[acindex][acindex1];
    int index;
    float xdiff[sumtotalnrclass], transxdiff[sumtotalnrclass][1];
    float sum[acindex1][acindex1], sumare;

   
    // * I AM IMPLEMENTING THE CANONICAL VARIATES ANALYSIS METHOD BASED ON THE MATLAB VERSION OF THIS METHOD
    
    
    N = sumtotalnrclass;//sizeof(X);
    D = acindex1;//sizeof(X[0][0])-1;
    
    
    
    for (j=0; j < acindex1; j=j+1)
    {
        xmg[j] = 0;
        
    }
    
    K = grp[0];
    for (int j=1;j<sumtotalnrclass;j++)
    {
        if (K < grp[j])
        {
            K = grp[j];
           
        }
            }
    
    index=0;
    
      for (j=0;j<acindex1;j++)
    {
        alpha =0;
        for (i=0;i<sumtotalnrclass;i++)
        {
            alpha = alpha + X[i][j];
            
        }
        xmg[j] = alpha/sumtotalnrclass;
        
    }
    
    
    
    
   
    for (i=0; i < K; i=i+1)
    {
        for (j=0; j < acindex1; j=j+1)
        {
            xmk[i][j] = 0;
            
        }
    }
    
    
    float **difference = new float*[acindex1];
    for (int i = 0; i < acindex1; i++)
    {
        difference[i] = new float[acindex1];
    }
    
    
    
    float **difference1 = new float*[acindex1];
    for (int i = 0; i < acindex1; i++)
    {
        difference1[i] = new float[acindex1];
    }
    
    float suma = 0;
    
    double Xinter[sumtotalnrclass][acindex1];
  
    //printf("Hello from thread %d, nthreads %d\n", omp_get_thread_num(), omp_get_num_threads());
    
    //#pragma omp parallel for
    

   /*#pragma omp parallel for
    for(int n=0; n<10; n++)
    {
        printf(" %d", n);
    }
    printf(".\n");*/
    
    
    //#pragma omp parallel num_threads(5)
    //{
    
    //#pragma omp parallel for
    
    
    //#pragma omp parallel for private(k,i,c)
    for (k=1;k < acindex+1; k++)
    {
        index = 0;
        
        for (i=0;i<sumtotalnrclass;i++)
        {
            if (grp[i] == k)
            {
                
                for (int c=0;c<acindex1;c++)
                {
                    Xinter[index][c] = X[i][c];
                    
                }
                index = index +1;
                           }
            
        }
        //printf("Hello from thread %d, nthreads %d\n", omp_get_thread_num(), omp_get_num_threads());
       
        for (int c=0;c<acindex1;c++)
        {
            suma = 0;
            for (int d=0;d<nrclass[k-1];d++)
                suma = suma + Xinter[d][c];
            xmk[k-1][c] = suma/nrclass[k-1];
            
        }
       
        
    }
    
    //}
    
    
    float **S = new float*[D];
    for (int i = 0; i < D; i++)
    {
        S[i] = new float[D];
    }
    
    
    float **B = new float*[D];
    for (int i = 0; i < D; i++)
    {
        B[i] = new float[D];
    }
    
    
    float **xsumdiff = new float*[D];
    for (int i = 0; i < D; i++)
    {
        xsumdiff[i] = new float[D];
    }
    
    
    for (i=0; i < D; i=i+1)
    {
        for (j=0; j < D; j=j+1)
        {
            S[i][j] = 0;
        }
    }
    
    for (i=0; i < D; i=i+1)
    {
        for (j=0; j < D; j=j+1)
        {
            xsumdiff[i][j] = 0;
        }
    }
    
    
    //#pragma omp parallel for private(i,j,c)
    for (int i=0;i<sumtotalnrclass;i++)
    {
        
        for (int j=0;j<acindex1;j++)
        {
          
            index = grp[i];
            xdiff[j] =  X[i][j] - xmk[index-1][j] ;
         
        }
       
        for (int c = 0; c < acindex1; c++)
        {
            transxdiff[c][1] = xdiff[c];
            
        }
        
        //multiply xdiff'*xdiff
        for (int c=0;c<acindex1;c++)
        {
            for (int d = 0; d < acindex1; d++)
            {
                xsumdiff[c][d] = transxdiff[c][1]*xdiff[d];
                //printf ("%f \n", xsumdiff[c][d]);
            }
        }
        
        for (int c = 0; c < acindex1; c++)
        {
            for (int d = 0; d < acindex1; d++)
            {
                //printf ("%f \n", S[c][d]);
                S[c][d] = S[c][d] + xsumdiff[c][d];
            }
        }
        
    }
    
    //#pragma omp parallel for private(i,j)
    for (i=0; i < acindex1; i=i+1)
    {
        
        for (j=0; j < acindex1; j=j+1)
        {
            
            S[i][j] = S[i][j]/(sumtotalnrclass-acindex);
            
            
        }
      }
    
    
    
    printf("\n");
    
    //#pragma omp parallel for private(i,j)
    for (int i=0; i < D; i=i+1)
    {
        for (int j=0; j < D; j=j+1)
        {
            
            B[i][j] = 0;
            //printf("%f \n",B[i][j]);
            
        }
    }
    
    
    double Xtemp[sumtotalnrclass][acindex1];
    
    
    //#pragma omp parallel for private(i)
    for(i = 0; i < sumtotalnrclass; i++)
    {
        //    //printf("%3d: ", i);
        for(j = 0; j < acindex1; j++)
            Xtemp[i][j] = X[i][j];
        
    }
    
    
    //nrclass  acindex

    
    //#pragma omp parallel for private(k,i,d,c)
    for (k =0;k<acindex;k++)
    {
        for (i=0;i<acindex1;i++)
            
        {
            
            difference[1][i] = nrclass[k]*(xmk[k][i] - xmg[i]);
            difference1[1][i] = xmk[k][i] - xmg[i];
            
        }
        for(int d = 0 ; d < acindex1 ; d++ )
            transxdiff[d][1] = difference[1][d];
        
        for (int d = 0; d < acindex1; d++)
        {
            for (int c = 0; c < acindex1; c++)
            {
                
                sum[c][d] = transxdiff[c][1]*difference1[1][d];
                //printf("%f \n",sum[c][d]);
                
            }
            
        }
        
        for (int c=0; c < acindex1; c=c+1)
        {
            for (int d=0; d < acindex1; d=d+1)
            {
                B[c][d] = B[c][d]+sum[c][d];
                
                //
                printf("%f ",B[c][d]);
            }
             printf(" \n");

        }
        
        printf(" \n");

    }
    
    
    double coefficient;
    double coefficient1;
    
    coefficient1 = acindex-1;
    
    coefficient = acindex/coefficient1;
   
     //printf(" %d \n",acindex);
    //printf(" %lf \n",coefficient);
    //printf(" %d \n",sumtotalnrclass);
    
    //#pragma omp parallel for private(d,c)
    for (int c=0; c < acindex1; c=c+1)
    {
        for (int d=0; d < acindex1; d=d+1)
        {
            
            B[c][d] = coefficient*B[c][d]/sumtotalnrclass;
           
            //printf("%f ",B[c][d]);
            
        }
        //printf(" \n");
    }
    
        float vectork[acindex1];
    
    float finalk =0;
    
    gsl_matrix * AA , *SS;
    
    gsl_vector * eval;
    gsl_matrix * evec;
    gsl_eigen_gensymmv_workspace  * w;
    //, gsl_vector_complex * eval, gsl_matrix_complex * evec, gsl_eigen_nonsymmv_workspace * w
    int err;
    err = 1;
    
    
    // * I AM USING THE GSL GNU FUNCTIONS GSL_MATRIX_ALLOC , GSL_EIGEN_GENSYMMV_ALLOC , ETC TO CALCULATE THE EIGEN VECTORS
    
    AA = gsl_matrix_alloc(acindex1, acindex1);
    SS = gsl_matrix_alloc(acindex1, acindex1);
    eval = gsl_vector_alloc(acindex1);
    evec  = gsl_matrix_alloc(acindex1, acindex1);
    w = gsl_eigen_gensymmv_alloc(acindex1);
    
    //#pragma omp parallel for private(i,j)
    for (int i = 0; i < acindex1; i++)
        for (int j = 0; j < acindex1; j++)
            gsl_matrix_set (AA, i, j, B[i][j]);// B[i][j]);
    
    for (int i = 0; i < acindex1; i++)
        for (int j = 0; j < acindex1; j++)
            gsl_matrix_set (SS, i, j, S[i][j]);// B[i][j]);
    
    
    
    int status;
    
    gsl_set_error_handler_off();
    
    status = gsl_eigen_gensymmv( AA,  SS,  eval, evec,  w) ;
    
    
    double a;
    int indexa[acindex1];
    
    for (i = 0; i < acindex1; i++)
    {
        indexa[i] = i;
    }
    
    for (i = 0; i < acindex1; i++)
    {
        indexa[i]= i;
    }
    
    /*for(i = 0; i < 23; i++)
     {
     printf("%3d %f %i \n", i,  gsl_vector_get(eval, i) ,indexa[i]);
     }*/
    
    
    int prst;
    //#pragma omp parallel for private(i,j)
    for (i = 0; i < acindex1; i++)
    {
        //indexa[i]= i;
        for (j = i ; j < acindex1; j++)
        {
            if (gsl_vector_get(eval, i) < gsl_vector_get(eval, j))
            {
                
                a = gsl_vector_get(eval, i);
                
                gsl_vector_set(eval, i, gsl_vector_get(eval, j) );
                prst = indexa[i];
                indexa[i]= indexa[j];
                indexa[j]= prst;
                
                gsl_vector_set(eval, j, a);
                
            }
            else
            {
                //gsl_vector_set(eval, i, (-1)*gsl_vector_get(eval, i) );
            }
        }
    }
    
    
      printf("  \n"  );
    printf(" EIGENVALUES \n ");
    
    for(i = 0; i < acindex1; i++)
    {
        printf("%3d %f %i \n", i,  gsl_vector_get(eval, i) ,indexa[i]);
    }
    
    
    double summ = 0;
    double Xresult[sumtotalnrclass][acindex1];
    
    double tempcoef[acindex1][acindex1];
    
    for (i = 0; i < acindex1; i++)
    {
        for (j = 0; j < acindex1; j++)
        {
            tempcoef[i][j] = gsl_matrix_get(evec,i,j) ;
            
        }
    }
       printf("  \n"  );
     printf(" EIGEN VECTORS \n ");
    
    for(i = 0; i < acindex1; i++)
    {
        //printf("%3d: ", i);
        for(j = 0; j < acindex1; j++)
            printf("%lf ",   gsl_matrix_get(evec,i,j)  );
        printf("\n");
    }
    
    
    
    
    double coef[acindex1][acindex1];
    
    for(i = 0; i < acindex1; i++)
    {
        //printf("%3d: ", i);
        for(j = 0; j < acindex1; j++)
            coef[i][j] =  gsl_matrix_get(evec,i,j) ;
        
    }
    
    
    
    
    
    // *  I AM CALCULATING THE NEW IMAGE POINTS BASED ON THE PARAMETERS CALCULATED BY THE GSL GNU FUNCTIONS
    
    //#pragma omp parallel for
    //#pragma omp parallel for private(k,i,j)
    for(i=0;i<sumtotalnrclass;i++)
    {
        for(j=0;j<acindex1;j++)
        {
            summ=0;
            for(k=0;k<acindex1;k++)
            {
                
                summ=summ+Xtemp[i][k]*gsl_matrix_get(evec, k, j);
                
            }
            Xresult[i][j]=summ;
        }
        
    }
    
    
    
    
     double** newmatrix1= new double*[s1];
    
    for (int i = 0; i < s1; i++)
    {
        newmatrix1[i] = new double[s2];
    }

    
     //static double newmatrix2[5412][7216];
    double** newmatrix2= new double*[s1];
    for (int i = 0; i < s1; i++)
    {
        newmatrix2[i] = new double[s2];
    }
     //static double newmatrix3[5412][7216];
   
    double** newmatrix3= new double*[s1];
    for (int i = 0; i < s1; i++)
    {
        newmatrix3[i] = new double[s2];
    }
    
    
    
    
    for(i = 0; i < s1; i++)
    {
        for(j = 0; j < s2; j++)
        {
            newmatrix1[i][j] = 0;
        }
    }
    
    for(i = 0; i < s1; i++)
    {
        for(j = 0; j < s2; j++)
        {
            newmatrix2[i][j] = 0;
        }
    }
    
    for(i = 0; i < s1; i++)
    {
        for(j = 0; j < s2; j++)
        {
            newmatrix3[i][j] = 0;
        }
    }
  
    
    
    double coef1[acindex1][acindex1];
    double score1[sumtotalnrclass][acindex1];
    
    
    
    //#pragma omp parallel for private(i,j)
    for (int i=0; i < sumtotalnrclass; i=i+1)
    {
        for (int j=0; j < acindex1; j=j+1)
        {
            score1[i][j] = 0;
        }
    }
    
    
    
    for (int i=0; i < acindex1; i=i+1)
    {
        for (int j=0; j < acindex1; j=j+1)
        {
            coef1[i][j] = 0;
        }
    }
    
    
    
    
    
    for (int i=0; i < sumtotalnrclass; i=i+1)
    {
        for (int j=0; j < acindex1; j=j+1)
        {
            score1[i][j] = Xresult[i][j];
        }
    }
    
    
    for (int i=0; i < acindex1; i=i+1)
    {
        for (int j=0; j < acindex1; j=j+1)
        {
            coef1[i][j] = coef[i][j];
        }
    }
    
    
    
    
     // *  I AM IMPLEMENTING THE POST-PROCESSING WHICH EXIST IN THE ORIGINAL CANONICAL VARIATES ANALYSIS METHOD IMPLEMENTED INITIALLY IN MATLAB
    
    
    //#pragma omp parallel for private(j,i,k)
    for(i = 0; i < s1; i++)
    {
        for(j = 0; j < s2; j++)
        {
            for(k = 0; k < acindex1; k++)
            {
                newmatrix1[i][j] = newmatrix1[i][j]  + ( (double)various_images[k].at<uchar>(i,j) )*coef1[k][0];
              
                newmatrix2[i][j] = newmatrix2[i][j]  + ( (double)various_images[k].at<uchar>(i,j) )*coef1[k][1];
                
                newmatrix3[i][j] = newmatrix3[i][j]  + ( (double)various_images[k].at<uchar>(i,j) )*coef1[k][2];
                
                
                
            }
            
           
        }
      
    }
    
    
    double minimum1,minimum2,minimum3;
    double maximum1,maximum2,maximum3;
    
    
    double **range_cv1 = new double*[s1];
    for (int i = 0; i < s1; i++)
    {
        range_cv1[i] = new double[s2];
    }
    
    
    double **range_cv2 = new double*[s1];
    for (int i = 0; i < s1; i++)
    {
        range_cv2[i] = new double[s2];
    }
    
    double **range_cv3 = new double*[s1];
    for (int i = 0; i < s1; i++)
    {
        range_cv3[i] = new double[s2];
    }
    
    
    
    
    minimum1= newmatrix1[0][0];
    for(int i=0; i<s1; i++)
    {
        for(int j=0; j<s2; j++)
        {
            if( newmatrix1[i][j]< minimum1)
            {
                minimum1=newmatrix1[i][j];
            }
        }
    }
    
   
    minimum2= newmatrix2[0][0];
    for(int i=0; i<s1; i++)
    {
        for(int j=0; j<s2; j++)
        {
            if( newmatrix2[i][j]< minimum2)
            {
                minimum2=newmatrix2[i][j];
            }
        }
    }
    
    minimum3= newmatrix3[0][0];
    for(int i=0; i<s1; i++)
    {
        for(int j=0; j<s2; j++)
        {
            if( newmatrix3[i][j]< minimum3)
            {
                minimum3=newmatrix3[i][j];
            }
        }
    }
  
    maximum1= newmatrix1[0][0];
    for(int i=0; i<s1; i++)
    {
        for(int j=0; j<s2; j++)
        {
            if( newmatrix1[i][j]> maximum1)
            {
                maximum1=newmatrix1[i][j];
            }
        }
    }
    
    maximum2= newmatrix2[0][0];
    for(int i=0; i<s1; i++)
    {
        for(int j=0; j<s2; j++)
        {
            if( newmatrix2[i][j]> maximum2)
            {
                maximum2=newmatrix2[i][j];
            }
        }
    }
    
    maximum3= newmatrix3[0][0];
    for(int i=0; i<s1; i++)
    {
        for(int j=0; j<s2; j++)
        {
            if( newmatrix3[i][j]> maximum3)
            {
                maximum3=newmatrix3[i][j];
            }
        }
    }
    
    
    
    range_cv1 = range_map(newmatrix1, minimum1, maximum1);
    
    
    range_cv2 = range_map(newmatrix2, minimum2, maximum2);
    
    range_cv3 = range_map(newmatrix3, minimum3, maximum3);
    
    
    
    int aa,bb,cc;
    
    
     printf("  \n"  );
    
    printf(" A SET OF 8 PICTURES ARE PRODUCED ");
    
    
    cv::Mat img16(s1, s2, CV_8UC3);
    
    vector<int> compression_params;
    compression_params.push_back(CV_IMWRITE_PNG_COMPRESSION);
    compression_params.push_back(9);
    
    
    for (int i = 0; i < s1; i++) {
        for (int j = 0; j < s2; j++) {
            
           
            
            img16.at<cv::Vec3b>(i,j)[1] =  (255-range_cv2[i][j]);
            img16.at<cv::Vec3b>(i,j)[2] = (255-range_cv1[i][j]);
            img16.at<cv::Vec3b>(i,j)[3] = (255-range_cv3[i][j]);
            
        }
    }
    
    char fileword[100];
    strcpy(fileword,namefile);
    strcat(fileword,"_image_rangecvasecond.tiff");
    
    
    //end = clock();
    //cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    //printf("  \n"  );
    
    //printf(" %lf ", cpu_time_used  );
    
    //exit(1);
    
    
    cv::imwrite(fileword, img16);
    
    
    cv::Mat img162(s1, s2, CV_8UC3);
    
    
    for (int i = 0; i < s1; i++) {
        for (int j = 0; j < s2; j++) {
            
            
            img162.at<cv::Vec3b>(i,j)[1] =  range_cv2[i][j];
            img162.at<cv::Vec3b>(i,j)[2] = range_cv1[i][j];
            img162.at<cv::Vec3b>(i,j)[3] = range_cv3[i][j];
            
        }
    }
    
    char fileword1[100];
    strcpy(fileword1,namefile);
    strcat(fileword1,"_image_rangecva.tiff");
    
    
     cv::imwrite(fileword1, img162);
    
    
    
    
    double minscore1,minscore2,minscore3;
    double maxscore1,maxscore2,maxscore3;
    
    
    minscore1=0;
    minscore1= score1[0][0];
    for(int i=0; i<sumtotalnrclass; i++)
    {
        
        if( score1[i][0]< minscore1)
        {
            minscore1=score1[i][0];
        }
        
    }
    
    minscore2==0;
    minscore2= score1[0][1];
    for(int i=0; i<sumtotalnrclass; i++)
    {
        
        if( score1[i][1]< minscore2)
        {
            minscore2=score1[i][1];
        }
        
    }
    
    minscore3==0;
    minscore3= score1[0][2];
    for(int i=0; i<sumtotalnrclass; i++)
    {
        
        if( score1[i][2]< minscore3)
        {
            minscore3=score1[i][2];
        }
        
    }
    
    maxscore1=0;
    maxscore1= score1[0][0];
    for(int i=0; i<sumtotalnrclass; i++)
    {
        
        if( score1[i][0]> maxscore1)
        {
            maxscore1=score1[i][0];
        }
        
    }
    
    maxscore2=0;
    maxscore2= score1[0][1];
    for(int i=0; i<sumtotalnrclass; i++)
    {
        
        if( score1[i][1]> maxscore2)
        {
            maxscore2=score1[i][1];
        }
        
    }
    
    maxscore3=0;
    maxscore3= score1[0][2];
    for(int i=0; i<sumtotalnrclass; i++)
    {
        
        if( newmatrix3[i][2]> maxscore3)
        {
            maxscore3=score1[i][2];
        }
        
    }
    
    
    double **score_cv1 = new double*[s1];
    for (int i = 0; i < s1; i++)
    {
        score_cv1[i] = new double[s2];
    }
    
    
    double **score_cv2 = new double*[s1];
    for (int i = 0; i < s1; i++)
    {
        score_cv2[i] = new double[s2];
    }
    
    double **score_cv3 = new double*[s1];
    for (int i = 0; i < s1; i++)
    {
        score_cv3[i] = new double[s2];
    }
    
    
    score_cv1 = range_map(newmatrix1, minscore1, maxscore1);
    
    score_cv2 = range_map(newmatrix2, minscore2, maxscore2);
    
    score_cv3 = range_map(newmatrix3, minscore3, maxscore3);
    
    
    
    
    cv::Mat img163(s1, s2, CV_8UC3);
    
    
    for (int i = 0; i < s1; i++) {
        for (int j = 0; j < s2; j++) {
            
            
            img163.at<cv::Vec3b>(i,j)[1] =  score_cv2[i][j];
            img163.at<cv::Vec3b>(i,j)[2] = score_cv1[i][j];
            img163.at<cv::Vec3b>(i,j)[3] = score_cv3[i][j];
            
        }
    }
    
    char fileword2[100];
    strcpy(fileword2,namefile);
    strcat(fileword2,"_image_score_rangecva.tiff");
    
    
    cv::imwrite(fileword2, img163);

    
    
    cv::Mat img164(s1, s2, CV_8UC3);
    
  
    
     for (int i = 0; i < s1; i++) {
        for (int j = 0; j < s2; j++) {
            
            
            img164.at<cv::Vec3b>(i,j)[1] =  (255-score_cv2[i][j]);
            img164.at<cv::Vec3b>(i,j)[2] = (255-score_cv1[i][j]);
            img164.at<cv::Vec3b>(i,j)[3] = (255-score_cv3[i][j]);
            
        }
    }
 
    
    char fileword3[100];
    strcpy(fileword3,namefile);
    strcat(fileword3,"_image_score_rangecvasecond.tiff");
    
    
    cv::imwrite(fileword3, img164);
    
    
    
       // * I AM PRODUCING THE 8 BIT IMAGES OF THE PERCENTILE
    
    double required_percentiles[8];
    
    required_percentiles[0] = 0.01;
    required_percentiles[1] = 0.1;
    required_percentiles[2] = 1;
    required_percentiles[3] = 5;
    required_percentiles[4] = 99.99;
    required_percentiles[5] = 99.9;
    required_percentiles[6] = 99;
    required_percentiles[7] = 95;
    
    
    
    int sizerows,sizecolumns;
    
    
    int n_percentiles;
    
    n_percentiles = (int) 8 / 2;
    
    double *percentiles_cv1 = new double[5];
    double *percentiles_cv2 = new double[5];
    double *percentiles_cv3 = new double[5];
    double *percentiles_cv4 = new double[5];
    double *percentiles_cv5 = new double[5];
    
    for (int i = 0; i < 5; i++)
    {
        percentiles_cv1[i] = 0;
        percentiles_cv2[i] = 0;
        percentiles_cv3[i] = 0;
        percentiles_cv4[i] = 0;
        percentiles_cv5[i] = 0;
        
        
        
    }
    
    percentiles_cv1 = Percentile(newmatrix1, required_percentiles);
    percentiles_cv2 = Percentile(newmatrix2, required_percentiles);
    percentiles_cv3 = Percentile(newmatrix3, required_percentiles);
    
    
    double **per_cv1 = new double*[s1];
    for (int i = 0; i < s1; i++)
    {
        per_cv1[i] = new double[s2];
    }
    
    
    double **per_cv2 = new double*[s1];
    for (int i = 0; i < s1; i++)
    {
        per_cv2[i] = new double[s2];
    }
    
    double **per_cv3 = new double*[s1];
    for (int i = 0; i < s1; i++)
    {
        per_cv3[i] = new double[s2];
    }
    
    cv::Mat img165(s1, s2, CV_8UC3);
    char str22[35];
    
    
    for (int i = 0; i < n_percentiles ; i++)
    {
        per_cv1 = range_map(newmatrix1,percentiles_cv1[i] , percentiles_cv1[i+n_percentiles]);
        
        per_cv2 = range_map(newmatrix2, percentiles_cv2[i], percentiles_cv2[i+n_percentiles]);
        
        per_cv3 = range_map(newmatrix3, percentiles_cv3[i], percentiles_cv3[i+n_percentiles]);
        
      
        
       
        for (int i = 0; i < s1; i++) {
            for (int j = 0; j < s2; j++) {
                
                img165.at<cv::Vec3b>(i,j)[1] =  per_cv2[i][j];
                img165.at<cv::Vec3b>(i,j)[2] =  per_cv1[i][j];
                img165.at<cv::Vec3b>(i,j)[3] =  per_cv3[i][j];
                
            }
        }
        
        
        sprintf(str22,"_image_percentile_%lfcva.tiff", required_percentiles[i]);
        
        
        strcpy(fileword3,namefile);
        strcat(fileword3,str22);
        
        cv::imwrite(fileword3, img165);
        
        
        
        
    }
    
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    
    printf(" %lf ", cpu_time_used  );
    
    return;
}




//double* Percentile(double arr[5412][7216], double percentile[8])
double* Percentile(double** arr, double percentile[8])
{
    
    int index,size1;
    
    index =0;
    
    
    
    double *resultingvector = new double[s1s2];
    
    size1 = sizeof(percentile);
    
    for(int i = 0; i < s1; i++)
    {
        for(int j = 0; j < s2; j++)
        {
            
            resultingvector[index] = arr[i][j];
            index = index +1;
        }
        
    }
    
    double aa;
    
    
    
    gsl_vector * v = gsl_vector_alloc (s1s2);
    
    for (int i = 0; i < s1s2; i++)
    {
        gsl_vector_set (v, i,resultingvector[i] );
    }
    
    
    
    gsl_sort_vector(v);
    
    for (int i = 0; i < s1s2; i++)
    {
        resultingvector[i] = gsl_vector_get (v, i);
    }
    
    
    int index2;
    
    double *percentile_values = new double[size1];
    
    for(int i = 0; i < size1; i++)
    {
        index2 = round(1 + (percentile[i]/100)*(s1s2-1));
        percentile_values[i] = resultingvector[index2];
    }
    
    return percentile_values;
}

int compare_doubles (const double * a,
                                 const double * b)
{
    if (*a > *b)
        return 1;
    else if (*a < *b)
        return -1;
    else
        return 0;
}

double* quickSort( double a[], long l, long r)
{
    long j;
    
    //r = 39052992;
    if( l < r )
    {
        // divide and conquer
        j = partition( a, l, r);
        a = quickSort( a, l, j-1);
        a = quickSort( a, j+1, r);
    }
    //for(int i = 0; i < 39052992; i++)
    //{
    printf(" %d  \n",  j  );
    //}
    return a;
}


long partition(double a[], long l, long r) {
    long  i, j;
    double pivot,t;
    pivot = a[l];
    i = l; j = r+1;
    
    while( 1)
    {
        do ++i; while( a[i] <= pivot && i <= r );
        do --j; while( a[j] > pivot );
        if( i >= j ) break;
        t = a[i]; a[i] = a[j]; a[j] = t;
    }
    t = a[l]; a[l] = a[j]; a[j] = t;
    return j;
}

//double** range_map(double newmatrix[5412][7216], double minimum, double maximum)
double** range_map(double** newmatrix, double minimum, double maximum)

{
    
    
    
    //static double newimage[5412][7216];
    
    double **newimage = new double*[s1];
    for (int i = 0; i < s1; i++)
    {
        newimage[i] = new double[s2];
    }
    
    
    
    double out_low, out_high, out_range_low, out_range_high,v,v2;
    
    out_low = 0;
    out_high =255;
    out_range_low = 0;
    out_range_high = 255;
    
    double in_low,in_high;
    
    in_low = minimum;
    in_high = maximum;
    
    
    for(int i = 0; i < s1; i++)
    {
        for(int j = 0; j < s2; j++)
        {
            v =  newmatrix[i][j];
            if (v < in_low)
                v2 = out_range_low;
            else if (v > in_high)
                v2 = out_range_high;
            else
                v2 = ((v - in_low) / (in_high - in_low)) * (out_high - out_low) + out_low;
            
            
            //newimage[i][j] = uint8(floor(v2 + 0.5));
            newimage[i][j] = uint8_t(floor(v2+0.5));
            
            
            
        }
    }
    return newimage;
}


