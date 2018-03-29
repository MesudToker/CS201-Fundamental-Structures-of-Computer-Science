// Ömer Mesud TOKER
// 21302479
// Section 2

#ifndef MOVIEDATABASE_H
#define MOVIEDATABASE_H
#include <iostream>
#include <string>

using namespace std;

class MovieDatabase {
	public:
		MovieDatabase();
		~ MovieDatabase();

		void addMovie(const string movieTitle, const string directorFirstName,const string directorLastName, const int releaseDay,const int releaseMonth, const int releaseYear);
		void removeMovie(const string movieTitle);

		void addActor(const string movieTitle, const string actorFirstName, const string actorLastName, const string actorRole);
		void removeActor(const string movieTitle, const string actorFirstName, const string actorLastName);

		void showAllMovies();

		void showMovie(const string movieTitle);

		void showActorRoles(const string actorFirstName, const string actorLastName);

		void showMovies(const int releaseYear);

		int areMoviesSame( string movie1, string movie2);

        int areActorsSame( string name1, string surname1, string name2, string surname2);

        string toUpper( string);

    private:
        struct Actor{
			string name, last, role;
			Actor *next;
		};

        struct Movie {
            Movie( string title, string dName, string dLast, int day, int month, int year);
            ~Movie();

            string title, dName, dLast;
			int day, month, year;

			Actor *cast;
			Movie *next, *precede;

			int actorNo;
        };
        Movie *head;
        int movieNo;
};

#endif // MOVIEDATABASE_H

