#include "music_functions.h"
#include <iostream>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

// Struct Constructors
SongNode::SongNode(string songName) {
    name = songName;
    next = nullptr;
}
StackNode::StackNode(string name) {
    songName = name;
    next = nullptr;
}

// Function: Insert a song at the end of the list
void insertSong(SongNode*& head, string songName) {
    SongNode* newNode = new SongNode(songName);
    if (head == nullptr) {
        head = newNode;
        return;
    }

    SongNode* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function: Display songs in the list
void displaySongs(SongNode* head) {
    if (head == nullptr) {
        cout << "No songs available.\n";
        return;
    }

    cout << "\nSongs available in folder:\n";
    SongNode* temp = head;
    while (temp != nullptr) {
        cout << "- " << temp->name << endl;
        temp = temp->next;
    }
}

// Function: Check if song exists in list
bool songExists(SongNode* head, string name) {
    SongNode* temp = head;
    while (temp != nullptr) {
        if (temp->name == name)
            return true;
        temp = temp->next;
    }
    return false;
}

// Function: Display playlist
void displayPlaylist(SongNode* head) {
    if (head == nullptr) {
        cout << "Playlist is empty.\n";
        return;
    }

    cout << "\nYour Playlist:\n";
    SongNode* temp = head;
    while (temp != nullptr) {
        cout << "- " << temp->name << endl;
        temp = temp->next;
    }
}

// Function: Push song to Recently Played (stack)
void push(StackNode*& top, string songName) {
    StackNode* newNode = new StackNode(songName);
    newNode->next = top;
    top = newNode;
}

// Function: Display Recently Played Stack
void displayRecentlyPlayed(StackNode* top) {
    if (top == nullptr) {
        cout << "Recently Played stack is empty.\n";
        return;
    }

    cout << "\nRecently Played Songs:\n";
    StackNode* temp = top;
    while (temp != nullptr) {
        cout << "- " << temp->songName << endl;
        temp = temp->next;
    }
}

// Function: Play a song and push to Recently Played
void playSong(SongNode* songList, const string& songName, const string& songFolder, StackNode*& recentlyPlayed) {
    SongNode* temp = songList;
    while (temp != nullptr) {
        if (temp->name == songName) {
            string fullPath = "start \"\" \"" + songFolder + "\\" + songName + "\"";
            system(fullPath.c_str());
            cout << "🎵 Now playing: " << songName << endl;

            push(recentlyPlayed, songName);
            return;
        }
        temp = temp->next;
    }

    cout << "Song not found in list.\n";
}
void searchSong(SongNode* songList, const string& path, StackNode*& recentlyPlayed) {
    string songName;
    cout << "Enter the name of the song to search: ";
    getline(cin, songName);

    if (songExists(songList,songName)) {
        cout << "Song found:" << songName << endl;
        char choice;
        cout << "Do you want to play it? (y/n): ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            playSong(songList, songName, path, recentlyPlayed);
        } else {
            cout << "Okay, not playing the song.\n";
        }
    } else {
        cout << "Song '" << songName << "' not found in the list.\n";
    }
}
