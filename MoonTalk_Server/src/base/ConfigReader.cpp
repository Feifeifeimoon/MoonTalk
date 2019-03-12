#include "ConfigReader.h"

#include <string.h>

ConfigReader::ConfigReader(const char* filename)
{
    _loadFile(filename);
}

ConfigReader::~ConfigReader()
{    
}


char* ConfigReader::getConfigByName(const char* name)
{
    char* value = nullptr;
    auto it = m_config.find(name);
    if(it != m_config.end())
        value = (char*)it->second.c_str();
    return value;
}

void ConfigReader::_loadFile(const char* filename)
{
    m_filename.clear();
    m_filename.append(filename);
    FILE* fp = fopen(filename, "r");
    if(!fp)
    {
        perror("open failed");
        return ;
    }
    char buf[128];
    for(;;)
    {
        if(!fgets(buf, 128, fp))
            break;
        size_t len = strlen(buf);
        if(buf[len - 1] == '\n')
            buf[len - 1] = 0;
        char* ch = strchr(buf, '#');	// remove string start with #
		if (ch)
			*ch = 0;

		if (strlen(buf) == 0)
			continue;
        _parseLine(buf);
    }
    fclose(fp);
}

void ConfigReader::_parseLine(char* line)
{
    char* p = strchr(line, '=');
    if(p == NULL)
        return ;
    size_t len = strlen(p);
    char name[64];
    strncpy(name, line, strlen(line) - len);
    name[strlen(line) - len] = 0;
    char* key = _trimSpace(name);
    char* value = _trimSpace(p + 1);
    m_config[key] = value;
}

char* ConfigReader::_trimSpace(char* name)
{
    // remove starting space or tab
	char* start_pos = name;
	while ( (*start_pos == ' ') || (*start_pos == '\t') )
	{
		start_pos++;
	}

	if (strlen(start_pos) == 0)
		return NULL;

	// remove ending space or tab
	char* end_pos = name + strlen(name) - 1;
	while ( (*end_pos == ' ') || (*end_pos == '\t') )
	{
		*end_pos = 0;
		end_pos--;
	}

	int len = (int)(end_pos - start_pos) + 1;
	if (len <= 0)
		return NULL;

	return start_pos;
}