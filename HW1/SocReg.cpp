// Ömer Mesud TOKER
// 21302479

#include <iostream>
#include "SocReg.h"
#include "Team.h"
#include "Player.h"
#include <string>

using namespace std;

SocReg::SocReg() {
    tNo = 0;
    teams = NULL;
}

int SocReg::getNoOfTeams() {
    return tNo;
}

Team* SocReg::getTeams() {
    return teams;
}

int SocReg::isEqual(string str1, string str2) {
        string lower1 = "", lower2 = "";
        for( int i = 0; i < (int)str1.length(); i++)
            lower1 += tolower( str1[i]);
        for( int i = 0; i < (int)str2.length(); i++)
            lower2 += tolower( str2[i]);
        return ( lower1 == lower2);
    }

void SocReg::addTeam( string teamName, string color ) {
    int isSame = 0;
    for(int i = 0; i < tNo && !isSame; i++)
        isSame = isEqual( teamName, teams[i].getTeamName());

    if(isSame)
        cout << "There is already a team whose name is " << teamName << "!" << endl;
    else {
        Team *tmp = new Team[tNo+1];
        for(int i = 0; i < tNo; i++)
            tmp[i] = teams[i];
        tmp[tNo++] = Team(teamName, color);

        delete []teams;
        teams = tmp;
    }
}

void SocReg::removeTeam( string teamName ) {
    int isSame = 0;
    for(int i = 0; i < tNo; i++)
        if(isEqual(teamName, teams[i].getTeamName())) {
            isSame = i + 1;
            break;
        }
    if(!isSame)
        cout << "There is no team whose name is " << teamName << "!" << endl;
    else {
        Team *tmp = new Team[--tNo];
        for(int i = 0; i < isSame - 1; i++)
            tmp[i] = teams[i];
        for(int i = isSame - 1; i < tNo; i++)
            tmp[i] = teams[i+1];

        delete []teams;
        teams = tmp;
    }
}

void SocReg::addPlayer( string teamName, string playerName, string playerPosition ) {
    int isSame = 0;
    for(int i = 0; i < tNo && !isSame; i++) {
        if(isEqual(teamName, teams[i].getTeamName()))
            isSame = i + 1;
    }
    if(!isSame)
        cout << "There is no team whose name is " << teamName << "!" << endl;
    else
        teams[isSame-1].addAPlayer(playerName, playerPosition);
}

void SocReg::removePlayer( string teamName, string playerName ) {
    int isSame = 0;
    for(int i = 0; i < tNo && !isSame; i++)
        if(isEqual(teamName, teams[i].getTeamName()))
            isSame = i + 1;

    if(!isSame)
        cout << "There is no team whose name is " << teamName << "!" << endl;
    else
        teams[isSame-1].removeAPlayer(playerName);
}

void SocReg::displayAllTeams() {
    if(!tNo)
        cout << "--EMPTY--" << endl;
    else
        for(int i = 0; i < tNo; i++)
            cout << teams[i].getTeamName() << ", " << teams[i].getTeamColor() << endl;
}

void SocReg::displayPlayer( string playerName ) {
    cout << playerName << endl;

    int isSame = 0;
    for(int i = 0; i < tNo; i++) {
        for(int j = 0; j < teams[i].getNoOfPlayers(); j++) {
            if(isEqual(teams[i].getRoster()[j].getPlayerName(), playerName)) {
                cout << teams[i].getRoster()[j].getPlayerPosition() << ", " << teams[i].getTeamName() << ", " << teams[i].getTeamColor() << endl;
                isSame = 1;
            }
        }
    }
    if(!isSame)
        cout << "--EMPTY--" << endl;
}

void SocReg::displayTeam( string teamName ) {
    int isSame = 0;
    for(int i = 0; i < tNo && !isSame; i++)
        if(isEqual(teams[i].getTeamName(), teamName))
            isSame = i + 1;
    if(!isSame)
        cout << "Team does not exist!" << endl;
    else {
        cout << teams[isSame-1].getTeamName() << ", " << teams[isSame-1].getTeamColor() << endl;

        if(!teams[isSame-1].getNoOfPlayers())
            cout << "--EMPTY--" << endl;
        else
            for(int i = 0; i < teams[isSame-1].getNoOfPlayers(); i++)
                cout << teams[isSame-1].getRoster()[i].getPlayerName() << ", " << teams[isSame-1].getRoster()[i].getPlayerPosition() << endl;
    }
}


SocReg::~SocReg()
{
if(tNo > 0)
    delete []teams;
}
