#include "Catalog.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

const string DB_NAME = "database.txt";

void addSong(vector<Song>& songs, const Song& song) {
    songs.push_back(song);
    saveDatabase(songs);
    cout << "Successfully added and saved to database!\n";
}

void deleteSong(vector<Song>& songs, const string& title) {
    for (auto it = songs.begin(); it != songs.end(); ++it) {
        if (it->title == title) {
            songs.erase(it);
            saveDatabase(songs);
            cout << "Song '" << title << "' deleted from database.\n";
            return;
        }
    }
    cout << "Error: Song not found.\n";
}

void modifyLyrics(vector<Song>& songs, const string& title, const string& newLyrics) {
    for (auto& s : songs) {
        if (s.title == title) {
            s.lyrics = newLyrics;
            saveDatabase(songs);
            cout << "Lyrics updated and saved.\n";
            return;
        }
    }
    cout << "Song not found.\n";
}

void displaySong(const vector<Song>& songs, const string& title) {
    for (const auto& s : songs) {
        if (s.title == title) {
            cout << "\n[" << s.title << "] - " << s.author << " (" << s.year << ")\n";
            cout << "--------------------------\n" << s.lyrics << "--------------------------\n";
            return;
        }
    }
    cout << "Song not found.\n";
}

void saveSongToFile(const vector<Song>& songs, const string& title, string filename) {
    if (filename.size() < 4 || filename.substr(filename.size() - 4) != ".txt") {
        filename += ".txt";
    }

    for (const auto& s : songs) {
        if (s.title == title) {
            ofstream f(filename);
            if (f.is_open()) {
                f << "Title: " << s.title << "\nAuthor: " << s.author << "\nYear: " << s.year << "\n\n" << s.lyrics;
                cout << "Exported to: " << filename << "\n";
            }
            else {
                cout << "Error: Could not create file.\n";
            }
            return;
        }
    }
    cout << "Song not found.\n";
}

void searchByAuthor(const vector<Song>& songs, const string& author) {
    bool found = false;
    cout << "Songs by " << author << ":\n";
    for (const auto& s : songs) {
        if (s.author == author) {
            cout << " - " << s.title << "\n";
            found = true;
        }
    }
    if (!found) cout << "No matches found.\n";
}

void searchByWord(const vector<Song>& songs, const string& word) {
    bool found = false;
    cout << "Songs containing '" << word << "':\n";
    for (const auto& s : songs) {
        if (s.lyrics.find(word) != string::npos) {
            cout << " - " << s.title << "\n";
            found = true;
        }
    }
    if (!found) cout << "No matches found.\n";
}

void saveDatabase(const vector<Song>& songs) {
    ofstream f(DB_NAME);
    if (!f.is_open()) return;
    for (const auto& s : songs) {
        f << s.title << "|" << s.author << "|" << s.year << "|" << s.lyrics.size() << "\n" << s.lyrics << "\n";
    }
}

void loadDatabase(vector<Song>& songs) {
    ifstream f(DB_NAME);
    if (!f.is_open()) return;
    songs.clear();
    string line;
    while (getline(f, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        Song s;
        string lenStr;
        getline(ss, s.title, '|');
        getline(ss, s.author, '|');
        getline(ss, s.year, '|');
        getline(ss, lenStr);

        int lyricsLen = stoi(lenStr);
        s.lyrics.resize(lyricsLen);
        f.read(&s.lyrics[0], lyricsLen);
        f.ignore(numeric_limits<streamsize>::max(), '\n');
        songs.push_back(s);
    }
}

string readLyricsFromConsole() {
    string res, line;
    cout << "Enter text (type 'END' on a new line to finish):\n";
    while (getline(cin, line) && line != "END") {
        res += line + "\n";
    }
    return res;
}

string readLyricsFromFile(const string& filename) {
    ifstream f(filename);
    if (!f.is_open()) {
        cout << "Error: Could not open " << filename << "\n";
        return "";
    }
    stringstream ss;
    ss << f.rdbuf();
    return ss.str();
}