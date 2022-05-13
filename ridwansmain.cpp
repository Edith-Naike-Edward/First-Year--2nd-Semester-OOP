//  Assignment 3!
//  Created by Farhan Ridhwan on 17/04/2022.

#include <iostream>
#include <string.h>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <random>
using namespace std;

// Global variables!
int minimum = 1, maximum = 100;

int no_of_players;



class gameSession
{
protected:
    string name;
    int Random,guessed,R1points,variance,R2points,total;
    
public:
    void singlePlayer();
    void multiplayer2();
    void multiplayer3();
    
};

void gameSession :: singlePlayer()
{
    fstream Players; // creating a file!
    
    cout << "\n\n\t\t WHAT WOULD YOU LIKE TO NAME THIS SESSION :: "; cin >> name;
    
    Players.open("score " + name + ".txt",ios::app); // opening the file
    
    system("clear"); // In some OS the correct format is system("cls") so the likely message is 'TERM variable not set'
    
    cout << "\n\n\t\tSESSION " << name <<endl;
   
    cout << "\n\n\t\tPRINCIPLE OF THE GAME" << endl;
    cout << "This Game Has 2 Rounds: Each round a random number is generated(1-100) in which a player guesses \n If A Player Makes A Correct guess then another round begins and you are awarded points.\n Press ENTER to continue...";
    
    getchar();
    system("clear"); // In some OS the correct format is system("cls") so the likely message is 'TERM variable not set'
    
    srand((unsigned) time(NULL)); // setting the seed so that each program run has a different random number!
    
    Random = minimum + (rand() % ( maximum - minimum + 1 ) );
    
    cout << "\n\n\n\t\t FIRST ROUND " << endl;
    
    
    cout << "\n\t\t\t PLAYER 1\n\n Enter the number guessed:: "; cin >> guessed;
    
    Players <<"Round 1 \n Guessed::  "<< guessed;
    
    variance = guessed - Random ;
    if (variance == 0)
    {
        R1points = 10;
        cout << R1points <<"points"<<endl;
        cout <<"random no:: " << Random << endl;
    }
    else if(variance<=3 && variance > 0)
    {
        R1points = 7;
        cout << R1points <<"points"<<endl;
        cout <<"random no:: " << Random << endl;
    }
    else if (variance <= 5 && variance > 3)
    {
        R1points = 5;
        cout << R1points <<"points"<<endl;
        cout <<"random no:: " << Random << endl;
    }
    else if(variance<=10 && variance > 5)
    {
        R1points = 2;
        cout << R1points <<"points"<<endl;
        cout <<"random no:: " << Random << endl;
    }
    else
    {
        R1points = 0;
        cout << R1points <<"points"<<endl;
        cout <<"random no:: " << Random << endl;
    }
    
    
    system("clear"); // In some OS the correct format is system("cls") so the likely message is 'TERM variable not set'
    cout << "\n\n\n\t\t SECOND ROUND " << endl;
    
    
    cout << "\n\t\t\t PLAYER 1\n\n Enter the number guessed:: ";cin >> guessed;
    Players <<"\n\nRound 2 \n Guessed::  "<< guessed;
    
    variance = guessed - Random ;
    if (variance == 0)
    {
        R2points = 10;
        cout << R2points <<"points"<<endl;
        cout <<"random no:: " << Random << endl;
    }
    else if(variance<=3 && variance > 0)
    {
        R2points = 7;
        cout << R2points <<"points"<<endl;
        cout <<"random no:: " << Random << endl;
    }
    else if (variance <= 5 && variance > 3)
    {
        R2points = 5;
        cout << R2points <<"points"<<endl;
        cout <<"random no:: " << Random << endl;
    }
    else if(variance<=10 && variance > 5)
    {
        R2points = 2;
        cout << R2points <<"points"<<endl;
        cout <<"random no:: " << Random << endl;
    }
    else
    {
        R2points = 0;
        cout << R2points <<"points"<<endl;
        cout <<"random no:: " << Random << endl;
    }
    
    total = R1points + R2points;
    
    cout << "TOTAL POINTS = " << total <<endl;
    
    // saving to file!
    
  
    
    Players << "\tTOTAL: " << total;
    
    Players.close(); // closing the file!
    
}

