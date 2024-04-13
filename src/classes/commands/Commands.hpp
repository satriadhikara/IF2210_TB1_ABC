#ifndef COMMANDS_HPP
#define COMMANDS_HPP

class Main;

class Commands
{
public:
    Commands();
    virtual ~Commands();
    virtual void run(Main &) = 0;
};
#endif