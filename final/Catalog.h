#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#ifndef CATALOG_H
#define CATALOG_H

struct Song {
    std::string title;
    std::string author;
    std::string year;
    std::string lyrics;
};

void addSong(std::vector<Song>& songs, const Song& song);
void deleteSong(std::vector<Song>& songs, const std::string& title);
void modifyLyrics(std::vector<Song>& songs, const std::string& title, const std::string& newLyrics);
void displaySong(const std::vector<Song>& songs, const std::string& title);
void saveSongToFile(const std::vector<Song>& songs, const std::string& title, std::string filename);
void searchByAuthor(const std::vector<Song>& songs, const std::string& author);
void searchByWord(const std::vector<Song>& songs, const std::string& word);

void saveDatabase(const std::vector<Song>& songs);
void loadDatabase(std::vector<Song>& songs);

std::string readLyricsFromConsole();
std::string readLyricsFromFile(const std::string& filename);

#endif