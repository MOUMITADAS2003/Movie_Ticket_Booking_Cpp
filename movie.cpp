#include <iostream>
#include <string>
#include <vector>

class Movie {
public:
    Movie(const std::string& title, int availableSeats)
        : title(title), availableSeats(availableSeats) {}

    const std::string& getTitle() const {
        return title;
    }

    int getAvailableSeats() const {
        return availableSeats;
    }

    void bookSeats(int numSeats) {
        if (numSeats <= availableSeats) {
            availableSeats -= numSeats;
            std::cout << numSeats << " seat(s) booked for " << title << std::endl;
        } else {
            std::cout << "Not enough seats available for " << title << std::endl;
        }
    }

private:
    std::string title;
    int availableSeats;
};

class MovieTicketBookingSystem {
public:
    void addMovie(const Movie& movie) {
        movies.push_back(movie);
    }

    void showMovies() const {
        std::cout << "Available movies:" << std::endl;
        for (const Movie& movie : movies) {
            std::cout << "- " << movie.getTitle() << " (" << movie.getAvailableSeats() << " seats)" << std::endl;
        }
    }

    void bookTickets(const std::string& movieTitle, int numSeats) {
        for (Movie& movie : movies) {
            if (movie.getTitle() == movieTitle) {
                movie.bookSeats(numSeats);
                return;
            }
        }
        std::cout << "Movie not found: " << movieTitle << std::endl;
    }

private:
    std::vector<Movie> movies;
};

int main() {
    MovieTicketBookingSystem bookingSystem;

    bookingSystem.addMovie(Movie("Avengers: Endgame", 100));
    bookingSystem.addMovie(Movie("Inception", 50));
    // Add more movies

    bookingSystem.showMovies();

    bookingSystem.bookTickets("Avengers: Endgame", 2);
    bookingSystem.bookTickets("Inception", 3);
    
    return 0;
}