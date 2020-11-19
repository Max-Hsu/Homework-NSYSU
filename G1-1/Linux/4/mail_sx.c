#include <stdio.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>
#include <stdlib.h>
#define add_space(x) strcat(x," ");
#define alloc(x) (char *)malloc(sizeof(char)*strlen(x));

#define FROM    "hsuevaair3317forsmtp@gmail.com"
#define TO      "hsuevaair3317forsmtp@gmail.com"
#define CC      "hsuevaair3317forsmtp@gmail.com"

char *payload_text[] =
{
    "Date: Mon, 29 Nov 2017 21:54:29 +1100\r\n",
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
    struct tm *a;
    time_t x;
    char s[10];
    char sx[100];
    clean(sx);
    time(&x);
    a=localtime(&x);
    //line1
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

    payload_text[0]=alloc(sx);
    memcpy(payload_text[0],sx,strlen(sx));
    clean(sx);

    //line2

    strcpy(sx,"To: ");
    strcat(sx,TO);
    strcat(sx,"\r\n");
    //printf("%s",sx);

    payload_text[1]=alloc(sx);
    memcpy(payload_text[1],sx,strlen(sx));
    clean(sx);
    //printf("%s",payload_text[1]);
    //line3
    strcpy(sx,"From: ");
    strcat(sx,FROM);
    strcat(sx,"(Max-Hsu)\r\n");

    payload_text[2]=alloc(sx);
    memcpy(payload_text[2],sx,strlen(sx));
    clean(sx);
    //line4
    strcpy(sx,"Cc: ");
    strcat(sx,CC);
    strcat(sx,"\r\n");

    payload_text[3]=alloc(sx);
    memcpy(payload_text[3],sx,strlen(sx));
    clean(sx);

    //line5
    strcpy(sx,"Message-ID: abcdefgh\r\n");

    payload_text[4]=alloc(sx);
    memcpy(payload_text[4],sx,strlen(sx));
    clean(sx);

    //line6
    strcpy(sx,"Subject: ");
    char ap[100];
    scanf("%s",ap);
    strcat(sx,ap);
    strcat(sx,"\r\n");

    payload_text[5]=alloc(sx);
    memcpy(payload_text[5],sx,strlen(sx));
    clean(sx);
    //line7
    //should be /r/n

    //line8
    strcpy(sx,"hello\r\n");

    payload_text[7]=alloc(sx);
    memcpy(payload_text[7],sx,strlen(sx));
    clean(sx);

    //line9
    strcpy(sx,"end.\r\n");

    payload_text[8]=alloc(sx);
    memcpy(payload_text[8],sx,strlen(sx));
    clean(sx);
    //line10 left NULL


    for(int i=0;i<9;i++){
    printf("%s",payload_text[i]);
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

        recipients = curl_slist_append(recipients, TO);
        recipients = curl_slist_append(recipients, CC);
        curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);

        curl_easy_setopt(curl, CURLOPT_READFUNCTION, payload_source);
        curl_easy_setopt(curl, CURLOPT_READDATA, &upload_ctx);
        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);

        res = curl_easy_perform(curl);

        /* Check for errors */
        if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));

        curl_slist_free_all(recipients);

        curl_easy_cleanup(curl);
    }

    return (int)res;
}
