#ifndef _EXCEPTION_HPP_
#define _EXCEPTION_HPP_

#include <exception>
using namespace std;

class GameException : public exception {
public:
    virtual const char* what() const noexcept override {
        return "Game exception occurred.\n";
    }
};

class RunCommandException : public GameException {
public:
    const char* what() const noexcept override {
        return "Command Not Found.\n";
    }
};

class CetakPenyimpananException : public GameException {
public:
    const char* what() const noexcept override {
        return "Pointer pemain kosong.\n";
    }
};

class WalikotaException : public GameException {
public:
    const char* what() const noexcept override {
        return "Pemain bukan walikota.\n";
    }
};

class PetaniException : public GameException {
public:
    const char* what() const noexcept override {
        return "Pemain bukan petani.\n";
    }
};

class PeternakException : public GameException {
public:
    const char* what() const noexcept override {
        return "Pemain bukan peternak.\n";
    }
};

class MakanException : public GameException {
public:
    const char* what() const noexcept override {
        return "Tidak ada makanan yang bisa dimakan!.\n";
    }
};

class BeliException : public GameException {
public:
    const char* what() const noexcept override {
        return "Invalid item state.\n";
    }
};

class JualException : public GameException {
public:
    const char* what() const noexcept override {
        return "Invalid item state.\n";
    }
};

#endif