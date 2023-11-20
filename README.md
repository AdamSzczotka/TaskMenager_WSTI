# TicketMenager_WSTI
Plan aplikacji obsługi ticketów 
Ogólna struktura programu: 
  Aplikacja będzie oparta na konsoli i będzie obsługiwać operacje na "ticketach".  Tickety to obiekty opisane przez pewne atrybuty, takie jak ID, tytuł, opis, data  utworzenia, status itp. Wszystkie dane będą przechowywane w plikach  binarnych. 
Klasy: 
• Ticket (klasa reprezentująca pojedynczy ticket):
  o Pola: 
    ▪ ID (numer identyfikacyjny) 
    ▪ Tytuł 
    ▪ Opis 
    ▪ Data utworzenia 
    ▪ Status 
    ▪ Priorytet 
  o Metody: 
    ▪ Konstruktor 
    ▪ Gettery i settery dla pól 
• TicketManager (klasa zarządzająca ticketami): 
  o Pola: 
    ▪ Wektor obiektów Ticket przechowujący tickety 
  o Metody: 
    ▪ Dodawanie nowego ticketu 
    ▪ Otwieranie pliku z istniejącymi ticketami 
    ▪ Zapisywanie ticketów do pliku 
    ▪ Przeglądanie ticketów (do przodu i do tyłu) 
    ▪ Dopisywanie pojedynczego ticketu z walidacją 
    ▪ Aktualizacja pojedynczego ticketu 
    ▪ Usuwanie pojedynczego ticketu z potwierdzeniem 
    ▪ Wyszukiwanie ticketów według kryteriów 
    ▪ Sortowanie ticketów 
• FileHandler (klasa do obsługi plików): 
  o Metody: 
    ▪ Tworzenie nowego pliku 
    ▪ Otwieranie istniejącego pliku 
    ▪ Zapisywanie danych do pliku 
    ▪ Eksport pliku do innych formatów 
• UserManager (klasa zarządzająca użytkownikami i ich uprawnieniami):
  o Metody: 
    ▪ Zarządzanie użytkownikami 
    ▪ Przypisywanie uprawnień
Operacje użytkownika: 
1. Dodawanie nowego ticketu 
2. Otwieranie pliku z istniejącymi ticketami 
3. Zapisywanie zmian w pliku 
4. Przeglądanie ticketów (do przodu i do tyłu) 
5. Dopisywanie pojedynczego ticketu 
6. Aktualizacja pojedynczego ticketu 
7. Usuwanie pojedynczego ticketu 
8. Wyszukiwanie ticketów według kryteriów 
9. Sortowanie ticketów 
10. Eksport pliku do innych formatów 
Dodatkowe funkcje: 
1. Praca z wieloma plikami (wybór, archiwizacja, zapisz jako) 
2. Zaznaczanie / wyłączanie elementów do usunięcia, archiwizacji 3. Usuwanie grupowe na podstawie zaznaczenia lub kryteriów 
4. Zaawansowane kryteria wyszukiwawcze (z operatorami logicznymi, dokładne /  przybliżone) 
5. Wyszukaj i zamień 
6. Nakładanie / wyłączanie filtrów 
7. Zaawansowana walidacja i zabezpieczenia 
8. Hasło dostępu do operacji modyfikujących 
9. Użytkownicy z uprawnieniami

