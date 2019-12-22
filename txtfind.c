//
// Created by rotem levy on 18/12/2019.
//
#include <string.h>
#include <stdio.h>
#include "txtfind.h"
#define LINE 256
#define WORD 30

int getLine(char s[])
{
    char ch;
    int i =0;
    scanf("%c", &ch);
    while((ch !='\n') && (i != LINE) && (ch != EOF))
    {
        s[i] = ch;
        i++;
        scanf("%c", &ch);

    }
    s[i] = '\0';
    return i;
}

int getWord(char w[])
{
    char ch;
    int i = 0;
    scanf("%c", &ch);
    while((ch !='\n') && (ch != '\t') && (ch != ' ') && (i != WORD) && (i != EOF))
    {
        w[i] = ch;
        i++;
        scanf("%c", &ch);
    }
    w[i] = '\0';
    return i;
}

int substring(char * str1,char * str2)
{
    if(strstr(str1, str2) != NULL)
    {
        return 1;
    }
    return 0;
}

int similar(char *s,char *t,int n)
{
    while(*t!='\0')
    {
        while((*s!=*t) && (*s!='\0'))
        {
            n--;
            s++;
        }
        if(*s!=*t)
        {
            return 0;
        }
        s++;
        t++;
    }
    while(*s!='\0')
    {
        n--;
        s++;
    }
    if(n==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void print_lines(char *str)
{
    char line[LINE] = {'\0'};
    int num_c = getLine(line);
    int j = 0;

    while(num_c)
    {
            num_c = getLine(line);
            line[num_c] = '\0';
            char *p_line = line;
            if(substring(p_line,str) == 1)
            {
                printf("%s\n",line);
                while(line[j])
                {
                    printf("%c", line[j]);
                    j++;
                }
            }
    }
}

void print_similar_words(char *str)
{
    char line[LINE] = {'\0'};
    int num_c = getWord(line);
    int j = 0;
    while(num_c)
    {
        num_c = getWord(line);
        char *p_line = line;
        if(similar(p_line,str,1) == 1 || similar(p_line,str,0) == 1)
        {
            printf("%s\n",line);
        }
    }

}
int main()
{
    char sWord[WORD];
    char *search=sWord;
    getWord(sWord);
    char sAction[WORD];
    getWord(sAction);
    if(sAction[0]=='a')
    {
        print_lines(search);
    }
    else
    {
        print_similar_words(search);
    }
    return 0;
}
