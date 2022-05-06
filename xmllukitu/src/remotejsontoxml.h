#ifndef REMOTEJSONTOXML_H
#define REMOTEJSONTOXML_H

#include <curl/curl.h>
#include <string>
#include "json11.hpp"
#include "worker_thread.h"
#include "tinyxml2.h"

class RemoteJsonToXML
{
public:
    RemoteJsonToXML();
    void StartRunning(const string &url, const string &savePath);
    void StopRuning();
private:
    static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);
    void StartFetchAndConvert(const string &target_url, const string &target_path);
private:
    worker_thread currentThread;
};

#endif // REMOTEJSONTOXML_H
