#include <iostream>
#include <string>
#include <limits>

using namespace std;

class Song {
public:
    string title;
    string artist;
    int duration; // in seconds

    Song(string t, string a, int d) : title(t), artist(a), duration(d) {}
};

class Node {
public:
    Song* song;
    Node* next;
    Node* prev;

    Node(Song* s) : song(s), next(nullptr), prev(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    Node* current;

public:
    LinkedList() : head(nullptr), tail(nullptr), current(nullptr) {}

    void addSong(Song* song) {
        Node* newNode = new Node(song);
        if (!head) {
            head = tail = current = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void displayPlaylist() {
        Node* temp = head;
        int index = 1;
        while (temp) {
            cout << index << ". " << temp->song->title << " - " << temp->song->artist << " (" << temp->song->duration << "s)" << endl;
            temp = temp->next;
            index++;
        }
    }

    Song* getCurrentSong() {
        return current ? current->song : nullptr;
    }

    void nextSong() {
        if (current && current->next) {
            current = current->next;
        } else if (current && !current->next) {
            current = head; // Loop back to the beginning
        }
    }

    void prevSong() {
        if (current && current->prev) {
            current = current->prev;
        } else if (current && !current->prev) {
            current = tail; // Loop back to the end
        }
    }

    void removeSong(int index) {
        if (!head) return;

        Node* temp = head;
        for (int i = 1; i < index && temp; i++) {
            temp = temp->next;
        }

        if (!temp) return;

        if (temp == head) {
            head = head->next;
            if (head) head->prev = nullptr;
        } else if (temp == tail) {
            tail = tail->prev;
            if (tail) tail->next = nullptr;
        } else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }

        if (current == temp) {
            current = temp->next ? temp->next : head;
        }

        delete temp->song;
        delete temp;
    }
};

class MusicPlayer {
private:
    LinkedList playlist;

public:
    void addSong(string title, string artist, int duration) {
        Song* newSong = new Song(title, artist, duration);
        playlist.addSong(newSong);
    }

    void displayPlaylist() {
        playlist.displayPlaylist();
    }

    void playCurrent() {
        Song* currentSong = playlist.getCurrentSong();
        if (currentSong) {
            cout << "Now playing: " << currentSong->title << " - " << currentSong->artist << endl;
        } else {
            cout << "No song is currently playing." << endl;
        }
    }   

    

    void nextSong(){
        playlist.nextSong();
        playCurrent();
    }

    void prevSong() {
        playlist.prevSong();
        playCurrent();
    }

    void removeSong(int index) {
        playlist.removeSong(index);
    }
};

void displayMenu() {
    cout << "\n--- Music Player Menu ---" << endl;
    cout << "1. Add a song" << endl;
    cout << "2. Display playlist" << endl;
    cout << "3. Play current song" << endl;
    cout << "4. Play next song" << endl;
    cout << "5. Play previous song" << endl;
    cout << "6. Remove a song" << endl;
    cout << "7. Quit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    MusicPlayer player;
    int choice;

    while (true) {
        displayMenu();
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1: {
                string title, artist;
                int duration;
                cout << "Enter song title: ";
                getline(cin, title);
                cout << "Enter artist name: ";
                getline(cin, artist);
                cout << "Enter song duration (in seconds): ";
                cin >> duration;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                player.addSong(title, artist, duration);
                cout << "Song added successfully!" << endl;
                break;
            }
            case 2:
                cout << "\nCurrent Playlist:" << endl;
                player.displayPlaylist();
                break;
            case 3:
                player.playCurrent();
                break;
            case 4:
                player.nextSong();
                break;
            case 5:
                player.prevSong();
                break;
            case 6: {
                int index;
                cout << "Enter the index of the song to remove: ";
                cin >> index;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                player.removeSong(index);
                cout << "Song removed (if it existed)." << endl;
                break;
            }
            case 7:
                cout << "Thank you for using the Music Player. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
