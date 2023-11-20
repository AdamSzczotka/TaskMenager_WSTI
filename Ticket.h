#pragma once
#include <string>
#include <iostream>

class Ticket {
private:
    int ID;
    std::string title;
    std::string description;
    std::string creationDate;
    std::string status;
    std::string priority;

public:
    Ticket(int id, const std::string& t, const std::string& desc, const std::string& date,
           const std::string& stat, const std::string& pri);

    Ticket() = default;

    // Gettery i settery dla pól
    int getID() const;
    std::string getTitle() const;
    std::string getDescription() const;
    std::string getCreationDate() const;
    std::string getStatus() const;
    std::string getPriority() const;

    void setID(int id);
    void setTitle(const std::string& t);
    void setDescription(const std::string& desc);
    void setCreationDate(const std::string& date);
    void setStatus(const std::string& stat);
    void setPriority(const std::string& pri);

    void displayTicket() const;

    // Serializacja i deserializacja
    std::string serialize() const;
    static Ticket deserialize(const std::string& data);
};