void gameSession::multiplayer2()
{
    fstream Players; // Creating file!
    
    cout << "\n\n\t\t WHAT WOULD YOU LIKE TO NAME THIS SESSION :: "; cin >> name;
    
    Players.open("score " + name + ".txt",ios::app); // Opening File! the '+' is for string concatenation!
    
    system("clear"); // In some OS the correct format is system("cls") so the likely message is 'TERM variable not set'
    
    cout << "\n\n\t\tSESSION " << name <<endl;
    cout << "\n\n\t\tPRINCIPLE OF THE GAME" << endl;
    cout << "This Game Has 2 Rounds: Each round a random number is generated(1-100) in which a player guesses \n If A Player Makes A Correct guess then another round begins and you are awarded points.If all players make guesses then a new round begins regardless of the players making correct guesses.\n\n Press ENTER to continue...";
    getchar();
    
    system("clear"); // In some OS the correct format is system("cls") so the likely message is 'TERM variable not set'
    cout << "\n\n\nFIRST ROUND\n\n Press ENTER to continue..." << endl;
    getchar();
    
    system("clear");
    
    srand((unsigned) time(NULL));
    Random = minimum + (rand() % ( maximum - minimum + 1 ) );
    
    for (int i = 0; i < 2; i++)
    {
        cout << "\n\t\t\t PLAYER " << i+1 << "\n\n Enter the number guessed:: ";cin >> guessed;
        
        Players <<"Round 1 \n PLAYER "<<  i+1 << "\nGuessed: "<< guessed;
        
        variance = guessed - Random ;
        
        // setting conditions for point allocation!
        if (variance == 0)
        {
            R1points = 10;
            cout << R1points <<"points"<<endl;
            cout <<"random no:: " << Random << endl;
        }
        else if(variance <= 3 && variance > 0)
        {
            R1points = 7;
            cout << R1points <<"points"<<endl;
            cout <<"random no:: " << Random << endl;
        }
        else if (variance <= 5 && variance > 3)
        {
            R1points = 5;
            cout << R1points <<"points"<<endl;
            cout <<"random no:: " << Random << endl;
        }
        else if(variance <= 10 && variance > 5)
        {
            R1points = 2;
            cout << R1points <<"points"<<endl;
            cout <<"random no:: " << Random << endl;
        }
        else
        {
            R1points = 0;
            cout << R1points <<"points"<<endl;
            cout <<"random no:: " << Random << endl;
        }
        
        
    }
    
    system("clear");
    cout << "\n\n\n\t\t\tSECOND ROUND \n\n Press ENTER to continue..." << endl;
    getchar();
    
    system("clear"); // In some OS the correct format is system("cls") so the likely message is 'TERM variable not set'
    
    srand((unsigned) time(NULL));
    Random = minimum + (rand() % ( maximum - minimum + 1 ) );
    
    for (int i = 0; i < 2; i++)
    {
        cout << "\n\t\t\t PLAYER " << i+1 << "\n\n Enter the number guessed:: ";cin >> guessed;
        
        Players <<"\nRound 2 \n PLAYER "<<  i+1 << "\nGuessed:: "<< guessed;
        
        variance = guessed - Random ;
        if (variance == 0)
        {
            R2points = 10;
            cout << R2points <<"points"<<endl;
            cout <<"random no:: " << Random << endl;
        }
        else if(variance <= 3 && variance > 0)
        {
            R2points = 7;
            cout << R2points <<"points"<<endl;
            cout <<"random no:: " << Random << endl;
        }
        else if (variance <= 5 && variance > 3)
        {
            R2points = 5;
            cout << R2points <<"points"<<endl;
            cout <<"random no:: " << Random << endl;
        }
        else if(variance<=10 && variance > 5)
        {
            R2points = 2;
            cout << R2points <<"points"<<endl;
            cout <<"random no:: " << Random << endl;
        }
        else
        {
            R2points = 0;
            cout << R2points <<"points"<<endl;
            cout <<"random no:: " << Random << endl;
        }
        
    }
    total = R1points + R2points;
    
    cout << "\n\nTOTAL POINTS =  " << total <<endl;
    
   
    
    Players << "\tTOTAL:: "<< total;
    
    Players.close();
}

