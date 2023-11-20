#include "Ticket.h"
#include <sstream>

Ticket::Ticket(int id, const std::string& t, const std::string& desc, const std::string& date,
               const std::string& stat, const std::string& pri)
    : ID(id), title(t), description(desc), creationDate(date), status(stat), priority(pri){}

int Ticket::getID() const {
    return ID;
}

std::string Ticket::getTitle() const {
    return title;
}

std::string Ticket::getDescription() const {
    return description;
}

std::string Ticket::getCreationDate() const {
    return creationDate;
}

std::string Ticket::getStatus() const {
    return status;
}

std::string Ticket::getPriority() const {
    return priority;
}

void Ticket::setID(int id) {
    ID = id;
}

void Ticket::setTitle(const std::string& t) {
    title = t;
}

void Ticket::setDescription(const std::string& desc) {
    description = desc;
}

void Ticket::setCreationDate(const std::string& date) {
    creationDate = date;
}

void Ticket::setStatus(const std::string& stat) {
    status = stat;
}

void Ticket::setPriority(const std::string& pri) {
    priority = pri;
}

void Ticket::displayTicket() const {
    std::cout << "ID: " << ID << "\n";
    std::cout << "Title: " << title << "\n";
    std::cout << "Description: " << description << "\n";
    std::cout << "Creation Date: " << creationDate << "\n";
    std::cout << "Status: " << status << "\n";
    std::cout << "Priority: " << priority << "\n";
    std::cout << "------------------------\n";
}

std::string Ticket::serialize() const {
    // Serializacja obiektu do jednego stringa
    std::stringstream ss;
    ss << ID << "|" << title << "|" << description << "|" << creationDate << "|" << status << "|" << priority;
    return ss.str();
}

Ticket Ticket::deserialize(const std::string& data) {
    // Deserializacja stringa do obiektu Ticket
    std::istringstream ss(data);
    std::string token;
    
    // ID|Title|Description|CreationDate|Status|Priority
    getline(ss, token, '|');
    int id = std::stoi(token);
    
    getline(ss, token, '|');
    std::string title = token;

    getline(ss, token, '|');
    std::string description = token;

    getline(ss, token, '|');
    std::string creationDate = token;

    getline(ss, token, '|');
    std::string status = token;

    getline(ss, token, '|');
    std::string priority = token;

    return Ticket(id, title, description, creationDate, status, priority);
}
