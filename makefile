CC = g++

CFLAGS = -std=c++14

SRCDIR = src
OUTDIR = bin
CLSDIR = $(SRCDIR)/Classes
UTILDIR = $(SRCDIR)/Utils

CLSFILES = $(wildcard $(CLSDIR)/*.cpp)
UTILFILES = $(wildcard $(UTILDIR)/*.cpp)

all: run

run: 
	$(CLSFILES) $(UTILFILES)
	$(CC) $(CFLAGS) -I include $^ $(SRCDIR)/main.cpp -o $(OUTDIR)/main
	./$(OUTDIR)/main