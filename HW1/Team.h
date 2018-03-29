// Ömer Mesud TOKER
// 21302479

#ifndef TEAM_H
#define TEAM_H
#include "Player.h"
#include <string>

using namespace std;

class Team
{
    public:
        //Team();
        Team(string = "", string = "");

        void setTeamName(string);
        string getTeamName();

        void setTeamColor(string);
        string getTeamColor();

        void setNoOfPlayers(int);
        int getNoOfPlayers();

        Player* getRoster();

        void removeAPlayer(string);
        void addAPlayer(string, string);

        void operator=( const Team&);

        //void displayTeam();

        virtual ~Team();
    protected:
    private:
        string color, tName;
        Player *roster;
        int pNo;
        int isEqual(string, string);
};

#endif // TEAM_H
