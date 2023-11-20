#include "FileHandler.h"
#include <fstream>
#include <iostream>

bool FileHandler::createFile(const std::string& filename) {
    std::ofstream file(filename.c_str());
    return file.is_open();
}

bool FileHandler::openFile(const std::string& filename) {
    std::ifstream file(filename.c_str());
    return file.is_open();
}

bool FileHandler::saveToFile(const std::string& filename, const std::string& data) {
    std::ofstream file(filename.c_str());
    if (file.is_open()) {
        file << data;
        file.close();
        return true;
    }
    return false;
}

bool FileHandler::exportToFile(const std::string& filename, const std::string& data) {
    // Implementacja eksportu danych do innego formatu
    // Na przykład, zapis danych w formie JSON lub XML
    std::ofstream file(filename.c_str());
    if (file.is_open()) {
        file << data;
        file.close();
        return true;
    }
    return false;
}

