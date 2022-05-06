#include "remotejsontoxml.h"

using namespace std;
using namespace tinyxml2;

RemoteJsonToXML::RemoteJsonToXML(){}

void RemoteJsonToXML::StartRunning(const string &url, const string &savePath)
{
    currentThread.post([=]() {
        StartFetchAndConvert(url, savePath);
    });
    currentThread.join();
}

void RemoteJsonToXML::StopRuning()
{
    currentThread.postQuit();
}

void RemoteJsonToXML::StartFetchAndConvert(const string &target_url, const string &target_path)
{
    XMLDocument xmlDoc;
    XMLNode * pRoot = xmlDoc.NewElement("Root");
    xmlDoc.InsertFirstChild(pRoot);

    CURL *curl;
    CURLcode res;
    std::string readBuffer;

    curl = curl_easy_init();
    if(curl) {
      curl_easy_setopt(curl, CURLOPT_URL,target_url.c_str());
      curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
      curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
      res = curl_easy_perform(curl);
      curl_easy_cleanup(curl);
      string err;
      auto json = json11::Json::parse(readBuffer, err).array_items();
      for(const auto& value: json) {
          //std::cout << value.object_items().at("body").dump() << "\n";
          XMLElement * pElement = xmlDoc.NewElement("");
          pElement->SetAttribute("id", value.object_items().at("id").dump().c_str());
          pElement->SetAttribute("body", value.object_items().at("body").dump().c_str());
          pElement->SetAttribute("userId", value.object_items().at("userId").dump().c_str());
          pElement->SetAttribute("title", value.object_items().at("title").dump().c_str());
          pRoot->InsertEndChild(pElement);
      }
      XMLError eResult = xmlDoc.SaveFile(target_path.c_str());
      if (eResult == XML_SUCCESS){
          printf("save XML file successfully");
      }else{
          printf("save XML file failed: %i\n", eResult);
      }
    }
}

size_t RemoteJsonToXML::WriteCallback(void *contents, size_t size, size_t nmemb, void *userp){
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}
