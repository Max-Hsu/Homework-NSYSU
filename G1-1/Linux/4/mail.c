#include <stdio.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>
#include <stdlib.h>
#define add_space(x) strcat(x," ");
#define alloc(x) (char *)malloc(sizeof(char)*x);

#define FROM    "hsuevaair3317forsmtp@gmail.com"
#define TO      "hsuevaair3317forsmtp@gmail.com"
#define CC      "hsuevaair3317forsmtp@gmail.com"

char *payload_text[] =
{
    "Date: Mon, 30 Nov 2007 21:54:49 +1100\r\n\0",
    "To: " TO "\r\n",
    "From: " FROM "(Max-Hsu)\r\n",
    "Cc: " CC "\r\n",
    "Message-ID: <dcd7cb36-11db-487a-9f3a-e652a9458efd@"
    "rfcpedant.example.org>\r\n",
    "Subject: Did I Make yvvysssy it?\r\n",
    "\r\n", /* empty line to divide headers from body, see RFC5322 */
    "I am Max-Hsu\r\n",
    "this is a test copy\r\n",
    NULL
};
void clean(char *sx){
    for(int i=0;i<99;i++){
        sx[i]='\0';
    }
}
struct upload_status
{
    int lines_read;
};

static size_t payload_source(void *ptr, size_t size, size_t nmemb, void *userp)
{
    struct upload_status *upload_ctx = (struct upload_status *)userp;
    const char *data;

    if((size == 0) || (nmemb == 0) || ((size*nmemb) < 1))
    {
        return 0;
    }

    data = payload_text[upload_ctx->lines_read];

    if(data)
    {
        size_t len = strlen(data);
        memcpy(ptr, data, len);
        upload_ctx->lines_read++;

        return len;
    }

    return 0;
}

int main(void)
{
    /*
    char **tranchar;
    struct tm *a;
    time_t x;
    char s[10];
    char sx[100];
    clean(sx);
    time(&x);
    a=localtime(&x);
    tranchar=(char **)malloc(sizeof(char)*10);
    tranchar[0]=alloc(1);
    strcpy(sx,"Date: ");
    strftime(s, 10, "%a", a);
    strcat(sx,s);
    strcat(sx,", ");
    strftime(s, 10, "%d", a);
    strcat(sx,s);
    add_space(sx);
    strftime(s, 10, "%b", a);
    strcat(sx,s);
    add_space(sx);
    strftime(s, 10, "%G", a);
    strcat(sx,s);
    add_space(sx);
    strftime(s, 10, "%T", a);
    strcat(sx,s);
    add_space(sx);
    strftime(s, 10, "%z", a);
    strcat(sx,s);
    add_space(sx);
    strcat(sx,"\r\n");
    printf("%s",sx);

    payload_text[0]=sx;
    tranchar[0]=sx;
    printf("%s",payload_text[0]);
    clean(sx);

    tranchar[1]=alloc(1);
    strcpy(sx,"To: ");
    strcat(sx,TO);
    strcat(sx,"\r\n");
    printf("%s",sx);

    payload_text[1]=sx;
    tranchar[1]=sx;
    printf("%s",payload_text[1]);
    printf("%s",tranchar[1]);
    clean(sx);
    /*
    tranchar[2]=alloc(1);
    strcpy(tranchar[2],"From: ");
    strcat(tranchar[2],FROM);
    strcat(tranchar[2],"\r\n");

    tranchar[3]=alloc(1);
    strcpy(tranchar[3],"Cc: ");
    strcat(tranchar[3],CC);
    strcat(tranchar[3],"\r\n");

    tranchar[4]=alloc(1);
    strcpy(tranchar[4],"Message-ID: abcdefgh\r\n");
    tranchar[5]=alloc(1);
    strcpy(tranchar[5],"Subject: axby");
    //strcat(tranchar[5],tranchar[0]);
    tranchar[6]=alloc(1);
    strcpy(tranchar[6],"hello\r\n");
    tranchar[7]=alloc(1);
    strcpy(tranchar[7],"\r\n");
    tranchar[8]=alloc(1);
    strcpy(tranchar[8],"\r\n");
    tranchar[9]=alloc(1);
    tranchar[9]=NULL;
    //printf("%s",tranchar[5]);
    for(int i=0; i<9; i++)
    {
        printf("%s\n",tranchar[i]);
    }
    */
    for(int i=0;i<9;i++){
    printf("%ld   %ld    %s ",strlen(payload_text[i]),sizeof(payload_text[i]),payload_text[i]);
    }

    CURL *curl;
    CURLcode res = CURLE_OK;
    struct curl_slist *recipients = NULL;
    struct upload_status upload_ctx;

    upload_ctx.lines_read = 0;

    curl = curl_easy_init();
    if(curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, "smtps://smtp.gmail.com:465");
        curl_easy_setopt(curl, CURLOPT_USE_SSL, CURLUSESSL_ALL);
        curl_easy_setopt(curl, CURLOPT_USERNAME, "hsuevaair3317forsmtp@gmail.com");
        curl_easy_setopt(curl, CURLOPT_PASSWORD, "hsu893972");
        curl_easy_setopt(curl, CURLOPT_MAIL_FROM, FROM);
        printf("okaa");
        recipients = curl_slist_append(recipients, TO);
        recipients = curl_slist_append(recipients, CC);
        curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);
        printf("okv");
        curl_easy_setopt(curl, CURLOPT_READFUNCTION, payload_source);
        curl_easy_setopt(curl, CURLOPT_READDATA, &upload_ctx);
        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
        printf("ok1");
        res = curl_easy_perform(curl);
        printf("ok2");
        /* Check for errors */
        if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        printf("ok3");
        curl_slist_free_all(recipients);
        printf("OK");
        curl_easy_cleanup(curl);
    }
    /*for(int i=0;i<10;i++){
        free(tranchar[i]);
    }*/
    //free(tranchar);
    return (int)res;
}
