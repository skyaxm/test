#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <sys/stat.h>
#include <signal.h>

#include <curl/curl.h>
#include <curl/easy.h>

#include <string>
#include <fstream>
#include <iostream>

/*
g++ curl_test.cpp -I /usr/local/curl/include/ -I /usr/local/libssh2/include/ -I /usr/local/openssl/include/  -L /usr/local/curl/lib/ -L /usr/local/libssh2/lib/ -L /usr/local/openssl/lib/ -lrt -lcurl -lssh2 -lssl -lcrypto -ldl -lz
*/

using namespace std;

void gloale_init()
{
    
    curl_global_init(CURL_GLOBAL_DEFAULT);
    return;
}

size_t read_callback(void *ptr, size_t size, size_t nmemb, void *stream) //回调函数
{
    curl_off_t nread;
    size_t retcode = fread(ptr, size, nmemb, (FILE*)(stream));
    nread = (curl_off_t)retcode;
    return retcode;
}


size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
    int written = fwrite(ptr, size, nmemb, (FILE *)stream);
    return written;
}

size_t upload(const char * user,const char * passwd,const char * url, const char * path)
{    
    CURL *curl;
    CURLcode res;
    string s1(user);
    string s2(passwd);
    string s3 = s1 + ":" + s2;
    cout<<s3<<endl;    
    system("ls write_file");
    FILE* pSendFile = fopen(path,"r");
    if(pSendFile == NULL)
    {
        printf("open failed\n");
        return 1;
    }
    printf("------------\n");
    fseek(pSendFile, 0L, SEEK_END);
    printf("------------\n");
    size_t iFileSize = ftell(pSendFile);
    printf("------------\n");
    fseek(pSendFile, 0L, SEEK_SET);
    printf("begin easy_init\n"); 
 
    curl = curl_easy_init();
    printf("curl_easy_init success\n");
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL,url);
    curl_easy_setopt(curl, CURLOPT_USERPWD,s3.c_str());  
    curl_easy_setopt(curl, CURLOPT_READFUNCTION, read_callback);
    curl_easy_setopt(curl, CURLOPT_READDATA, pSendFile);
    curl_easy_setopt(curl, CURLOPT_FTP_CREATE_MISSING_DIRS, 0);
    curl_easy_setopt(curl, CURLOPT_UPLOAD, 1);
    curl_easy_setopt(curl, CURLOPT_INFILESIZE, iFileSize);
 
    printf("curl_easy_setopt success");
    res = curl_easy_perform(curl);
 
    curl_easy_cleanup(curl);
 
    if(CURLE_OK != res) 
    {
 
        fprintf(stdout, "curl told us %d\n", res);
    }
  }
    fclose(pSendFile);
    curl_global_cleanup();
    return 0;
}


int download(const char * user,const char * passw,const char * url,const char * filePath)
{
    CURL *curl;
    CURLcode curl_code;
    string s1(user);
    string s2(passw);
    string s3 = s1 + ":" + s2;
    cout<<s3<<endl;    
    curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, url);
//    curl_easy_setopt(curl, CURLOPT_USERPWD, s3.c_str());
    curl_easy_setopt(curl, CURLOPT_USERNAME, user);
    curl_easy_setopt(curl, CURLOPT_PASSWORD, passw);
    
    FILE *fp = fopen(filePath, "wb+");
    if (NULL == fp)
    {
        curl_easy_cleanup(curl);
        printf("fopen failed\n");
        return -1;
    }
    
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
    curl_code = curl_easy_perform(curl);
    printf("curl_code = %d\n",curl_code);
    if (CURLE_OK != curl_code)
    {
        printf("perform failed\n");
        curl_easy_cleanup(curl);
        fclose(fp);
        remove(filePath);        
        return -1;
    }
    curl_easy_cleanup(curl);
    
    fclose(fp);

    return 0;
}
int main()
{
    gloale_init();
    char * serverip = "192.168.248.135";
    char * port = "22";
    char * serverpath = "/root/CentOS-Base.repo";
    char *user = "root";
    char * passwd = "123456";
    char * savepath = "write_file";
    char url[125] = {0};
    
    sprintf(url,"sftp://%s:%s/%s",serverip,port,serverpath);
    printf("url: %s\n", url);
    //download(user,passwd,url,savepath);
    upload(user,passwd,url,savepath);

    return 0;
}