void gameSession::multiplayer3()
{
    
    cout << "\n\n\t\t WHAT WOULD YOU LIKE TO NAME THIS SESSION :: "; cin >> name;
    
    system("clear"); // In some OS the correct format is system("cls") so the likely message is 'TERM variable not set'
    
    fstream Players;
    
    Players.open("score " + name + ".txt",ios::app);
    
    cout << "\n\n\t\tSESSION " << name <<endl;
    cout << "\n\n\t\tPRINCIPLE OF THE GAME" << endl;
    cout << "This Game Has 2 Rounds: Each round a random number is generated(1-100) in which a player guesses \n If A Player Makes A Correct guess then another round begins and you are awarded points.If all players make guesses then a new round begins regardless of the players making correct guesses.\n\n Press ENTER to continue...";
    getchar();
    
    system("clear"); // In some OS the correct format is system("cls") so the likely message is 'TERM variable not set'
    cout << "\n\n\nFIRST ROUND\n\n Press ENTER to continue..." << endl;
    getchar();
    
    system("clear"); // In some OS the correct format is system("cls") so the likely message is 'TERM variable not set'
    
    for (int i = 0; i < 3; i++)
    {
        cout << "\n\t\t\t PLAYER" << i+1 << "\n\n Enter the number guessed:: ";cin >> guessed;
        Players <<"Round 1 \n PLAYER "<<  i+1 << "\nGuessed: "<< guessed;
        
        variance = guessed - Random ;
        if (variance == 0)
        {
            R1points = 10;
            cout << R1points <<"points"<<endl;
            cout <<"random no:: " << Random << endl;
        }
        else if(variance<=3 && variance > 0)
        {
            R1points = 7;
            cout << R1points <<"points"<<endl;
            cout <<"random no:: " << Random << endl;
        }
        else if (variance <= 5 && variance > 3)
        {
            R1points = 5;
            cout << R1points <<"points"<<endl;
            cout <<"random no:: " << Random << endl;
        }
        else if(variance<=10 && variance > 5)
        {
            R1points = 2;
            cout << R1points <<"points"<<endl;
            cout <<"random no:: " << Random << endl;
        }
        else
        {
            R1points = 0;
            cout << R1points <<"points"<<endl;
            cout <<"random no:: " << Random << endl;
        }
        
        
    }
   
    
    cout << "\n\n\nSECOND ROUND\n\n Press ENTER to continue..." << endl;
    getchar();
    
    system("clear"); // In some OS the correct format is system("cls") so the likely message is 'TERM variable not set'
  
    
    srand((unsigned) time(NULL));
    Random = minimum + (rand() % ( maximum - minimum + 1 ) );
    
    for (int i = 0; i < 3; i++)
    {
        cout << "\n\t\t\t PLAYER " << i+1 << "\n\n Enter the number guessed:: ";cin >> guessed;
        Players <<"\nRound 2 \n PLAYER "<<  i+1 << "\nGuessed: "<< guessed;
        variance = guessed - Random ;
        if (variance == 0)
        {
            R2points = 10;
            cout << R2points <<"points"<<endl;
            cout <<"random no:: " << Random << endl;
        }
        else if(variance <= 3 && variance > 0)
        {
            R2points = 7;
            cout << R2points <<"points"<<endl;
            cout <<"random no:: " << Random << endl;
        }
        else if (variance <= 5 && variance > 3)
        {
            R2points = 5;
            cout << R2points <<"points"<<endl;
            cout <<"random no:: " << Random << endl;
        }
        else if(variance<=10 && variance > 5)
        {
            R2points = 2;
            cout << R2points <<"points"<<endl;
            cout <<"random no:: " << Random << endl;
        }
        else
        {
            R2points = 0;
            cout << R2points <<"points"<<endl;
            cout <<"random no:: " << Random << endl;
        }
        
    }
    total = R1points + R2points;
    
    cout << "TOTAL POINTS = " << total <<endl;
    
   
    
    Players << "\tTOTAL:: "<< total;
    
    Players.close();
}


int main (void)
{
    gameSession frnd;
    
    cout << "\n\n\n\t\tWELCOME TO THE GUESS WIZARD" << endl;
    cout << "____________________________________________________________________________________" <<endl;
    
    cout << "\n\n\nPress ENTER to continue..." << endl;
    getchar();
    
    system("clear"); // In some OS the correct format is system("cls") so the likely message is 'TERM variable not set'
    
    
    cout << "\n\n\t\tCHOOSE THE MODE OF GUESS WIZARD\n\t" << endl;
    
    cout << "\t 1. SINGLE PLAYER\n\nMULTIPLAYER\n\t 2. 2 PLAYERS\n\t 3. 3 PLAYERS\n\n ENTER THE NUMBER OF THE MODE YOU WANT TO PLAY"<< endl; cin >> no_of_players;
    
    system("clear");
    if (no_of_players == 1)
    {
        frnd.singlePlayer();
        
    }
    else if (no_of_players == 2)
    {
        frnd.multiplayer2();
    }
    else if (no_of_players == 3)
    {
        frnd.multiplayer3();
    }
    else
    {
        cout << "GAME OVER !!! "<< endl;
    }
  
    system("clear"); // In some OS the correct format is system("cls") so the likely message is 'TERM variable not set'!
    cout << "\n\n\n\t\tCreated by Farhan Ridwan Abdullahi";
    
    

}
