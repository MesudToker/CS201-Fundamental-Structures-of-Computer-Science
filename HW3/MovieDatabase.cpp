// Ömer Mesud TOKER
// 21302479
// Section 2

#include "MovieDatabase.h"
#include <iostream>
#include <string>
using namespace std;

// constructor
MovieDatabase::MovieDatabase() {
    head = NULL;
    movieNo = 0;
}

// destructor
MovieDatabase::~MovieDatabase() {
    while( head != NULL) {
        Movie *temp = head;
        head = head->next;
        //delete temp->cast;
        delete temp;
    }
}

MovieDatabase::Movie::Movie( string title = "", string dName = "", string dLast = "", int day = 0, int month = 0, int year = 0) {
    this->title = title;
    this->dName = dName;
    this->dLast = dLast;
    this->day = day;
    this->month = month;
    this->year = year;

    precede = NULL;
    next = NULL;

    cast = NULL;

    actorNo = 0;
}

MovieDatabase::Movie::~Movie() {
    while( cast != NULL) {
        Actor *temp = cast;
        cast = cast->next;
        delete temp;
    }
}

string MovieDatabase::toUpper( string str) {
    string upper = "";
    for( int i = 0; i < (int)str.length(); ++i)
        upper += toupper( str[i]);
    return upper;
}

int MovieDatabase::areMoviesSame( string movie1, string movie2) {
    return ( toUpper( movie1) == toUpper( movie2));
}

int MovieDatabase::areActorsSame( string name1, string surname1, string name2, string surname2) {
    return areMoviesSame( name1, name2) && areMoviesSame( surname1, surname2);
}

void MovieDatabase::addMovie( const string movieTitle, const string directorFirstName, const string directorLastName, const int releaseDay, const int releaseMonth, const int releaseYear) {
    if ( head == NULL )
        head = new Movie( movieTitle, directorFirstName, directorLastName, releaseDay, releaseMonth, releaseYear);
    else {
        Movie *cur = head;

        while ( cur->next != NULL ) {
            if ( areMoviesSame( cur->title, movieTitle) ) {
                cout << "There is already a movie whose name is " << movieTitle << "!" << endl;
                return;
            }
            cur = cur->next;
        }
        if ( areMoviesSame( cur->title, movieTitle) ) {
            cout << "There is already a movie whose name is " << movieTitle << "!" << endl;
            return;
        }
        cur->next = new Movie( movieTitle, directorFirstName, directorLastName, releaseDay, releaseMonth, releaseYear);
        (cur->next)->precede = cur;
    }
    ++movieNo;
}

void MovieDatabase::removeMovie( const string movieTitle) {
    /* if( head == NULL )
        cout << "There is no movie in the database!" << endl;
    else {
        Movie *temp;
        Movie *cur;

        if ( areMoviesSame( head->title, movieTitle )) {
            temp = head->next;
            head->next= NULL;
            delete head;
            head = temp;
            cout << movieTitle << " deleted successfully!";
        }
        else {
            cur = head;

            for(;;){
                if( cur->next == NULL ){
                    cout << "There is no movie whose name is " << movieTitle << "!" << endl;
                    break;
                }
                if( areMoviesSame( (cur->next)->title, movieTitle )){
                    temp = cur->next;
                    cur->next = temp->next;
                    temp->next= NULL;
                    delete temp;
                    temp = NULL;
                    break;
                }
                cur = cur->next;
            }
        }
    } */
    Movie *cur = head;

    while( cur != NULL && !areMoviesSame( cur->title, movieTitle) )
        cur = cur->next;
    if( cur == NULL)
        cout << "There is no movie whose name is " << movieTitle << "!" << endl;
    else {
        if( cur == head ) {
            if( movieNo == 1) {
                delete cur;
                head = NULL;
            }
            else {
                head->next->precede = NULL;
                head = head->next;
                delete cur;
            }
        }
        else {
            cur->precede->next = cur->next;
            if( cur->next != NULL )
                cur->next->precede = cur->precede;
            delete cur;
        }
        --movieNo;
    }
}

void MovieDatabase::addActor( const string movieTitle, const string actorFirstName, const string actorLastName, const string actorRole ) {
    Movie *cur = head;
    for (; cur != NULL && !areMoviesSame(cur->title, movieTitle); cur = cur->next);
    if (cur == NULL)
        cout << "There is no movie whose name is " << movieTitle << "!" << endl;
    else {
        if ( cur->cast == NULL ) {
            Actor *actor = new Actor;
            actor->name = actorFirstName;
            actor->last = actorLastName;
            actor->role = actorRole;
            actor->next = NULL;
            cur->cast = actor;
            cur->actorNo++;
            //cout << "first actor added" << endl;
        }
        else {
            bool isActorExist = false;
            Actor *temp = cur->cast;
            for ( ; temp != NULL; temp = temp->next )
                if ( areActorsSame( actorFirstName, actorLastName, temp->name, temp->last ) ) {
                    isActorExist = true;
                    break;
                }

            if (isActorExist)
                cout << "There is already an actor/actress whose name is " << actorFirstName << " " << actorLastName << endl;
            else {
                string upperName = toUpper(actorFirstName);
                string upperLast = toUpper(actorLastName);

                Actor *actor = new Actor;
                actor->name = actorFirstName;
                actor->last = actorLastName;
                actor->role = actorRole;

                if ( upperLast < toUpper(cur->cast->last) || (upperLast == toUpper(cur->cast->last) && upperName < toUpper(cur->cast->name) )) {
                    actor->next = cur->cast;
                    cur->cast = actor;
                    //cout << "actor added to head" << endl;
                }
                else {
                    temp = cur->cast->next;
                    Actor *prev = cur->cast;

                    for ( ; temp != NULL; ) {
                        if ( upperLast < toUpper(temp->last) || (upperLast == toUpper(temp->last) && upperName < toUpper(temp->name)) ) {
                            actor->next = temp;
                            prev->next = actor;
                            //cout << "actor added somewhere" << endl;
                            break;
                        }
                        prev = prev->next;
                        temp = temp->next;
                    }
                    if (temp == NULL) {
                        prev->next = actor;
                        actor->next = NULL;
                        //cout << "actor added to last" << endl;
                    }
                }
                (cur->actorNo)++;
            }
        }
    }
}

