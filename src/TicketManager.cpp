#include "../include/TicketManager.h"
#include "../include/Ticket.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <algorithm> 

void TicketManager::addTicket(Ticket& ticket) {
  // Pobierz następny dostępny identyfikator
  int nextId = getLastTicketId() + 1;

  // Ustaw identyfikator nowego biletu
  ticket.setID(nextId);

  // Dodaj nowy bilet do wektora
  tickets.push_back(ticket);

  // Wyświetl komunikat o sukcesie
  std::cout << "Ticket dodany pomyślnie." << std::endl;
}

void TicketManager::readStringFromFile(std::ifstream& file, std::string& str) {
    size_t length;
    file.read(reinterpret_cast<char*>(&length), sizeof(length));
    str.resize(length);
    file.read(&str[0], length);
}

void TicketManager::loadTicketsFromFile(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary | std::ios::in);

    if (!file) {
        std::cerr << "Nie można otworzyć pliku do odczytu: " << filename << std::endl;
        return;
    }

    size_t size = 0;
    file.read(reinterpret_cast<char*>(&size), sizeof(size));

    tickets.clear();
    for (size_t i = 0; i < size; ++i) {
        Ticket ticket;

        int id;
        file.read(reinterpret_cast<char*>(&id), sizeof(id));
        ticket.setID(id);

        std::string title;
        readStringFromFile(file, title);
        ticket.setTitle(title);

        std::string description;
        readStringFromFile(file, description);
        ticket.setDescription(description);

        time_t creationDate;
        file.read(reinterpret_cast<char*>(&creationDate), sizeof(creationDate));
        ticket.setCreationDate(creationDate);

        std::string status;
        readStringFromFile(file, status);
        ticket.setStatus(status);

        int priority;
        file.read(reinterpret_cast<char*>(&priority), sizeof(priority));
        ticket.setPriority(priority);

        tickets.push_back(ticket);
    }

    file.close();
}

void writeStringToFile(std::ofstream& file, const std::string& str) {
    size_t length = str.size();
    file.write(reinterpret_cast<const char*>(&length), sizeof(length));
    file.write(str.c_str(), length);
}

void TicketManager::saveTicketsToFile(const std::string& filename) {
    std::ofstream file(filename, std::ios::binary | std::ios::out);

    if (!file) {
        std::cerr << "Nie można otworzyć pliku do zapisu: " << filename << std::endl;
        return;
    }

    size_t size = tickets.size();
    file.write(reinterpret_cast<char*>(&size), sizeof(size));

    for (const auto& ticket : tickets) {
        int id = ticket.getID();
        file.write(reinterpret_cast<const char*>(&id), sizeof(id));
        writeStringToFile(file, ticket.getTitle());
        writeStringToFile(file, ticket.getDescription());
        time_t creationDate = ticket.getCreationDate();
        file.write(reinterpret_cast<const char*>(&creationDate), sizeof(creationDate));
        writeStringToFile(file, ticket.getStatus());
        int priority = ticket.getPriority();
        file.write(reinterpret_cast<const char*>(&priority), sizeof(priority));
    }

    file.close();
}

void TicketManager::viewTickets() const {
    if (tickets.empty()) {
        std::cout << "Brak ticketów do wyświetlenia." << std::endl;
        return;
    }

    for (const auto& ticket : tickets) {
        std::cout << "Ticket ID: " << ticket.getID() << "\n"
                  << "Tytuł: " << ticket.getTitle() << "\n"
                  << "Opis: " << ticket.getDescription() << "\n"
                  << "Status: " << ticket.getStatus() << "\n"
                  << "Priorytet: " << ticket.getPriority() << "\n";

        // Formatowanie daty
        char buffer[80];
        std::time_t creationDate = ticket.getCreationDate();
        std::strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", std::localtime(&creationDate));
        std::cout << "Data utworzenia: " << buffer << "\n"
                  << "--------------------------------\n";
    }
}

int TicketManager::getLastTicketId() {
  // Jeśli wektor biletów jest pusty, zwracaj 0
  if (tickets.empty()) {
    return 0;
  }

  // W przeciwnym razie zwróć identyfikator ostatniego biletu
  return tickets.back().getID();
}

void TicketManager::updateTicket(int id, const std::string& newTitle, const std::string& newDescription, const std::string& newStatus, int newPriority) {
    for (auto& ticket : tickets) {
        if (ticket.getID() == id) {
            ticket.setTitle(newTitle);
            ticket.setDescription(newDescription);
            ticket.setStatus(newStatus);
            ticket.setPriority(newPriority);
            std::cout << "Ticket o ID " << id << " został zaktualizowany." << std::endl;
            return;
        }
    }
    std::cout << "Nie znaleziono ticketu o ID " << id << "." << std::endl;
}

void TicketManager::removeTicket(int id) {
    auto it = std::find_if(tickets.begin(), tickets.end(), [id](const Ticket& ticket) {
        return ticket.getID() == id;
    });

    if (it != tickets.end()) {
        tickets.erase(it);
        std::cout << "Ticket o ID " << id << " został usunięty." << std::endl;
    } else {
        std::cout << "Nie znaleziono ticketu o ID " << id << "." << std::endl;
    }
}

void TicketManager::searchTicketsByPriority(int priority) const {
    bool found = false;
    for (const auto& ticket : tickets) {
        if (ticket.getPriority() == priority) 
        {    
            std::cout << "Ticket ID: " << ticket.getID() << "\n"
            << "Tytuł: " << ticket.getTitle() << "\n"
            << "Opis: " << ticket.getDescription() << "\n"
            << "Status: " << ticket.getStatus() << "\n"
            << "Priorytet: " << ticket.getPriority() << "\n";

            // Formatowanie daty
            char buffer[80];
            std::time_t creationDate = ticket.getCreationDate();
            std::strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", std::localtime(&creationDate));
            std::cout << "Data utworzenia: " << buffer << "\n"
            << "--------------------------------\n";
            found = true;
        }
        
    }
    if (!found) {
        std::cout << "Nie znaleziono ticketów o podanym priorytecie." << std::endl;
    }
}

void TicketManager::searchTicketsByStatus(const std::string& status) const {
    bool found = false;
    for (const auto& ticket : tickets) {
        if (ticket.getStatus() == status) 
        {    
            std::cout << "Ticket ID: " << ticket.getID() << "\n"
            << "Tytuł: " << ticket.getTitle() << "\n"
            << "Opis: " << ticket.getDescription() << "\n"
            << "Status: " << ticket.getStatus() << "\n"
            << "Priorytet: " << ticket.getPriority() << "\n";

            // Formatowanie daty
            char buffer[80];
            std::time_t creationDate = ticket.getCreationDate();
            std::strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", std::localtime(&creationDate));
            std::cout << "Data utworzenia: " << buffer << "\n"
            << "--------------------------------\n";
            found = true;
        }
    }
    if (!found) {
        std::cout << "Nie znaleziono ticketów o podanym statusie." << std::endl;
    }
}


// Implementacja pozostałych metod
