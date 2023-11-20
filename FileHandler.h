#pragma once
#include <string>

class FileHandler {
public:
    bool createFile(const std::string& filename);
    bool openFile(const std::string& filename);
    bool saveToFile(const std::string& filename, const std::string& data);
    bool exportToFile(const std::string& filename, const std::string& data);
};
