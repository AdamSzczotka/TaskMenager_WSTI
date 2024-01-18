/**
 * @brief Klasa do obsługi plików.
 * 
 * FileHandler to klasa pomocnicza służąca do zarządzania operacjami na plikach.
 * Oferuje funkcje do tworzenia, czytania, zapisywania i eksportowania danych do plików.
 */
#pragma once
#include <string>
#include <vector>

class FileHandler {
public:
    /**
     * @brief Tworzy nowy plik, jeśli jeszcze nie istnieje.
     * 
     * @param filename Nazwa pliku do utworzenia.
     */
    static void createFile(const std::string& filename);

    /**
     * @brief Czyta zawartość pliku i zwraca ją jako wektor ciągów znaków.
     * 
     * @param filename Nazwa pliku do odczytu.
     * @return std::vector<std::string> Wektor zawierający linie tekstu z pliku.
     */
    static std::vector<std::string> readFile(const std::string& filename);

    /**
     * @brief Zapisuje dane do pliku.
     * 
     * @param filename Nazwa pliku, do którego dane mają być zapisane.
     * @param data Wektor ciągów znaków do zapisania w pliku.
     */
    static void writeFile(const std::string& filename, const std::vector<std::string>& data);

    /**
     * @brief Eksportuje dane ticketów do pliku tekstowego.
     * 
     * @param sourceFilename Nazwa pliku źródłowego z danymi ticketów.
     * @param targetFilename Nazwa pliku docelowego, do którego dane mają być eksportowane.
     */
    static void exportTicketsToTxt(const std::string& sourceFilename, const std::string& targetFilename);
};

