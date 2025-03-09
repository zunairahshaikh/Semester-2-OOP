#include <iostream>
#include <string>

class Movie {
private:
    std::string title;
    std::string director;
    int duration;

public:
    Movie(const std::string& _title, const std::string& _director, int _duration)
        : title(_title), director(_director), duration(_duration) {}

    std::string getTitle() const { return title; }
    std::string getDirector() const { return director; }
    int getDuration() const { return duration; }
};

class Playlist {
private:
    std::string name;
    Movie** movies;
    int numMovies;
    int capacity;

public:
    Playlist(const std::string& _name) : name(_name), numMovies(0), capacity(10) {
        movies = new Movie*[capacity];
    }

    ~Playlist() {
        for (int i = 0; i < numMovies; ++i) {
            delete movies[i];
        }
        delete[] movies;
    }

    void addMovie(Movie* movie) {
        if (numMovies >= capacity) {
            capacity *= 2;
            Movie** newMovies = new Movie*[capacity];
            for (int i = 0; i < numMovies; ++i) {
                newMovies[i] = movies[i];
            }
            delete[] movies;
            movies = newMovies;
        }
        movies[numMovies++] = movie;
    }

    void removeMovie(Movie* movie) {
        for (int i = 0; i < numMovies; ++i) {
            if (movies[i] == movie) {
                for (int j = i; j < numMovies - 1; ++j) {
                    movies[j] = movies[j + 1];
                }
                --numMovies;
                break;
            }
        }
    }

    void displayInfo() const {
        std::cout << "Playlist: " << name << std::endl;
        for (int i = 0; i < numMovies; ++i) {
            std::cout << "Movie: " << movies[i]->getTitle() 
                      << ", Director: " << movies[i]->getDirector() 
                      << ", Duration: " << movies[i]->getDuration() << " mins" << std::endl;
        }
    }
};

class User {
private:
    std::string name;
    Playlist** playlists;
    int numPlaylists;
    int capacity;

public:
    User(const std::string& _name) : name(_name), numPlaylists(0), capacity(10) {
        playlists = new Playlist*[capacity];
    }

    ~User() {
        for (int i = 0; i < numPlaylists; ++i) {
            delete playlists[i];
        }
        delete[] playlists;
    }

    void createPlaylist(const std::string& playlistName) {
        if (numPlaylists >= capacity) {
            capacity *= 2;
            Playlist** newPlaylists = new Playlist*[capacity];
            for (int i = 0; i < numPlaylists; ++i) {
                newPlaylists[i] = playlists[i];
            }
            delete[] playlists;
            playlists = newPlaylists;
        }
        playlists[numPlaylists++] = new Playlist(playlistName);
    }

    void addMovieToPlaylist(Playlist* playlist, Movie* movie) {
        playlist->addMovie(movie);
    }

    void removeMovieFromPlaylist(Playlist* playlist, Movie* movie) {
        playlist->removeMovie(movie);
    }

    void displayUserPlaylists() const {
        std::cout << "User: " << name << std::endl;
        for (int i = 0; i < numPlaylists; ++i) {
            playlists[i]->displayInfo();
        }
    }

    Playlist* getPlaylist(int index) const {
        if (index >= 0 && index < numPlaylists) {
            return playlists[index];
        }
        return nullptr;
    }
};

int main() {
    Movie* darkKnight = new Movie("The Dark Knight", "Christopher Nolan", 152);
    Movie* inception = new Movie("Inception", "Christopher Nolan", 148);
    Movie* hangover = new Movie("The Hangover", "Todd Phillips", 100);
    Movie* superbad = new Movie("Superbad", "Greg Mottola", 119);

    User user("Mujeeb Rehman");

    user.createPlaylist("Action Movies");
    user.createPlaylist("Comedy Movies");

    Playlist* actionPlaylist = user.getPlaylist(0);
    Playlist* comedyPlaylist = user.getPlaylist(1);

    user.addMovieToPlaylist(actionPlaylist, darkKnight);
    user.addMovieToPlaylist(actionPlaylist, inception);
    user.addMovieToPlaylist(comedyPlaylist, hangover);
    user.addMovieToPlaylist(comedyPlaylist, superbad);

    user.displayUserPlaylists();

    user.removeMovieFromPlaylist(actionPlaylist, inception);

    std::cout << "\nAfter removing 'Inception':\n";
    user.displayUserPlaylists();

    delete darkKnight;
    delete inception;
    delete hangover;
    delete superbad;

    return 0;
}
