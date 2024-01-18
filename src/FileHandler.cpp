#include "../include/FileHandler.h"
#include "../include/Ticket.h"
#include "../include/TicketManager.h"
#include <fstream>
#include <iostream>
#include <string>
#include <ctime>

void FileHandler::createFile(const std::string& filename) {
    std::ofstream file(filename, std::ios::app); // Używamy flagi 'app' aby nie nadpisywać istniejącego pliku
    if (!file) {
        std::cerr << "Nie można utworzyć pliku: " << filename << std::endl;
    }
    file.close();
}

std::vector<std::string> FileHandler::readFile(const std::string& filename) {
    std::vector<std::string> data;
    std::string line;
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "Nie można otworzyć pliku: " << filename << std::endl;
        return data;
    }

    while (getline(file, line)) {
        data.push_back(line);
    }

    file.close();
    return data;
}

void FileHandler::writeFile(const std::string& filename, const std::vector<std::string>& data) {
    std::ofstream file(filename);

    if (!file) {
        std::cerr << "Nie można otworzyć pliku: " << filename << std::endl;
        return;
    }

    for (const auto& line : data) {
        file << line << std::endl;
    }

    file.close();
}

void FileHandler::exportTicketsToTxt(const std::string& sourceFilename, const std::string& targetFilename) {
    std::ifstream sourceFile(sourceFilename, std::ios::binary | std::ios::in);
    std::ofstream targetFile(targetFilename+".txt");

    TicketManager manager;

    if (!sourceFile) {
        std::cerr << "Nie można otworzyć pliku źródłowego: " << sourceFilename << std::endl;
        return;
    }

    if (!targetFile) {
        std::cerr << "Nie można utworzyć pliku docelowego: " << targetFilename << std::endl;
        return;
    }

    size_t size = 0;
    sourceFile.read(reinterpret_cast<char*>(&size), sizeof(size));

    for (size_t i = 0; i < size; ++i) {
        Ticket ticket;

        // Deserializacja ticketu
        int id;
        std::string title, description, status;
        time_t creationDate;
        int priority;

        sourceFile.read(reinterpret_cast<char*>(&id), sizeof(id));
        manager.readStringFromFile(sourceFile, title);
        manager.readStringFromFile(sourceFile, description);
        sourceFile.read(reinterpret_cast<char*>(&creationDate), sizeof(creationDate));
        manager.readStringFromFile(sourceFile, status);
        sourceFile.read(reinterpret_cast<char*>(&priority), sizeof(priority));

        ticket.setID(id);
        ticket.setTitle(title);
        ticket.setDescription(description);
        ticket.setCreationDate(creationDate);
        ticket.setStatus(status);
        ticket.setPriority(priority);

        // Formatowanie ticketu do postaci tekstowej
        char buffer[80];
        std::strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", std::localtime(&creationDate));
        targetFile << "Ticket ID: " << ticket.getID() << "\n"
                   << "Title: " << ticket.getTitle() << "\n"
                   << "Description: " << ticket.getDescription() << "\n"
                   << "Creation Date: " << buffer << "\n"
                   << "Status: " << ticket.getStatus() << "\n"
                   << "Priority: " << ticket.getPriority() << "\n\n";
    }

    sourceFile.close();
    targetFile.close();
    std::cout << "Tickety zostały pomyślnie wyeksportowane do " << targetFilename << std::endl;
}
