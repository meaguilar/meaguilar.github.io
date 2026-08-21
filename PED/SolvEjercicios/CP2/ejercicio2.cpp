#include <iostream>
#include <vector>
using namespace std;

struct Song
{
    string name;
    string artist;
    int duration; // in seconds
    int replays;
    float revenue_per_replay;
    float total_revenue;
};

vector<Song> allSongs;

int main()
{
    int option = 0;
    while (option != 4)
    {
        cout << "Welcome to the Music Manager!" << endl
             << "1. Add Song" << endl
             << "2. Show All Songs" << endl
             << "3. Total Revenue" << endl
             << "4. Exit" << endl;
        cin >> option;

        switch (option)
        {
        case 1:
        {
            cout << "Enter song name: ";
            string name;
            cin >> name;
            cout << "Enter artist name: ";
            string artist;
            cin >> artist;
            cout << "Enter duration (in seconds): ";
            int duration;
            cin >> duration;
            cout << "Enter revenue per replay: ";
            float revenue_per_replay;
            cin >> revenue_per_replay;

            allSongs.push_back(createSong(name, artist, duration, revenue_per_replay));
            break;
        }
        case 2:
            showAllSongs(allSongs);
            break;
        case 3:
            cout << "Total Revenue: $" << totalRevenue(allSongs) << endl;
            break;
        case 4:
            cout << "Exiting the program." << endl;
            break;
        default:
            break;
        }
    }
    return 0;
}

Song createSong(string name, string artist, int duration, float revenue_per_replay)
{
    Song newSong;
    newSong.name = name;
    newSong.artist = artist;
    newSong.duration = duration;
    newSong.replays = 0;
    newSong.revenue_per_replay = revenue_per_replay;
    newSong.total_revenue = 0.0f;
    return newSong;
}

float totalRevenue(vector<Song> playlist)
{
    float total = 0.0f;
    for (auto song : playlist)
    { // cada canción se copia
        total += song.total_revenue;
    }
    return total;
}

void showAllSongs(vector<Song> playlist)
{
    for (auto song : playlist)
    { // cada canción se copia
        cout << "Name: " << song.name << ", Artist: " << song.artist
             << ", Duration: " << song.duration << "s, Replays: " << song.replays
             << ", Revenue per Replay: $" << song.revenue_per_replay
             << ", Total Revenue: $" << song.total_revenue << endl;
    }
}
