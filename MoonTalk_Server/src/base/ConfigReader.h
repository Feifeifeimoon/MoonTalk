#ifndef _MOONTALK_BASE_CONFIGREADER_H_
#define _MOONTALK_BASE_CONFIGREADER_H_

#include <map>
#include <string>
using std::string;

class ConfigReader
{
public:
    ConfigReader(const char* filename);
    ~ConfigReader();
    //first code in 2019 
    char* getConfigByName(const char* name);
private:
    void _loadFile(const char* filename);
    void _parseLine(char* line);
    char* _trimSpace(char* name);
private:
    std::map<string, string> m_config;
    string                   m_filename;
};

#endif