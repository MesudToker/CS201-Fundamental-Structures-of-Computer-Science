// Ömer Mesud TOKER
// 21302479

#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>

using namespace std;

class Player
{
    public:
        //Player();
        Player(string = "", string = "");

        void setPlayerName(string);
        string getPlayerName();

        void setPlayerPosition(string);
        string getPlayerPosition();

        // virtual ~Player();
    protected:
    private:
        string name;
        string pos;
};

#endif // PLAYER_H
