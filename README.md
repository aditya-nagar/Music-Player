# C++ Music Player

A simple console-based music player application implemented in C++ using a doubly linked list data structure.

## Features

- Add songs to a playlist with title, artist, and duration information
- Display the current playlist
- Play the current song
- Navigate to next and previous songs
- Remove songs from the playlist
- Circular navigation (loops back to beginning/end of playlist)

## Implementation Details

The application is built using the following classes:

### Song
Stores information about a song:
- Title
- Artist
- Duration (in seconds)

### Node
Represents a node in the doubly linked list:
- Contains a Song pointer
- Has pointers to the next and previous nodes

### LinkedList
Implements the doubly linked list data structure:
- Maintains head, tail, and current pointers
- Provides methods for adding, removing, and navigating through songs

### MusicPlayer
Provides a user interface to interact with the playlist:
- Wraps the LinkedList functionality
- Handles user commands for playing and managing songs

## Installation

### Prerequisites
- C++ compiler (GCC, Clang, MSVC, etc.)
- Basic knowledge of terminal/command prompt usage

### Windows
1. Install a C++ compiler like MinGW or Visual Studio
2. Open Command Prompt or PowerShell
3. Navigate to the directory containing the source code
4. Compile the program:
