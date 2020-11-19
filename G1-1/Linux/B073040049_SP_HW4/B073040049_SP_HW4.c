#include <errno.h>
#include <poll.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/inotify.h>
#include <unistd.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>
#define add_space(x) strcat(x," ");
#define alloc(x) (char *)malloc(sizeof(char)*strlen(x));
#define dea 200
#define del 1000

#define FROM    "hsuevaair3317forsmtp@gmail.com"
#define TO      "hsuevaair3317forsmtp@gmail.com"
#define CC      "hsuevaair3317forsmtp@gmail.com"
int send_s(void);


char current_path[dea];
char current_file[dea];
char current_type[dea];
char current_status[del];
char *payload_text[] =
{
    "Date: Mon, 29 Nov 2017 21:54:29 +1100\r\n ",
    "To: " TO "\r\n",
    "From: " FROM "(Max-Hsu)\r\n",
    "Cc: " CC "\r\n",
    "Message-ID: <dcd7cb36-11db-487a-9f3a-e652a9458efd@"
    "rfcpedant.example.org>\r\n",
    "Subject: Did I Make yvvysssy it?\r\n",
    "\r\n", /* empty line to divide headers from body, see RFC5322 */
    "I am Max-Hsu\r\n",
    "this is a test copy\r\n",
    "Please go to check!!\r\n",
    NULL
};
void clean(char *sx,int u)
{
    for(int i=0; i<u; i++)
    {
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


static void handle_events(int fd, int *wd, int argc, char* argv[])
{
    char buf[4096]
    __attribute__ ((aligned(__alignof__(struct inotify_event))));
    const struct inotify_event *event;
    int i;
    ssize_t len;
    char *ptr;
    for (;;)
    {

        len = read(fd, buf, sizeof buf);
        if (len == -1 && errno != EAGAIN)
        {
            perror("read");
            exit(EXIT_FAILURE);
        }


        if (len <= 0)
            break;


        for (ptr = buf; ptr < buf + len;
                ptr += sizeof(struct inotify_event) + event->len)
        {
            clean(current_file,dea);
            clean(current_path,dea);
            clean(current_status,del);
            clean(current_type,dea);

            event = (const struct inotify_event *) ptr;


            //printf("Hello  ");

            if (event->mask & IN_ISDIR)
            {
                printf("directory:");
                strcat(current_type,"directory");
            }
            else
            {
                printf("file:");
                strcat(current_type,"file");
            }

            if (event->len)
            {
                printf("%s  at  ", event->name);
                strcat(current_file,event->name);
            }
            for (i = 1; i < argc; ++i)
            {
                if (wd[i] == event->wd)
                {
                    printf("%s/", argv[i]);
                    strcat(current_path,argv[i]);
                    break;
                }
            }
            if(event->mask &IN_ACCESS)
            {
                printf("   was   IN_ACCESS \n");
                strcat(current_status," IN_ACCESS ");
            }
            if(event->mask &IN_ATTRIB)
            {
                printf("   was   IN_ATTRIB \n");
                strcat(current_status," IN_ATTRIB ");
            }
            if (event->mask & IN_CLOSE_WRITE)
            {
                printf("   was   IN_CLOSE_WRITE \n");
                strcat(current_status," IN_CLOSE_WRITE ");
            }
            if (event->mask & IN_CLOSE_NOWRITE)
            {
                printf("   was   IN_CLOSE_NOWRITE \n");
                strcat(current_status," IN_CLOSE_NOWRITE ");
            }
            if (event->mask & IN_CREATE)
            {
                printf("   was   IN_CREATE \n");
                strcat(current_status," IN_CREATE ");
            }
            if (event->mask & IN_DELETE)
            {
                printf("   was   IN_DELETE \n");
                strcat(current_status," IN_DELETE ");
            }
            if (event->mask & IN_DELETE_SELF)
            {
                printf("   was   IN_DELETE_SELF \n");
                strcat(current_status," IN_DELETE_SELF ");
            }
            if (event->mask & IN_MODIFY)
            {
                printf("   was   IN_MODIFY \n");
                strcat(current_status," IN_MODIFY ");
            }
            if (event->mask & IN_MOVE_SELF)
            {
                printf("   was   IN_MOVE_SELF \n");
                strcat(current_status," IN_MOVE_SELF ");
            }
            if (event->mask & IN_MOVED_FROM)
            {
                printf("   was   IN_MOVE_FROM \n");
                strcat(current_status," IN_MOVE_FROM ");
            }
            if (event->mask & IN_MOVED_TO)
            {
                printf("   was   IN_MOVE_TO \n");
                strcat(current_status," IN_MOVE_TO ");
            }
            if (event->mask & IN_OPEN)
            {
                printf("   was   IN_OPEN \n");
                strcat(current_status," IN_OPEN ");
            }
            printf("%s\t%s\t%s\t%s\t\n",current_file,current_path,current_type,current_status);
            send_s();
        }
        printf("\n\n");
    }
}

int send_s(void)
{
    struct tm *a;
    time_t x;
    char s[10];
    char sx[dea];
    clean(sx,dea);
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
    clean(sx,dea);

    //line2

    strcpy(sx,"To: ");
    strcat(sx,TO);
    strcat(sx,"\r\n");
    //printf("%s",sx);

    payload_text[1]=alloc(sx);
    memcpy(payload_text[1],sx,strlen(sx));
    clean(sx,dea);
    //printf("%s",payload_text[1]);
    //line3
    strcpy(sx,"From: ");
    strcat(sx,FROM);
    strcat(sx,"(Max-Hsu)\r\n");

    payload_text[2]=alloc(sx);
    memcpy(payload_text[2],sx,strlen(sx));
    clean(sx,dea);
    //line4
    strcpy(sx,"Cc: ");
    strcat(sx,CC);
    strcat(sx,"\r\n");

    payload_text[3]=alloc(sx);
    memcpy(payload_text[3],sx,strlen(sx));
    clean(sx,dea);

    //line5
    strcpy(sx,"Message-ID: abcdefgh\r\n");

    payload_text[4]=alloc(sx);
    memcpy(payload_text[4],sx,strlen(sx));
    clean(sx,dea);

    //line6
    strcpy(sx,"Subject: [warining]Some movement in ");
    strcat(sx,current_path);
    strcat(sx,"\r\n");

    payload_text[5]=alloc(sx);
    memcpy(payload_text[5],sx,strlen(sx));
    clean(sx,dea);
    //line7
    //should be /r/n

    //line8
    strcpy(sx,"Path: ");
    strcat(sx,current_path);
    strcat(sx,"  ");
    strcat(sx,current_type);
    strcat(sx,":  ");
    strcat(sx,current_file);
    strcat(sx,"  \r\n");

    payload_text[7]=alloc(sx);
    memcpy(payload_text[7],sx,strlen(sx));
    clean(sx,dea);

    //line9
    strcpy(sx,"Active: ");
    strcat(sx,current_status);
    strcat(sx,"  \r\n");

    payload_text[8]=alloc(sx);
    memcpy(payload_text[8],sx,strlen(sx));
    clean(sx, dea);
    //line10 left \r\n
    //line11 left NULL


    for(int i=0; i<9; i++)
    {
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


int main(int argc, char* argv[])
{
    clean(current_file,dea);
    clean(current_path,dea);
    clean(current_status,del);
    clean(current_type,dea);
    char buf;
    int fd, i, poll_num;
    int *wd;
    nfds_t nfds;
    struct pollfd fds[2];

    if (argc < 2)
    {
        printf("Usage: %s PATH [PATH ...]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    printf("Press ENTER key to terminate.\n");

    /* Create the file descriptor for accessing the inotify API */

    fd = inotify_init1(IN_NONBLOCK);
    if (fd == -1)
    {
        perror("inotify_init1");
        exit(EXIT_FAILURE);
    }

    /* Allocate memory for watch descriptors */

    wd = calloc(argc, sizeof(int));
    if (wd == NULL)
    {
        perror("calloc");
        exit(EXIT_FAILURE);
    }

    /* Mark directories for events
       - file was opened
       - file was closed */

    for (i = 1; i < argc; i++)
    {
        wd[i] = inotify_add_watch(fd, argv[i], IN_ACCESS|IN_ATTRIB|IN_CLOSE_WRITE|IN_CLOSE_NOWRITE|IN_CREATE|IN_DELETE|IN_DELETE_SELF|IN_MOVED_FROM|IN_MOVED_TO|IN_OPEN);
        if (wd[i] == -1)
        {
            fprintf(stderr, "Cannot watch '%s'\n", argv[i]);
            perror("inotify_add_watch");
            exit(EXIT_FAILURE);
        }
    }

    /* Prepare for polling */

    nfds = 2;

    /* Console input */

    fds[0].fd = STDIN_FILENO;
    fds[0].events = POLLIN;

    /* Inotify input */

    fds[1].fd = fd;
    fds[1].events = POLLIN;

    /* Wait for events and/or terminal input */

    printf("Listening for events.\n");
    while (1)
    {
        poll_num = poll(fds, nfds, -1);
        if (poll_num == -1)
        {
            if (errno == EINTR)
                continue;
            perror("poll");
            exit(EXIT_FAILURE);
        }

        if (poll_num > 0)
        {

            if (fds[0].revents & POLLIN)
            {

                /* Console input is available. Empty stdin and quit */

                while (read(STDIN_FILENO, &buf, 1) > 0 && buf != '\n')
                    continue;
                break;
            }

            if (fds[1].revents & POLLIN)
            {

                /* Inotify events are available */

                handle_events(fd, wd, argc, argv);
            }
        }
    }

    printf("Listening for events stopped.\n");

    /* Close inotify file descriptor */

    close(fd);

    free(wd);
    exit(EXIT_SUCCESS);
}
