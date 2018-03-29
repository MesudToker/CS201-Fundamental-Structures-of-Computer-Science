// Ömer Mesud TOKER
// 21302479

#include "Team.h"
#include "Player.h"
#include <string>

using namespace std;

/*Team::Team() {
    color = "";
    tName = "";
    pNo = 0;
    roster = NULL;
}*/

Team::Team(string tName, string color) {
    this -> tName = tName;
    this -> color = color;
    pNo = 0;
    roster = NULL;
}

int Team::isEqual(string str1, string str2) {
    string lower1 = "", lower2 = "";
    for( int i = 0; i < str1.length(); i++)
        lower1 += tolower( str1[i]);
    for( int i = 0; i < str2.length(); i++)
        lower2 += tolower( str2[i]);
    return ( lower1 == lower2);
}

void Team::operator =( const Team &second)
{
    this->tName = second.tName;
    this->color = second.color;
    this->pNo = second.pNo;

    delete[] this->roster;
    roster = new Player[pNo];
    for( int i = 0; i < pNo; i++)
        this->roster[i] = second.roster[i];
}

void Team::setTeamName(string tName) {
    this -> tName = tName;
}

string Team::getTeamName() {
    return tName;
}

void Team::setTeamColor(string color) {
    this -> color = color;
}

string Team::getTeamColor() {
    return color;
}

void Team::setNoOfPlayers(int pNo) {
    this -> pNo = pNo;
}

int Team::getNoOfPlayers() {
    return pNo;
}

Player* Team::getRoster() {
    return roster;
}

void Team::removeAPlayer(string name) {
    int isSame = 0;
    for(int i = 0; i < this->getNoOfPlayers(); i++) {
        if(isEqual(name, this->getRoster()[i].getPlayerName())) {
            isSame = i + 1;
            break;
        }
    }
    if(!isSame)
        cout << "In " << this->getTeamName() << ", there is no player whose name is " << name << "!" << endl;
    else {
        this->setNoOfPlayers(--pNo);

        Player *tmp = new Player[this->getNoOfPlayers()];

        for(int i = 0; i < isSame - 1; i++)
            tmp[i] = this->getRoster()[i];
        for (int i = isSame - 1; i < this->getNoOfPlayers(); i++)
            tmp[i] = this->getRoster()[i+1];

        delete []roster;
        roster = tmp;
    }
}

void Team::addAPlayer(string name, string pos) {
    int isSame = 0;
    for(int i = 0; i < pNo && !isSame; i++)
        isSame = isEqual(name, roster[i].getPlayerName());

    if(isSame)
        cout << "In " << this->getTeamName() << ", there is already a player whose name is " << name << "!" << endl;
    else {
        Player *tmp = new Player[pNo+1];
        for(int i = 0; i < pNo; i++)
            tmp[i] = roster[i];
        tmp[pNo++] = Player(name, pos);

        delete []roster;
        roster = tmp;
    }
}

Team::~Team()
{
if(pNo > 0)
    delete []roster;
}


