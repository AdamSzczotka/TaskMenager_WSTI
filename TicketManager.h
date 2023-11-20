#pragma once
#include "Ticket.h"
#include "FileHandler.h"
#include <vector>

class TicketManager {
private:
    std::vector<Ticket> tickets;
    FileHandler fileHandler;

public:
    TicketManager();
    void addTicket(const Ticket& ticket);
    void displayTickets() const;
    void searchTickets(const std::string& criteria) const;
    void sortTickets();
    void manageTickets();
    void loadTicketsFromFile(const std::string& filename);
    void saveTicketsToFile(const std::string& filename);
    void displayTicketsForward();
    void displayTicketsBackward();
    void appendTicket(const Ticket& ticket);
    void updateTicket(int ticketID, const Ticket& updatedTicket);
    void removeTicket(int ticketID);
    std::vector<Ticket> searchTickets(const std::string& criteria);

};