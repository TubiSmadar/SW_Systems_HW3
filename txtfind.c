//
// Created by Tuvia on 12/23/22.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define LINE 256 
#define WORD 30
#define MAX_LINES 250
int getLine(char line[LINE]);                              // get a line from stdio, with fgets
int getWord(char word[WORD]);                              // get a word a line from stdio, with fgets
int substring( char * str1, char * str2);           // check if word is a substing of another. 
int similar(char *s, char *t, int n);               // check if a word is similar to another
void print_lines(char * str);                       // print the lines that has a word similar to given word 
void print_similar_words(char * str);               // print only the similar word to the given


int buffer_c = ' '; // is used to get a char with fgets. is extern beacuse is used in more than one function 

int main(int argc, char *argv[])
{
    
    char* wordToFind = {0};              // the first word in the input file. it is the word that we will search

    getWord(wordToFind);   // get the first word
    
    while(1)
    {
        char decision;              // decision if to print like part a or like part b

    //    printf("Input the following:\n(a) For printing lines with similar words\n(b) for Printing similar words\n"); // ask user to pick a or b; 
       
        scanf("%c", &decision);             // get the dicision 
        
        if (decision == 'a')        // print the lines with similar words
        {
            print_lines(wordToFind);
            break;
        }
        else if (decision == 'b')      // print the similar words
        {
            print_similar_words(wordToFind);
            break;
        }
        else                    // invalid unput - try again 
            continue;

    }
    return 0;
}


/* get a line from the user using fgets with stdin
put the line into the given buffer */ 

int getLine(char line[LINE]){
    bzero(line,256);    // set buffer to zero 
    
    // for loop for getting the ling. stop if got line max length
    for (int i=0; i < LINE; i++)
    {
        buffer_c = fgetc(stdin);            // get char by char 

        if(buffer_c == '\0' ||buffer_c == EOF) 
            return 0;

        if(buffer_c == '\n')                // got to end of line
            break;

        if(buffer_c != '\r')            //  save the char into the buffer .
        {
            line[i] = buffer_c;
        }
    }

    return 1;
}

/* get a word from the user using fgets with stdin
put the word into the given buffer */ 

int getWord(char word[WORD] ){
    bzero(word,30);         // set the buffer
    for(int i=0; i<WORD; i++){  
        buffer_c = fgetc(stdin);        // get a char 
        if(buffer_c == '\0'||buffer_c == EOF)   
            return 0;
        if(buffer_c == ' ' || buffer_c == '\t' || buffer_c == '\n' || buffer_c == '\r') // got to end of word
            break;
        word[i] = buffer_c;  // save the char into the buffer 
    }
    return 1;

}

/*substring checks if str2 is substring of str1*/

int substring(char * str1, char * str2)
{
    int len1 = strlen(str1);       
    int len2 = strlen(str2);
    if (len1 < len2)            // str2 can not be a substring of word1. stop
    {
        return 0;
    }
    for (int i = 0; i <= len1 - len2; i++)
    {
        if (strncmp(&str1[i], str2, len2) == 0)
        {
            return 1;
        }
    }
    return 0;
}

/* similar checks if str1 and str2 are similar. 
that means that they are the same, or if you will take one letter out of str1 they will be the same. 
*/ 
int similar(char *s, char *t, int n)
{
    int len1 = (int)strlen(s);
    int len2 = (int)strlen(t);
    int i, j, count;

    if (abs(len1 - len2) > n) { 
        return 0;  // strings are not identical up to n omissions
    }

    i = j = count = 0;
    while (i < len1 && j < len2) {
        if (s[i] == t[j]) {
            i++;
            j++;
        } else {
            count++;
            if (count > n) {
                return 0;  // strings are not identical up to n omissions
            }
            if (len1 > len2) {
                i++;
            } else {
                j++;
            }
        }
    }

    return 1;  // strings are identical up to n omissions
}


/*print all the lines that contain in them the given "str" */ 

void print_lines(char* str)
{
    char line[LINE]; // buffer to store each line of text
    while (getLine(line) != 0) // read a line from stdin
    {
        if (substring(line, str) != 0) // check if the string is in the line
        {
            printf("%s\n", line); // print the line if it is
        }
    }
}

/*print all the similar word in the file that are similar to "str" */ 

void print_similar_words(char* str)
{
    char word[WORD]; // buffer to store each word of text
    while (getWord(word) != 0) // read a word from stdin
    {
        if (similar(word, str, 1) != 0) // check if the string is in the word
        {
            printf("%s\n", word); // print the line if it is similar
        }
    }
}



