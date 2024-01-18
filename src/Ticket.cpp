#include "../include/Ticket.h"

// Konstruktor
Ticket::Ticket(int id, std::string title, std::string description, std::string status, int priority)
    : ID(id), title(title), description(description), creationDate(time(nullptr)), status(status), priority(priority) {}

// Gettery
int Ticket::getID() const { return ID; }
std::string Ticket::getTitle() const { return title; }
std::string Ticket::getDescription() const { return description; }
time_t Ticket::getCreationDate() const { return creationDate; }
std::string Ticket::getStatus() const { return status; }
int Ticket::getPriority() const { return priority; }

// Settery
void Ticket::setID(int newID) { ID = newID; }
void Ticket::setTitle(const std::string& newTitle) { title = newTitle; }
void Ticket::setDescription(const std::string& newDescription) { description = newDescription; }
void Ticket::setCreationDate(time_t newCreationDate) { creationDate = newCreationDate; }
void Ticket::setStatus(const std::string& newStatus) { status = newStatus; }
void Ticket::setPriority(int newPriority) { priority = newPriority; }
