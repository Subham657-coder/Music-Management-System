#ifndef MUSIC_FUNCTIONS_H
#define MUSIC_FUNCTIONS_H

#include <string>
using namespace std;

struct SongNode {
    string name;
    SongNode* next;
    SongNode(string songName);
};

struct StackNode {
    string songName;
    StackNode* next;
    StackNode(string name);
};


void insertSong(SongNode*& head, string songName);
void displaySongs(SongNode* head);
bool songExists(SongNode* head, string name);
void displayPlaylist(SongNode* head);
void push(StackNode*& top, string songName);
void displayRecentlyPlayed(StackNode* top);
void playSong(SongNode* songList, const string& songName, const string& songFolder, StackNode*& recentlyPlayed);
void searchSong(SongNode* songList, const string& path, StackNode*& recentlyPlayed);


#endif