void MovieDatabase::removeActor(const string movieTitle, const string actorFirstName,const string actorLastName){
    Movie *cur = head;
    bool isActorExist = false;
    for ( ; cur != NULL && !areMoviesSame(cur->title, movieTitle); cur = cur->next);

    if ( cur == NULL )
        cout << "There is no movie whose name is " << movieTitle << "!" << endl;
    else {
        if ( cur->cast == NULL )
            cout << "The cast of " << movieTitle << " is empty!" << endl;
        else {
            Actor *temp, *prev;
            if ( areActorsSame(cur->cast->name, cur->cast->last, actorFirstName, actorLastName )) {
                temp = cur->cast;
                cur->cast = cur->cast->next;
                temp->next = NULL;
                delete temp;
                temp = NULL;
                isActorExist = true;
            }
            else {
                prev = cur->cast;
				temp = cur->cast->next;
				for ( ; temp != NULL; ) {
                    if(areActorsSame(temp->name, temp->last, actorFirstName, actorLastName)) {
                        prev->next = temp->next;
                        temp->next = NULL;
                        delete temp;
                        temp = NULL;
                        isActorExist = true;
                        break;
                    }
                    temp = temp->next;
                    prev = prev->next;
				}
            }
            (cur->actorNo)--;
        }
        if (!isActorExist)
            cout << "There is no actor/actress whose name is " << actorFirstName << " " << actorLastName << endl;
    }
}

void MovieDatabase::showAllMovies(){
    if( movieNo == 0)
        cout << "---none---" << endl;
    else
        for( Movie *cur = head; cur != NULL; cur = cur->next )
            cout << cur->title << ", " << cur->year << ", " << cur->dName << " " << cur->dLast << endl;
}

void MovieDatabase::showMovie(const string movieTitle){
    Movie *cur;
    for ( cur = head; cur != NULL && !areMoviesSame(cur->title, movieTitle); cur = cur->next );

    if (cur == NULL)
        cout << movieTitle << endl << "---none---" << endl;
    else {
        cout << movieTitle << endl;
        cout << cur->day << " / " << cur->month << " / " << cur->year << endl;
        cout << cur->dName << " " << cur->dLast << endl;

        for( Actor *curr = cur->cast; curr != NULL; curr = curr->next ) {
            cout << curr->name << " " << curr->last << ", " << curr->role << endl;
        }
    }
}

void MovieDatabase::showActorRoles(const string actorFirstName,const string actorLastName){
    /*bool isActorExist = false;
    for ( Movie *cur = head; cur != NULL; cur = cur->next ) {
        for ( Actor *curr = cur->cast; curr != NULL; curr = curr->next ) {
            if ( areActorsSame(actorFirstName, actorLastName, curr->name, curr->last ) ) {
                if ( !isActorExist  )
                    cout << actorFirstName << " " << actorLastName << endl;
                cout << curr->role << ", " << cur->title << ", " << cur->year << endl;
                isActorExist = true;
            }
        }
    }
    if (!isActorExist)
        cout << actorFirstName << " " << actorLastName << endl << "---none---" << endl;*/
        Movie *cur = head;
        Actor *curr;
        cout<< actorFirstName << " " << actorLastName << endl;
        bool isActorExist = false;
        for ( ; cur != NULL; cur = cur->next) {
            curr = cur->cast;
            for ( ; curr != NULL; curr = curr->next )
                if ( areActorsSame(curr->name, curr->last, actorFirstName, actorLastName) ) {
                    cout << curr->role << ", " << cur->title << ", " << cur->year << endl;
                    isActorExist = true;
                    break;
                }
        }
        if ( !isActorExist )
            cout << "---none---" << endl;
}

void MovieDatabase::showMovies(const int releaseYear){
    bool isMovieExist = false;
    cout << releaseYear << endl;

    for ( Movie *cur = head; cur != NULL; cur = cur->next )
        if ( cur->year == releaseYear ) {
            cout << cur->title << ", " << cur->dName << " " << cur->dLast << ", " << cur->day << "/" << cur->month << endl;
            isMovieExist = true;
        }

    if ( !isMovieExist )
        cout << "---none---" << endl;
}
