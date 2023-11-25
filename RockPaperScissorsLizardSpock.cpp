/*
Troy Kubanka

This program allows user input to compete against the computer in Rock/Paper/Scissors
The user can choose between standard Rock/Paper/Scissors or in Rock/Paper/Scissors/Lizard/Spock
The computer is programmed to randomly choose its selection
Best of 5 wins
*/

#include <iostream>
#include <string>
using namespace std;
//prototypes
string compRoll_RPSLS(int options);
int userVScomp (string user, string computer);
void printWinner (bool Winner, string user, string computer, int userTot, int userComp);
void bestOf (int userTot, int compTot);
//main 
int main() 
{
   // main variables
   int game, options, userTot = 0, compTot = 0;
   bool Winner=false;   // added to eliminate warnings
   string user, computer;  
   // introduction and idiot-proofing
   cout << "Welcome to Rock, Paper, Scissors (Lizard, Spock?)! Best of 5 wins!" << endl 
        << "First, choose if you want to play against the computer in Rock, Paper, Scissors... or, in Rock, Paper, Scissors, Lizard, Spock." << endl;
   cout << endl << endl << "1: Rock, Paper, Scissors" << endl 
        << "2: Rock, Paper, Scissors, Lizard, Spock" << endl 
        << "3: ''How to play Rock, Paper, Scissors, Lizard, Spock?''" << endl;
   cin >> game;
   while(game != 1 && game !=  2 && game != 3)
   {
      cout << endl << "Error! please enter '1' to play Rock, Paper, Scissors; '2' to play Rock, Paper, Scissors, Lizard, Spock; or '3' to see how Rock, Paper, Scissors, Lizard, Spock plays out: ";
      cin >> game; 
   }
   if(game == 3)
   {
      cout << endl << "As legends told:" << endl 
           << "''Scissors cuts paper, paper covers rock, rock crushes lizard, lizard poisons Spock, Spock smashes scissors, scissors decapitates lizard, lizard eats paper, paper disproves Spock, Spock vaporizes rock, and as it always has, rock crushes scissors.'' ";
      cout << endl << endl << "1: Play Rock, Paper, Scissors" << endl
           << "2: Play Rock, Paper, Scissors, Lizard, Spock" << endl;
      cin >> game;
   }
   while(game != 1 && game != 2)
   {
      cout << "Error! PLease ENTER '1' to play Rock, Paper, Scissors, or ENTER '2' to play Rock, Paper, Scissors, Lizard, Spock: ";
      cin >> game;
   }

   //main loop for RPS
   if(game == 1)
   {
      while(compTot < 3 && userTot < 3)
      {
         cout << endl << "Choose your move ('ROCK', 'PAPER', or 'SCISSORS'): ";
         cin >> user;
         while(user != "ROCK" && user != "PAPER" && user != "SCISSORS")
         {
            cout << endl << "Error! Please choose 'ROCK', 'PAPER', or 'SCISSORS' in all capitals: ";
            cin >> user; 
         }
         options = 3;
         // function to calculate computer's move
         computer = compRoll_RPSLS(options);
         // comparing computer with user 
         while(computer == user)
         {
            cout << "Computer also chose " << computer << ", it's a draw!" << endl << endl << "Enter another move ('ROCK', 'PAPER', or 'SCISSORS'): ";
            cin >> user;
            while(user != "ROCK" && user != "PAPER" && user != "SCISSORS")
            {
               cout << endl << "Error! Please choose 'ROCK', 'PAPER', or 'SCISSORS' in all capitals: ";
               cin >> user;
            }
            computer = compRoll_RPSLS(options);  
         }
         Winner = userVScomp (user, computer);
         if(Winner == false)
         {
            compTot++;
         }
         else if(Winner == true)
         {
            userTot++;
         }
         printWinner (Winner, user, computer, userTot, compTot);
      }
   }

   // main loop for RPSLS
   else if(game == 2)
   {
      while(compTot < 3 && userTot < 3)
      {
         cout << endl << "Choose your move ('ROCK', 'PAPER', 'SCISSORS', 'LIZARD', or 'SPOCK'): ";
         cin >> user;
         while(user != "ROCK" && user != "PAPER" && user != "SCISSORS" && user != "LIZARD" && user != "SPOCK")
         {
            cout << endl << "Error! Please choose 'ROCK', 'PAPER', 'SCISSORS', 'LIZARD', or 'SPOCK' in all capitals: ";
            cin >> user; 
         }
         options = 5;
         // function to calculate computer's move
         computer = compRoll_RPSLS(options);
         // comparing computer with user
         while(computer == user)
         {
            cout << "Computer also chose " << computer << ", it's a draw!" << endl << endl << "Enter another move ('ROCK', 'PAPER', 'SCISSORS', 'LIZARD', or 'SPOCK'): ";
            cin >> user;
            while(user != "ROCK" && user != "PAPER" && user != "SCISSORS" && user != "LIZARD" && user != "SPOCK")
            {
               cout << "Error! please choose 'ROCK', 'PAPER', 'SCISSORS', 'LIZARD', or 'SPOCK' in all capitals: ";
               cin >> user; 
            }   
            computer = compRoll_RPSLS(options);
          }
          Winner = userVScomp (user, computer);
          if(Winner == false)
          {
             compTot++;
          }
          else if(Winner == true)
          {
             userTot++;
          }
          printWinner (Winner, user, computer, userTot, compTot); 
      }
   }
   // function that outputs once user or computer has won 3 games
   bestOf (compTot, userTot);
   return 0;
}

