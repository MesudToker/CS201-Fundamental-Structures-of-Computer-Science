// Ömer Mesud TOKER
// 21302479

#include <string>
#ifndef SOCREG_H
#define SOCREG_H
#include "Team.h"
#include <string>

using namespace std;

class SocReg {
public:
    SocReg();
    ~SocReg();
    void addTeam( string teamName, string color );
    void removeTeam( string teamName );
    void addPlayer( string teamName, string playerName, string playerPosition );
    void removePlayer( string teamName, string playerName );

    void displayAllTeams();
    void displayPlayer( string playerName );
    void displayTeam( string teamName );

    int getNoOfTeams();
    Team* getTeams();

private:
    Team *teams;
    int isEqual(string, string);
    int tNo;
};

#endif
