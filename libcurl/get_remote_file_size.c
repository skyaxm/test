#include<stdio.h>
#include<stdlib.h>
#include<curl/curl.h>

size_t get_size_struct(void* ptr, size_t size, size_t nmemb, void* data){
    return (size_t)(size * nmemb);
}

static curl_off_t sftpGetRemoteFileSize(const char *i_remoteFile)
{
    CURLcode result = CURLE_GOT_NOTHING;
    //curl_off_t remoteFileSizeByte = -1;
    double remoteFileSizeByte = 0.0;
    long filetime = -1;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    CURL *curlHandlePtr = curl_easy_init();
    if (curlHandlePtr == NULL) {
        return -1;
    }
    curl_easy_setopt(curlHandlePtr, CURLOPT_URL, i_remoteFile);
    curl_easy_setopt(curlHandlePtr, CURLOPT_NOBODY, 1L);
    curl_easy_setopt(curlHandlePtr, CURLOPT_FILETIME, 1L);
    curl_easy_setopt(curlHandlePtr, CURLOPT_HEADERFUNCTION, get_size_struct);
    curl_easy_setopt(curlHandlePtr, CURLOPT_HEADER, 0L);

    curl_easy_setopt(curlHandlePtr, CURLOPT_VERBOSE, 1L);
    //curl_easy_setopt(curlHandlePtr, CURLOPT_USERNAME, "shikuiyang");
    //curl_easy_setopt(curlHandlePtr, CURLOPT_PASSWORD, "waxm1314");

    //curl_easy_setopt(curlHandlePtr, CURLOPT_NOPROGRESS, 0);
    //curl_easy_setopt(curlHandlePtr, CURLOPT_FOLLOWLOCATION, 1L);

    result = curl_easy_perform(curlHandlePtr);
    if(CURLE_OK == result) {
        result = curl_easy_getinfo(curlHandlePtr, CURLINFO_FILETIME, &filetime);
        if ((result == CURLE_OK)&&(filetime >=0)) {
            time_t file_time =(time_t)filetime;
            printf("filetime %s: %s\n",filetime, ctime(&file_time));
        }else {
            fprintf(stderr, "curl told us %d\n", result);
        }
        result = curl_easy_getinfo(curlHandlePtr,
                               CURLINFO_CONTENT_LENGTH_DOWNLOAD,
                               //CURLINFO_SIZE_DOWNLOAD,
                               &remoteFileSizeByte);
        if(result)
            return -1;
    //printf("filesize: %" CURL_FORMAT_CURL_OFF_T "\n", remoteFileSizeByte);
	    printf("filesize: %.0f\n", remoteFileSizeByte);
    }
    curl_easy_cleanup(curlHandlePtr);

    return remoteFileSizeByte;
}

int main()
{
	const char* remoteFile = "sftp://shikuiyang:waxm1314@10.180.8.21:22/home/shikuiyang/test.bin";
	long len = sftpGetRemoteFileSize(remoteFile);
	printf("len: %ld\n", len);

	return 0;
}