//function for computer's random number generator to use on Rock, Paper, Scissors, OR Rock, Paper, Scissors, Lizard, Spock
string compRoll_RPSLS(int options)
{
   int RPSLS; 
   string comp2;
   RPSLS = rand() % options + 1;
   if(RPSLS == 1)
   {
      comp2 = "ROCK";
   }
   else if(RPSLS == 2)
   {
      comp2 = "PAPER";
   }
   else if(RPSLS == 3)
   {
      comp2 = "SCISSORS";
   }
   else if(RPSLS == 4)
   {
      comp2 = "LIZARD";
   }
   else if(RPSLS == 5)
   {
      comp2 = "SPOCK";
   }
   return comp2;
}

//function to compare user move and computer move
int userVScomp (string user, string computer)
{
   bool winner;
   if(user == "ROCK")
   {
      if(computer == "SCISSORS")
      {
         winner = true;
      }
      else if(computer == "PAPER")
      {
         winner = false;
      }
      else if(computer == "LIZARD")
      {
         winner = true; 
      }
      else if(computer == "SPOCK")
      {
         winner = false;
      }
   }
   else if(user == "PAPER")
   {
      if(computer == "SCISSORS")
      {
         winner = false;
      }
      else if(computer == "ROCK")
      {
         winner = true;
      }
      else if(computer == "LIZARD")
      {
         winner = false;
      }
      else if(computer == "SPOCK")
      {
         winner = true;
      }
   }
   else if(user == "SCISSORS")
   {
      if(computer == "ROCK")
      {
         winner = false;
      }
      else if(computer == "PAPER")
      {
         winner = true;
      }
      else if(computer == "LIZARD")
      {
         winner = true;
      }
      else if(computer == "SPOCK")
      {
         winner = false; 
      }
   }
   else if(user == "LIZARD")
   {
      if(computer == "ROCK")
      {
         winner = false;
      }
      else if(computer == "PAPER")
      {
         winner = true;
      }
      else if(computer == "SCISSORS")
      {
         winner = false;
      }
      else if(computer == "SPOCK")
      {
         winner = true;
      }
   }
   else if(user == "SPOCK")
   {
      if(computer == "ROCK")
      {
         winner = true;
      }
      else if (computer == "PAPER")
      {
         winner = false;
      }
      else if(computer == "SCISSORS")
      {
         winner = true;
      }
      else if(computer == "LIZARD")
      {
         winner = false;
      }
   }     
   return winner;
}

//Print function that reveals the winner and current score. 
void printWinner(bool Winner, string user, string computer, int userTot, int compTot)
{
   if(Winner == true)
   {
      cout << "You chose " << user << " and the computer chose " << computer << ", you win!" << endl << "User: " << userTot << " win(s); Computer: " << compTot << " win(s)." << endl;
   }
   else if(Winner == false)
   {
      cout << "You chose " << user << " and the computer chose " << computer << ", computer wins!" << endl << "User: " << userTot << " win(s); Computer: " << compTot << " win(s)." << endl;
   }
}

//Print function once the user or computer wins 3 games
void bestOf (int userTot, int compTot)
{ 
   cout << endl << "Game Over!" << endl;                     
}


 
