CC = g++

CFLAGS = -std=c++14

SRCDIR = src
OUTDIR = .
CLSDIR = $(SRCDIR)/classes
CMDDIR = $(CLSDIR)/commands

CLSFILES = $(CLSDIR)/Main.cpp $(CLSDIR)/Menu.cpp $(CLSDIR)/Pemain.cpp $(CLSDIR)/Petani.cpp $(CLSDIR)/Walikota.cpp $(CLSDIR)/Peternak.cpp $(CLSDIR)/Peternakan.cpp $(CLSDIR)/Animal.cpp $(CLSDIR)/Items.cpp $(CLSDIR)/CarnivoreAnimal.cpp $(CLSDIR)/HerbivoreAnimal.cpp $(CLSDIR)/OmnivoreAnimal.cpp $(CLSDIR)/Ladang.cpp $(CLSDIR)/Plant.cpp $(CLSDIR)/FruitPlant.cpp $(CLSDIR)/MaterialPlant.cpp $(CLSDIR)/ConfigController.cpp $(CLSDIR)/Bangunan.cpp $(CLSDIR)/Product.cpp
CMDFILES = $(CMDDIR)/Commands.cpp $(CMDDIR)/Next.cpp $(CMDDIR)/CetakPenyimpanan.cpp $(CMDDIR)/CetakPeternakan.cpp $(CMDDIR)/CetakLadang.cpp $(CMDDIR)/PungutPajak.cpp

all: build

build:
	$(CC) $(CFLAGS) $(SRCDIR)/main.cpp $(CLSFILES) $(CMDFILES) -o $(OUTDIR)/main