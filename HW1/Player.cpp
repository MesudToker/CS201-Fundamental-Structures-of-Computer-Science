// Ömer Mesud TOKER
// 21302479

#include "Player.h"
#include <string>

using namespace std;

/*Player::Player() {
    name = "";
    pos = "";
}*/

Player::Player(string name, string pos) {
    this -> name = name;
    this -> pos = pos;
}

void Player::setPlayerName(string name) {
    this -> name = name;
}

string Player::getPlayerName() {
    return name;
}

void Player::setPlayerPosition(string pos) {
    this -> pos = pos;
}

string Player::getPlayerPosition() {
    return pos;
}

/*Player::~Player()
{

}*/
