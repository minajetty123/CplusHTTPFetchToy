#include "remotejsontoxml.h"

using namespace std;
//using namespace tinyxml2;

inline static const string TARGET_URI = "https://jsonplaceholder.typicode.com/posts";
inline static const string FILE_SAVE_PATH = "dataSave.xml";

int main()
{
    RemoteJsonToXML converter;
    converter.StartRunning(TARGET_URI, FILE_SAVE_PATH);
    return 0;
}
