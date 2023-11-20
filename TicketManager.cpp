#include "TicketManager.h"
#include <iostream>
#include <algorithm>
#include <fstream>

void TicketManager::addTicket(const Ticket& ticket) {
    tickets.push_back(ticket);
    std::cout << "Ticket added successfully.\n";
}

void TicketManager::loadTicketsFromFile(const std::string& filename) {
    std::ifstream file(filename.c_str(), std::ios::binary);
    if (file.is_open()) {
        Ticket ticket;
        while (file.read(reinterpret_cast<char*>(&ticket), sizeof(Ticket))) {
            tickets.push_back(ticket);
        }
        file.close();
        std::cout << "Tickets loaded successfully.\n";
    } else {
        std::cerr << "Unable to open file: " << filename << "\n";
    }
}

void TicketManager::saveTicketsToFile(const std::string& filename) {
    std::ofstream file(filename.c_str(), std::ios::binary);
    if (file.is_open()) {
        for (const auto& ticket : tickets) {
            file.write(reinterpret_cast<const char*>(&ticket), sizeof(Ticket));
        }
        file.close();
        std::cout << "Tickets saved successfully.\n";
    } else {
        std::cerr << "Unable to open file: " << filename << "\n";
    }
}

void TicketManager::displayTicketsForward() {
    for (const auto& ticket : tickets) {
        ticket.displayTicket();
    }
}

void TicketManager::displayTicketsBackward() {
    for (auto it = tickets.rbegin(); it != tickets.rend(); ++it) {
        it->displayTicket();
    }
}

void TicketManager::appendTicket(const Ticket& ticket) {
    addTicket(ticket);
}

void TicketManager::updateTicket(int ticketID, const Ticket& updatedTicket) {
    for (auto& ticket : tickets) {
        if (ticket.getID() == ticketID) {
            ticket = updatedTicket;
            break;
        }
    }
}

void TicketManager::removeTicket(int ticketID) {
    tickets.erase(std::remove_if(tickets.begin(), tickets.end(),
                                 [ticketID](const Ticket& ticket) { return ticket.getID() == ticketID; }),
                  tickets.end());
}

std::vector<Ticket> TicketManager::searchTickets(const std::string& criteria) {
    std::vector<Ticket> result;
    // Implementacja wyszukiwania biletów według kryteriów
    // ...
    return result;
}

void TicketManager::displayTickets() const {
    std::cout << "List of Tickets:\n";
    for (const auto& ticket : tickets) {
        std::cout << "ID: " << ticket.getID() << "\n";
        std::cout << "Title: " << ticket.getTitle() << "\n";
        std::cout << "Description: " << ticket.getDescription() << "\n";
        std::cout << "Creation Date: " << ticket.getCreationDate() << "\n";
        std::cout << "Status: " << ticket.getStatus() << "\n";
        std::cout << "Priority: " << ticket.getPriority() << "\n\n";
    }
}

void TicketManager::searchTickets(const std::string& criteria) const {
    std::cout << "Search results for '" << criteria << "':\n";
    for (const auto& ticket : tickets) {
        // Możesz dostosować kryteria wyszukiwania w zależności od potrzeb
        if (ticket.getTitle().find(criteria) != std::string::npos ||
            ticket.getDescription().find(criteria) != std::string::npos ||
            ticket.getStatus().find(criteria) != std::string::npos ||
            ticket.getPriority().find(criteria) != std::string::npos) {
            std::cout << "ID: " << ticket.getID() << "\n";
            std::cout << "Title: " << ticket.getTitle() << "\n";
            std::cout << "Description: " << ticket.getDescription() << "\n";
            std::cout << "Creation Date: " << ticket.getCreationDate() << "\n";
            std::cout << "Status: " << ticket.getStatus() << "\n";
            std::cout << "Priority: " << ticket.getPriority() << "\n\n";
        }
    }
}

void TicketManager::sortTickets() {
    // Sortuj bilet według dowolnego kryterium
    // W tym przypadku sortujemy po ID
    std::sort(tickets.begin(), tickets.end(),
              [](const Ticket& a, const Ticket& b) {
                  return a.getID() < b.getID();
              });

    std::cout << "Tickets sorted by ID.\n";
}

void TicketManager::manageTickets() {
    int choice;
    do {
        std::cout << "\nTicket Management Menu\n";
        std::cout << "1. Add Ticket\n";
        std::cout << "2. Display Tickets\n";
        std::cout << "3. Search Tickets\n";
        std::cout << "4. Sort Tickets\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                // Dodawanie nowego biletu
                std::string title, description, creationDate, status, priority;

                std::cout << "Enter title: ";
                std::cin.ignore();  // Ignoruj znaki nowej linii w buforze
                std::getline(std::cin, title);

                std::cout << "Enter description: ";
                std::getline(std::cin, description);

                std::cout << "Enter creation date: ";
                std::getline(std::cin, creationDate);

                std::cout << "Enter status: ";
                std::getline(std::cin, status);

                std::cout << "Enter priority: ";
                std::getline(std::cin, priority);

                Ticket newTicket(title, description, creationDate, status, priority);
                addTicket(newTicket);
                break;
            }
            case 2: {
                // Wyświetlanie biletów
                displayTickets();
                break;
            }
            case 3: {
                // Wyszukiwanie biletów
                std::string searchCriteria;
                std::cout << "Enter search criteria: ";
                std::cin.ignore();
                std::getline(std::cin, searchCriteria);
                searchTickets(searchCriteria);
                break;
            }
            case 4: {
                // Sortowanie biletów
                sortTickets();
                break;
            }
            case 0:
                std::cout << "Exiting Ticket Management Menu.\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
                break;
        }
    } while (choice != 0);
}