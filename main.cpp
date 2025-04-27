#include <iostream>
#include <filesystem>
#include "music_functions.h"
using namespace std;
namespace fs = std::filesystem;

int main() {
    string path = "C:\\Users\\ansup\\OneDrive\\Desktop\\Songs";  // update this
    SongNode* songList = nullptr;
    StackNode* recentlyPlayed = nullptr;



    for (const auto& entry : fs::directory_iterator(path)) {
        string filename = entry.path().filename().string();
        insertSong(songList, filename);
    }

    displaySongs(songList);
    int choice;
    string songName;
    SongNode* playlist = nullptr;

    do {
        cout << "\n====== Music Management Menu ======\n";
        cout << "1. Display All Songs in the folder\n";
        cout << "2. Add Song to Playlist\n";
        cout << "3. Display Playlist\n";
        cout << "4. Play a Song\n";
        cout << "5. Recently Played Songs\n";
        cout << "6. Search and Play Song\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // To handle getline after cin

        switch (choice) {
            case 1:
                displaySongs(songList);
                break;
            case 2:
                cout << "Enter song name to add to playlist: ";
                getline(cin, songName);
                if (songExists(songList, songName)) {
                    insertSong(playlist, songName);
                    cout << "Hurray! Song added to playlist!\nListen it according to your mood:)\n";
                } else {
                    cout << "Song not found in main list.\nWe will soon add new songs\n";
                }
                break;
            case 3:
                displayPlaylist(playlist);
                break;
            case 4:
                cout << "Enter song name to play: ";
                getline(cin, songName);
                playSong(songList, songName, path,recentlyPlayed);  // path = your song folder
                break;
            case 5:
                displayRecentlyPlayed(recentlyPlayed);
                break;
            case 6:
                searchSong(songList, path, recentlyPlayed);
                break; 
            case 0:
                cout << "Exiting. Thank you!\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);
    return 0;
}
