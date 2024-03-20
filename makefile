CC = g++

CFLAGS = -std=c++14

SRCDIR = src
OUTDIR = bin
CLSDIR = $(SRCDIR)/ulasses
UTILDIR = $(SRCDIR)/utils

CLSFILES = $(wildcard $(CLSDIR)/*.cpp)
UTILFILES = $(wildcard $(UTILDIR)/*.cpp)

all: run

run: build
	./$(OUTDIR)/main

build:
	$(CLSFILES) $(UTILFILES)
	$(CC) $(CFLAGS) -I include $^ $(SRCDIR)/main.cpp -o $(OUTDIR)/main