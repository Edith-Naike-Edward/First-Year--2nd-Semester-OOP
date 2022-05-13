#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Session {
    private:
    string sessionName;

    public:
    int numberOfRounds = 0;
    int numberOfPlayers = 0;
    Session() = default;
    Session(string name, int num);
    void init();
    int sessionNumber();
    void save();

};

Session::Session(string name, int num) {
    this->sessionName = name;
    this->numberOfPlayers = num;
}

// initialization of key information regarding the game session
void Session::init() {
    cout<<"Welcome to the Game ..."<<endl;
    cout<<"[+] Assign a name to the Session : ";
    getline(cin, this->sessionName);
    cout<<"[+] Enter the number of players : ";
    cin>>numberOfPlayers;
    cout<<"\n[*] Here We Go !!!\n"<<endl;
}

// retrieve last session number and increment by 1
int Session::sessionNumber() {
    FILE* fp = fopen("track.txt", "r");
    if (fp == NULL) {
        cout<<"[!] An error occurred . Terminating game ..."<<endl;
        exit(0);
    }
    int lastSession;
    fscanf(fp, "%d", &lastSession);
    return lastSession + 1;
}

// save information regarding the game session to a file
void Session::save() {

}


class Round : public Session {
    private:
    int answer;
    int playerNumber;

    public:
    Round(Session);
    void init(int);
    void end(Session);
};

// increment number of rounds in the session instance
Round::Round(Session s) {
    s.numberOfRounds += 1;
}

// generate and store the random number in a variable for reference as well as initialize players
void Round::init(int num) {
    this->playerNumber = num;
    srand((unsigned) time(NULL));
    this->answer = 1 + (rand() % 100);
}

// actions on ending of the round when certain conditions are met
void Round::end(Session s) {
    string fileName = to_string(s.sessionNumber());
    int len = fileName.size();
    char *fName;
    for(int i = 0; i < len; i++) {
        fName[i] = fileName[i];
    }
    FILE* fp = fopen(fName, "a");
    fprintf(fp, "%s %d", "Round", s.numberOfRounds);
}

class Player {
    public:
    int points;
    bool isCorrect = false;

    public:
    friend class Round;
};

int main() {
    string name;
    int num;
    cout<<"Welcome to the Game ..."<<endl;
    cout<<"[+] Assign a name to the Session : ";
    getline(cin, name);
    cout<<"[+] Enter the number of players : ";
    cin>>num;
    Session s(name, num);

    initRound:
    Round r(s);
    r.init(num);
    Player *players = new Player[num];
    for(int i = 0; i < num; i++) {
        if (players[i].isCorrect) {
            break;
        }
    }

    s.save();

    return 0;
}
