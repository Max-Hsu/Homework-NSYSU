/*
 * convert.c : take a file in the form
 *  word1
 *  multiline definition of word1
 *  stretching over several lines,
 * followed by a blank line
 * word2....etc
 * convert into a file of fixed-length records
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "dict.h"
#define BIGLINE 512

int main(int argc, char **argv)
{
    FILE *in;
    FILE *out;        /* defaults */
    //char line[BIGLINE];
    //static Dictrec dr, blank;

    /* If args are supplied, argv[1] is for input, argv[2] for output */
    if (argc==3)
    {
        if ((in =fopen(argv[1],"r")) == NULL)
        {
            DIE(argv[1]);
        }
        if ((out =fopen(argv[2],"w+")) == NULL)
        {
            DIE(argv[2]);
        }
    }
    else
    {
        printf("Usage: convert [input file] [output file].\n");
        return -1;
    }

    /* Main reading loop : read word first, then definition into dr */

    /* Loop through the whole file. */
    char in_c[100000];

    while (fgets(in_c,sizeof(in_c),in))
    {
        int status=-1;
        for(int t=0; t<strlen(in_c); t++)
        {
            if(in_c[t]==' ')
            {
                status=1;
                break;
            }
            else
            {
                status=0;
            }
        }
        //fscanf(in,"%s",in_c);
        if(status==0)
        {
            char worda[WORD];
            for(int q=0; q<(strlen(in_c)-1); q++)
            {
                worda[q]=in_c[q];
                fprintf(out,"%c",in_c[q]);
                /*if(in_c[q]=='\0'){
                    printf("qqq");
                }
                if(in_c[q]=='\n'){
                    printf("wwww");
                }*/

            }
            for(int p=(strlen(in_c)-1); p<WORD; p++)
            {
                //printf("hellp");
                worda[p]='\0';
                fprintf(out,"%c",worda[p]);
            }
            //printf("%s  ",worda);
            //printf("%d   ",sizeof(worda));
            //printf("%d",strlen(worda));
        }
        if(status==1) //把讀到的第一行後的'/0'先去掉,再用strcat把後面的連接最後用480-strlen補剩餘空間
        {
            char definition[TEXT]= {'\0'};
            for(int e=0; e<((strlen(in_c))-1); e++)
            {
                definition[e]=in_c[e];
            }
            //definition[strlen(in_c)-1]=' ';
            int now_pos=(strlen(in_c)-1);
            char check_a_b[10000];
            fgets(check_a_b,10000,in);
            while(check_a_b[0]!='\n')
            {
                for(int a=now_pos; a<(strlen(check_a_b)+(now_pos-1)); a++)
                {
                    definition[a]=check_a_b[a-now_pos];
                }
                //definition[strlen(check_a_b)+now_pos-1]=' ';
                now_pos+=strlen(check_a_b)-1;
                fgets(check_a_b,10000,in);
            }
            //printf("%s",definition);
            //printf("%d \n",sizeof(definition));

            for(int o=0; o<TEXT-1; o++)
            {
                fprintf(out,"%c",definition[o]);
            }
            fprintf(out,"%c",'\n');
        }
        /* Create and fill in a new blank record.
         * First get a word and put it in the word field, then get the definition
         * and put it in the text field at the right offset.  Pad the unused chars
         * in both fields with nulls.
         */
        //printf("%d",strlen(in_c));
        //printf("\n");
        /* Read word and put in record.  Truncate at the end of the "word" field.
         *
         * Fill in code. */

        /* Read definition, line by line, and put in record.
         *
         * Fill in code. */

        /* Write record out to file.
         *
         * Fill in code. */
    }


    fclose(in);
    fclose(out);
    //system("pause");
    return 0;
}
