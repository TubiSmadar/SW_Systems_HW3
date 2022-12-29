//
// Created by Tuvia on 12/23/22.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LINE 256
#define WORD 30
#define MAX_LINES 250
int getLine(char s[]);
int getWord(char w[]);
int substring( char * str1, char * str2);
int similar(char *s, char *t, int n);
void print_lines(char * str);
void print_similar_words(char * str);


int buffer_c = ' ';

int getLine(char line[LINE]){
    bzero(line,256);
    for (int i=0; i < LINE; i++)
    {
        buffer_c = fgetc(stdin);

        if(buffer_c == '\0' ||buffer_c == EOF)
            return 0;

        if(buffer_c == '\n')
            break;

        if(buffer_c != '\r')
        {
            line[i] = buffer_c;
        }
    }

    return 1;
}
int getWord(char word[WORD] ){
    bzero(word,30);
    for(int i=0; i<WORD; i++){
        buffer_c = fgetc(stdin);
        if(buffer_c == '\0'||buffer_c == EOF)
            return 0;
        if(buffer_c == ' ' || buffer_c == '\t' || buffer_c == '\n' || buffer_c == '\r')
            break;
        word[i] = buffer_c;
    }
    return 1;

}
int substring(char * str1, char * str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if (len1 < len2)
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

void print_similar_words(char* str)
{
    char word[WORD]; // buffer to store each line of text
    while (getWord(word) != 0) // read a line from stdin
    {
        if (similar(word, str, 1) != 0) // check if the string is in the line
        {
            printf("%s\n", word); // print the line if it is
        }
    }
}


int main(int argc, char *argv[])
{
    
    buffer_c = fgetc(stdin);
    char decision;
    while(1)
    {

        printf("(a) Print lines\n(b) Print similar words\n");
        scanf("%c", &decision);
        if (decision == 'a')
        {
            print_lines("cat");
            break;
        }
        else if (decision == 'b')
        {
            print_similar_words("cat");
            break;
        }
        else
            continue;

    }
    return 0;
}
