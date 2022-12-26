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
void print_lines(char * str);
void print_similar_words(char * str);


int main()
{
    return 0;
}
int getLine(char s[])
{
    char c;
    for (int i = 0; i < LINE; i++)
    {
        printf("Please select chars for a line:");
        scanf("%c",&c);
        s[i] = c;
        if (s[i] == '\n')
            return i;
    }
    return LINE;
}
int getWord(char w[])
{
    char c;
    for (int i = 0; i < WORD; i++)
    {
        printf("Please select chars for a word:");
        scanf("%c", &c);
        w[i] = c;
        if (w[i] == '\n' || w[i] == ' ' || w[i] == '\t')
            return i;
    }
    return WORD;
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

}
void print_lines(char * str)
{
    char buffer[LINE * WORD * MAX_LINES];
    // Need to scanf() a text
    // x=getLine()
    //for 0 - x-1
    //substring()
    //TODO
    getline(buffer, (size_t*) (LINE * WORD * MAX_LINES), stdin);
    for (int i = 0;buffer[i] != '\n',;i++)
    {

    }
}
void print_similar_words(char * str)
{
    //TODO
}