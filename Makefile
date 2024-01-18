# Kompilator
CC = g++

# Opcje kompilatora
CFLAGS = -I include -Wall

# Ścieżka do plików wykonywalnych
BINDIR = bin

# Pliki źródłowe
SRC = $(wildcard src/*.cpp)

# Pliki obiektowe
OBJ = $(SRC:src/%.cpp=$(BINDIR)/%.o)

# Nazwa pliku wykonywalnego
EXEC = $(BINDIR)/projekt

# Reguła domyślna
all: $(EXEC)

# Linkowanie
$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

# Kompilacja
$(BINDIR)/%.o: src/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Tworzenie katalogu bin, jeśli nie istnieje
$(shell mkdir -p $(BINDIR))

# Czyszczenie
clean:
	rm -f $(OBJ) $(EXEC)