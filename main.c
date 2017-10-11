/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: kingJ
 *
 * Created on September 20, 2017, 9:05 AM
 */

#include <stdio.h>
#include <stdlib.h>

char* read_file(int count, char *p, FILE *fp);
void write_file(int count, char *p, FILE *outfile);
/*
 * 
 */
int main(int argc, char** argv) {
    
    int count=0;
     char userinput[56];
     char useroutput[56];
    printf("Please enter the file name you would like to read in. ex: msg.txt\n");
    gets(userinput);//get user input
    FILE *fp = fopen(userinput,"r");
        printf("Please enter the file name you would like write to. ex: msg.txt\n");
    gets(useroutput);//getg user output
    FILE *outfile = fopen(useroutput,"w");
    //int checker;
    char* p ;
    if (fp == NULL) {
            return -1;
    }
    
   p =read_file(count,p,fp);// pass to read 
  // printf(" this is the count that is being returned %d", count);      
  // printf("%c  %c //////// %s\n", p[0], p[1],p);


write_file(count, p,outfile);// pass to write

printf("%s\n",p);
free(p);
  
    return (EXIT_SUCCESS);
}//end of main
 
//read from a file
char* read_file(int count, char *p,FILE *fp){

    int i=0;
    char c;
   // FILE *fp = fopen("text.txt","r");
    //get count from file 
     while( fgetc(fp) != EOF){
        count++;
        //printf(fgetc(fp));
     }
    
    //printf("this is the size of the text file %d\n", count);

    p= (char *)malloc( ((sizeof(char)) * ( count+1)) );
   // p= (char *)(malloc( count+1 ));

    rewind(fp);
    
    
    
    while((c=fgetc(fp)) != EOF)//get each character
    {
        p[i]=c;
        i++;
    }
    p[i] = '\0';
    
      
   fclose(fp); 

   return p;
}
//write to a file
void write_file(int count, char *p, FILE *outfile){
    int i=0;
//printf("%c  %c //////// %s\n", p[0], p[1],p);
   
//fputs(p, outfile);
  

    for (i = 0; p[i] != '\0'; i++) {//this writes character by character to a file
        // printf("Character we are writing to the File = %c \n", clearFile[i]);
        // Let us use our fputc
        fputc(p[i], outfile);
    }
fclose(outfile);
}
