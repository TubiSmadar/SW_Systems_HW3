//
// Created by Tuvia on 12/23/22.
//
#include <stdio.h>
#include <string.h>
#define LINE 256
#define WORD 30
#define MAX_LINES 250
int getLine(char s[]);
int getWord(char w[]);
int substring( char * str1, char * str2);
void removeChar(char *s, int index);
int similar(char *s, char *t, int n);
void print_lines(char * str);
void print_similar_words(char * str);


int main()
{
    return 0;
}
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
        if(buffer_c == ' ' || buffer_c == '\t' || buffer_c == '\n')
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
void removeChar(char *s, int index) {
    // shift the characters after the index to the left by one
    int i;
    for (i = index; i < strlen(s); i++) {
        s[i] = s[i+1];
    }
}

int similar(char *s, char *t, int n) {
    // make copies of the strings
    char s_copy[strlen(s)];
    strcpy(s_copy, s);
    char t_copy[strlen(t)];
    strcpy(t_copy, t);

    // check if the strings are already equal
    if (strcmp(s_copy, t_copy) == 0) {
        return 1; // strings are already equal
    }

    // try removing up to n characters from s_copy and comparing it to t_copy
    int num_removed = 0;
    int i, j;
    while (num_removed <= n) {
        // try removing a single character at each index
        for (i = 0; i < strlen(s_copy); i++) {
            removeChar(s_copy, i);
            if (strcmp(s_copy, t_copy) == 0) {
                return 1; // strings are similar
            }
            // restore the removed character
            s_copy[i] = s[i];
        }
        // try removing multiple characters at the same time
        for (i = 0; i < strlen(s_copy); i++) {
            for (j = i + 1; j < strlen(s_copy); j++) {
                removeChar(s_copy, i);
                removeChar(s_copy, j - 1);
                if (strcmp(s_copy, t_copy) == 0) {
                    return 1; // strings are similar
                }
                // restore the removed characters
                s_copy[j - 1] = s[j - 1];
                s_copy[i] = s[i];
            }
        }
        num_removed++;
    }
    return 0;
}
void print_lines(char *str)
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

void print_similar_words(char * str)
{
    //TODO

}
