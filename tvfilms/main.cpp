#include <iostream>
#include <vector>
#include <fstream>
#include <string>


using namespace std;

struct Movie {
    string title;
    double rating;
    string genre;
    int year;
    string country;
};

const string FILE_NAME = "movies.txt";

void saveToFile(const vector<Movie>& movies) {
    ofstream out(FILE_NAME);
    for (size_t i = 0; i < movies.size(); ++i) {
        out << movies[i].title << '\n'
            << movies[i].rating << '\n'
            << movies[i].genre << '\n'
            << movies[i].year << '\n'
            << movies[i].country << '\n';
    }
}

void loadFromFile(vector<Movie>& movies) {
    movies.clear();
    ifstream file(FILE_NAME);
    if (!file.is_open()) {
        return;
    }

    Movie temp;
    while (getline(file, temp.title)) {
        file >> temp.rating;
        file.ignore();
        getline(file, temp.genre);
        file >> temp.year;
        file.ignore();
        getline(file, temp.country);
        movies.push_back(temp);
    }
}

void printMovie(const Movie& m) {
    cout << "Title: " << m.title << " | Rating: " << m.rating
        << " | Genre: " << m.genre << " | Year: " << m.year
        << " | Country: " << m.country << endl;
}

void showAll(const vector<Movie>& movies) {
    if (movies.empty()) {
        cout << "No movies found." << endl;
        return;
    }
    for (size_t i = 0; i < movies.size(); ++i) {
        printMovie(movies[i]);
    }
}

void addMovie(vector<Movie>& movies) {
    Movie m;
    cout << "Enter title: ";
    getline(cin, m.title);
    cout << "Enter rating: ";
    cin >> m.rating;
    cin.ignore();
    cout << "Enter genre: ";
    getline(cin, m.genre);
    cout << "Enter year: ";
    cin >> m.year;
    cin.ignore();
    cout << "Enter country: ";
    getline(cin, m.country);

    movies.push_back(m);
    saveToFile(movies);
}

void searchByTitle(const vector<Movie>& movies) {
    string target;
    cout << "Enter title to search: ";
    getline(cin, target);
    bool found = false;
    for (size_t i = 0; i < movies.size(); ++i) {
        if (movies[i].title == target) {
            printMovie(movies[i]);
            found = true;
        }
    }
    if (!found) cout << "Not found." << endl;
}

void searchByGenre(const vector<Movie>& movies) {
    string target;
    cout << "Enter genre to search: ";
    getline(cin, target);
    bool found = false;
    for (size_t i = 0; i < movies.size(); ++i) {
        if (movies[i].genre == target) {
            printMovie(movies[i]);
            found = true;
        }
    }
    if (!found) cout << "Not found." << endl;
}

void searchByYear(const vector<Movie>& movies) {
    int target;
    cout << "Enter year to search: ";
    cin >> target;
    bool found = false;
    for (size_t i = 0; i < movies.size(); ++i) {
        if (movies[i].year == target) {
            printMovie(movies[i]);
            found = true;
        }
    }
    if (!found) cout << "Not found." << endl;
}

void findMostPopular(const vector<Movie>& movies) {
    if (movies.empty()) {
        cout << "No movies available." << endl;
        return;
    }
    size_t bestIndex = 0;
    for (size_t i = 1; i < movies.size(); ++i) {
        if (movies[i].rating > movies[bestIndex].rating) {
            bestIndex = i;
        }
    }
    cout << "Most popular movie:" << endl;
    printMovie(movies[bestIndex]);
}

int main() {
    vector<Movie> movies;
    loadFromFile(movies);

    int choice;
    do {
        cout << "\n--- Online TV Menu ---\n"
            << "1. Show all movies\n"
            << "2. Add a movie\n"
            << "3. Search by title\n"
            << "4. Search by genre\n"
            << "5. Search by year\n"
            << "6. Find most popular\n"
            << "0. Exit\n"
            << "Choice: ";

        cin >> choice;
        cin.ignore();

        if (choice == 1) showAll(movies);
        else if (choice == 2) addMovie(movies);
        else if (choice == 3) searchByTitle(movies);
        else if (choice == 4) searchByGenre(movies);
        else if (choice == 5) searchByYear(movies);
        else if (choice == 6) findMostPopular(movies);

    } while (choice != 0);

    return 0;
}
