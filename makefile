CC = g++

CFLAGS = -std=c++14

SRCDIR = src
OUTDIR = .
CLSDIR = $(SRCDIR)/classes
CMDDIR = $(CLSDIR)/commands

CLSFILES = $(CLSDIR)/Main.cpp $(CLSDIR)/Menu.cpp $(CLSDIR)/Pemain.cpp $(CLSDIR)/Walikota.cpp $(CLSDIR)/Peternak.cpp $(CLSDIR)/Petani.cpp 
CMDFILES = $(CMDDIR)/Commands.cpp $(CMDDIR)/Next.cpp $(CMDDIR)/CetakPenyimpanan.cpp $(CMDDIR)/PungutPajak.cpp 

all: build

build:
	$(CC) $(CFLAGS) $(SRCDIR)/main.cpp $(CLSFILES) $(CMDFILES) -o $(OUTDIR)/main