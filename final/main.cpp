#include <iostream>
#include <limits>
#include "Catalog.h"

using namespace std;

int main() {
    vector<Song> mySongs;
    loadDatabase(mySongs);

    int choice;
    while (true) {
        cout << "\n=== Song Lyrics Catalog (" << mySongs.size() << " songs loaded) ===\n";
        cout << "1. Add Song\n2. Delete Song\n3. Edit Lyrics\n4. Display Song\n"
            << "5. Export to .txt File\n6. Search by Author\n7. Search by Word\n0. Exit\n-> ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 0) break;

        if (choice == 1) {
            Song s;
            cout << "Title: "; getline(cin, s.title);
            cout << "Author: "; getline(cin, s.author);
            cout << "Year: ";   getline(cin, s.year);
            int t = 0;
            while (t != 1 && t != 2) {
                cout << "Lyrics (1-Console, 2-File): ";
                if (!(cin >> t)) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); }
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (t == 1) s.lyrics = readLyricsFromConsole();
            else {
                string fn; cout << "Filename: "; getline(cin, fn);
                s.lyrics = readLyricsFromFile(fn);
            }
            addSong(mySongs, s);
        }
        else if (choice == 2) {
            string t; cout << "Title to delete: "; getline(cin, t);
            deleteSong(mySongs, t);
        }
        else if (choice == 3) {
            string t; cout << "Title: "; getline(cin, t);
            modifyLyrics(mySongs, t, readLyricsFromConsole());
        }
        else if (choice == 4) {
            string t; cout << "Title: "; getline(cin, t);
            displaySong(mySongs, t);
        }
        else if (choice == 5) {
            string t, f;
            cout << "Title: "; getline(cin, t);
            cout << "Filename (will add .txt if missing): "; getline(cin, f);
            saveSongToFile(mySongs, t, f);
        }
        else if (choice == 6) {
            string a; cout << "Author: "; getline(cin, a);
            searchByAuthor(mySongs, a);
        }
        else if (choice == 7) {
            string w; cout << "Search word: "; getline(cin, w);
            searchByWord(mySongs, w);
        }
    }
    return 0;
}