/******************************************************************************
PIG DICE GAME

Jacob Castor

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

int ChooseGame(){
    int choice;
    cout << 
    " The game variations and rules are as follows:\n";
    
    cout <<
    "___________________________________________________________________________________________________\n" <<
    " TWO-DICE PIG - THIS VARIATION IS THE SAME AS PIG, EXCEPT:\n\n" <<
    "-Two standard dice are rolled. If neither shows a 1, their sum is added to the turn total.\n" <<
    "-If a single 1 is rolled, the player scores nothing and the turn ends.\n" <<
    "-If two 1s are rolled, the player’s entire score is lost, and the turn ends.\n";
    
    cout <<
    "___________________________________________________________________________________________________\n" <<
    " BIG PIG - THIS VARIATION IS THE SAME AS TWO DICE PIG, EXCEPT:\n\n" <<
    "-If two 1s are rolled, the player adds 25 to the turn total.\n" <<
    "-If other doubles are rolled, the player adds twice the value of the dice to the turn total.\n";                                   //Basic rules for variation games
    
    cout <<
    "___________________________________________________________________________________________________\n" <<
    " HOG - THIS VARIATION IS THE SAME AS PIG, EXCEPT: \n\n" <<
    "-At the beginning of a turn, the player decides *how many* dice to roll and rolls them all at once.\n" <<
    "-If any 1's (\"hogs\") are rolled, there is no score for the turn. \n Otherwise, the sum of the dice are scored.\n" <<
    "-In either case, it becomes the next player's turn.\n" <<
    "___________________________________________________________________________________________________\n";
    
    cout << 
    "\n\n\nPlease enter the number for the variation you want to play. [2 for \"TWO-DICE PIG\"][3 for \"BIG PIG\"][4 for \"HOG\"]\n";
    
    cin >> choice;                      //Takes the choice of the player and returns it to main to determine which game function to call
    
    return choice;
}



// numPlayers = 0 and classicOrVariation = q  and winnerFinal = 6 quits game 





int DiceRoll(){
    return (rand() % 6 + 1);                    // function to produce a random number for dice roll
}




// numPlayers = 0 and classicOrVariation = q  and winnerFinal = 6 quits game 




int ClassicPigGame(int numPlayers){             //function for classic pig game
    vector<int> sumPlayers(numPlayers);         //vector to hold player scores
    
    for(int i = 0; i < numPlayers; ++i){
        sumPlayers.at(i) = 0;                   //populates vector with zeros
    }
    
    int winner = 0;                             //if a player reaches 100, winner changes to a 1 and the loops break and the game ends
    int winNumber;                              //win number stors the number of the player that won
    int turnSum;
    
    
    while((winner != 1) && (winNumber != 6)){                         //While loop keeps game going until a player reaches 100 or until winNumber = 6 (quit condition)
    
        for(int i = 0; i < numPlayers; ++i){        //for loop cycles through players
            char rollDecision;                      //this variable stores the users decision to roll or quit the game
            turnSum = 0;
            cout << 
            "Player " << i + 1<< "\'s turn.\n" <<
            "Player " << i + 1<< "\'s total sum is: " << sumPlayers.at(i) << endl <<
            "Type q to quit, type h to hold and end turn, or type any other character/number to roll\n" <<
            "___________________________________________________________________________________________________\n\n\n";
            
            cin >> rollDecision;
        if(rollDecision == 'q'){
            winNumber = 6;// quits game
            break;
        } 
        
        else{
            while((rollDecision != 'h') && (sumPlayers.at(i) <= 100)){           //while loop keeps player turn going until a hold is decided or the player reaches 100
                int dieNumber = 0;
                dieNumber = DiceRoll();             //Stores a random number 1-6 
                cout <<
                "The number you rolled, Player " << i + 1 << ", is " << dieNumber << endl;
                
                if(dieNumber == 1){
                    cout <<                                                 // if a 1 is rolled, the player turn ends and the turn sum is not added to their score in the vector
                    "Sorry Player " << i + 1 << ", you rolled a 1 and your turn is over\n" <<
                    "*************************************************************************************************\n\n\n";
                    break;
                }
                else if(dieNumber != 1){
                    turnSum = turnSum + dieNumber;                      // if the dice roll returns a number 2-6, the number is added to the turn sum
                }
                
                
                cout <<
                "Player " << i + 1 << "\'s turn sum is: " << turnSum << endl <<
                "Player " << i + 1 << "\'s total sum before this turn is: " << sumPlayers.at(i)<< endl <<
                "Type q to quit, type h to hold and end turn, or type any other character/number to roll\n" <<
                "___________________________________________________________________________________________________\n\n\n";
                cin >> rollDecision;
                if(rollDecision == 'h' || turnSum >= 100){
                    sumPlayers.at(i) = turnSum + sumPlayers.at(i);                 //if the player decides to hold, their turn sum is added to the total sum in vector

                }
                
                else if(rollDecision == 'q'){
                    winNumber = 6;             // quits game
                    break;
                }
                
                if(sumPlayers.at(i) >= 100){                    //once a player reaches 100, the game loop breaks
                    winner = 1;
                    winNumber = i+1;                            //winNumber stores the number of the winning player and also breaks the loop to stop the game
                    break;
                }
            }
            
            if(winner == 1){        //quits game if somebody wins
                break;
            }
            else if(winNumber == 6){
                break;                  //quits game if somebody chooses quit option
            }
        }
        }
    }
    return winNumber;                   // returns the winning players number or 6 if the game was quit by user choice
}




// numPlayers = 0 and classicOrVariation = q  and winnerFinal = 6 quits game 


int TwoDicePigGame(int numPlayers){
    vector<int> sumPlayers(numPlayers);         //vector to hold player scores
    
    for(int i = 0; i < numPlayers; ++i){
        sumPlayers.at(i) = 0;                   //populates vector with zeros
    }
    
    int winner = 0;                             //if a player reaches 100, winner changes to a 1 and the loops break and the game ends
    int winNumber;                              //win number stors the number of the player that won
    int turnSum;
    
    
    while((winner != 1) && (winNumber != 6)){                         //While loop keeps game going until a player reaches 100
    
        for(int i = 0; i < numPlayers; ++i){        //for loop cycles through players
            char rollDecision;
            turnSum = 0;
            cout << 
            "\n\n\nPlayer " << i + 1<< "\'s turn.\n" <<
            "Player " << i + 1<< "\'s total sum is: " << sumPlayers.at(i) << endl <<
            "Type q to quit, type h to hold and end turn, or type any other character/number to roll\n" <<
            "___________________________________________________________________________________________________\n\n\n";
            
            cin >> rollDecision;
        if(rollDecision == 'q'){
            winNumber = 6;// quits game
            break;
        } 
        else{
            while((rollDecision != 'h') && ((sumPlayers.at(i)) <= 100)){           //while loop keeps player turn going until a hold is decided or the player reaches 100
                int dieNumber1 = 0;
                int dieNumber2 = 0;
                dieNumber1 = DiceRoll();
                dieNumber2 = DiceRoll();
                cout <<
                "The numbers you rolled, Player " << i + 1 << ", are " << dieNumber1 << " and " << dieNumber2 << endl;
                
                if((dieNumber1 == 1) || (dieNumber2 == 1)){
                    cout <<                                                 // if a 1 is rolled, the player turn ends and the turn sum is not added to their score in the vector
                    "Sorry Player " << i + 1 << ", you rolled a 1 and your turn is over\n" <<
                    "*************************************************************************************************\n\n\n";
                    break;
                }
                else if((dieNumber1 != 1) && (dieNumber2 != 1)){
                    turnSum = turnSum + dieNumber1 + dieNumber2;                      // if the dice rolls return numbers 2-6, the numbers are added to the turn sum
                }
                
                else if((dieNumber1 == 1) && (dieNumber2 == 1)){
                    cout <<                                                 // if a two 1s are rolled, the player turn ends and the total score is reset to zero
                    "Sorry Player " << i + 1 << ", you rolled two 1s and your turn is over along with your score being set to 0\n" <<
                    "*************************************************************************************************\n\n\n";
                    sumPlayers.at(i) = 0;
                    break;
                }
                
                
                cout <<
                "Player " << i + 1 << "\'s turn sum is: " << turnSum << endl <<
                "Player " << i + 1 << "\'s total sum before this turn is: " << sumPlayers.at(i)<< endl <<
                "Type q to quit, type h to hold and end turn, or type any other character/number to roll\n" <<
                "___________________________________________________________________________________________________\n\n\n";
                cin >> rollDecision;
                if(rollDecision == 'h' || turnSum >= 100){
                    sumPlayers.at(i) = turnSum + sumPlayers.at(i);                 //if the player decides to hold, their turn sum is added to the total sum in vector
                }
                
                else if(rollDecision == 'q'){
                    winNumber = 6;             // quits game
                    break;
                }
                
                if(sumPlayers.at(i) >= 100){                    //once a player reaches 100, the game loop breaks
                    winner = 1;
                    winNumber = i+1;                            //winNumber stores the number of the winning player and also breaks the loop to stop the game
                    break;
                }
            }
            
            if(winner == 1){
                break;
            }
            else if(rollDecision == 'q'){
                winNumber = 6;
                break;
            }
        }
        }
    if(winNumber == 6){
        break;
    }
    }
    return winNumber;

}




// numPlayers = 0 and classicOrVariation = q  and winnerFinal = 6 quits game 



int BigPigGame(int numPlayers){
    vector<int> sumPlayers(numPlayers);         //vector to hold player scores
    
    for(int i = 0; i < numPlayers; ++i){
        sumPlayers.at(i) = 0;                   //populates vector with zeros
    }
    
    int winner = 0;                             //if a player reaches 100, winner changes to a 1 and the loops break and the game ends
    int winNumber;                              //win number stors the number of the player that won
    int turnSum;
    
    
    while((winner != 1) && (winNumber != 6)){                         //While loop keeps game going until a player reaches 100
    
        for(int i = 0; i < numPlayers; ++i){        //for loop cycles through players
            char rollDecision;
            turnSum = 0;
            cout << 
            "\n\n\nPlayer " << i + 1<< "\'s turn.\n" <<
            "Player " << i + 1<< "\'s total sum is: " << sumPlayers.at(i) << endl <<
            "Type q to quit, type h to hold and end turn, or type any other character/number to roll\n" <<
            "___________________________________________________________________________________________________\n\n\n";
            
            cin >> rollDecision;
        if(rollDecision == 'q'){
            winNumber = 6;// quits game
            break;
        } 
        else{
            while((rollDecision != 'h') && ((sumPlayers.at(i)) <= 100)){           //while loop keeps player turn going until a hold is decided or the player reaches 100
                int dieNumber1 = 0;
                int dieNumber2 = 0;
                dieNumber1 = DiceRoll();
                dieNumber2 = DiceRoll();
                cout <<
                "The numbers you rolled, Player " << i + 1 << ", are " << dieNumber1 << " and " << dieNumber2 << endl; 
                
                if((dieNumber1 == 1) || (dieNumber2 == 1)){
                    cout <<                                                 // if a 1 is rolled, the player turn ends and the turn sum is not added to their score in the vector
                    "Sorry Player " << i + 1 << ", you rolled a 1 and your turn is over\n" <<
                    "*************************************************************************************************\n\n\n";
                    break;
                }
                else if(((dieNumber1 != 1) && (dieNumber2 != 1)) && (dieNumber1 != dieNumber2)){
                    turnSum = turnSum + dieNumber1 + dieNumber2;                      // if the dice rolls return numbers 2-6, the number is added to the turn sum if the numbers arent the same
                }
                
                else if((dieNumber1 == 1) && (dieNumber2 == 1)){
                    cout <<                                                 // if a two 1s are rolled, the player gains 25 to turn sum
                    "Player " << i + 1 << ", you rolled two 1s so you get +25 added to turn sum\n";
                    turnSum = turnSum + 25;
                }
                
                else if(dieNumber1 == dieNumber2){                          //if the same number is rolled on both dice, twice the value of the dice is added to turn total
                    turnSum = turnSum + ((dieNumber1 + dieNumber2) * 2);
                }

                cout <<
                "Player " << i + 1 << "\'s turn sum is: " << turnSum << endl <<
                "Player " << i + 1 << "\'s total sum before this turn is: " << sumPlayers.at(i)<< endl <<
                "Type q to quit, type h to hold and end turn, or type any other character/number to roll\n" <<
                "___________________________________________________________________________________________________\n\n\n";
                cin >> rollDecision;
                if(rollDecision == 'h' || turnSum >= 100){
                    sumPlayers.at(i) = turnSum + sumPlayers.at(i);                 //if the player decides to hold, their turn sum is added to the total sum in vector
                }
                
                else if(rollDecision == 'q'){
                    winNumber = 6;             // quits game
                    break;
                }
                
                if(sumPlayers.at(i) >= 100){                    //once a player reaches 100, the game loop breaks
                    winner = 1;
                    winNumber = i+1;                            //winNumber stores the number of the winning player and also breaks the loop to stop the game
                    break;
                }
            }
            
            if(winner == 1){
                break;
            }
            else if(rollDecision == 'q'){
                winNumber = 6;
                break;
            }
        }
        }
    if(winNumber == 6){
        break;
    }
    }
    return winNumber;

}



// numPlayers = 0 and classicOrVariation = q  and winnerFinal = 6 quits game 



int HogGame(int numPlayers){
    vector<int> sumPlayers(numPlayers); //vector to hold player scores
    vector<int> diceRolls;              // vector to hold values of the dice rolls
    
    for(int i = 0; i < numPlayers; ++i){
        sumPlayers.at(i) = 0;                   //populates player score vector with zeros
    }
    
    int winner = 0;                             //if a player reaches 100, winner changes to a 1 and the loops break and the game ends
    int winNumber;                              //win number stors the number of the player that won
    int turnSum;
    int numDice;

    
    
    while((winner != 1) && (winNumber != 6)){                         //While loop keeps game going until a player reaches 100
    
        for(int i = 0; i < numPlayers; ++i){        //for loop cycles through players
            char rollDecision;
            turnSum = 0;
            int rolledOne = 0;
            cout << 
            "Player " << i + 1<< "\'s turn.\n" <<
            "Player " << i + 1<< "\'s total sum is: " << sumPlayers.at(i) << endl <<
            "Please type r to choose the number of dice to roll or type q to quit:\n" <<
            "___________________________________________________________________________________________________\n\n\n";
            
            
            cin >> rollDecision;
        if(rollDecision == 'q'){
            winNumber = 6;// quits game
            break;
        } 
        else if(rollDecision == 'r'){
            cout <<                                 //prompts user to enter the amount of dice they would like to roll
            "Please enter the number of dice you would like to roll, Player " << i + 1 << ": \n";
            
            cin >> numDice;
            
            diceRolls.resize(numDice);    //resizes the dice vector based on how many dice the user wants to roll
            
            for(int j = 0; j < (diceRolls.size()); ++j){
                diceRolls.at(j) = DiceRoll();                //stores dice roll numbers in diceRolls vector
            }
            
            cout <<
            "The rolls for player " << i + 1 << " are as follows:\n";
            
            for(int j = 0; j < (diceRolls.size()); ++j){
                cout <<
                diceRolls.at(j) << ", ";                   //outputs dice roll numbers
                
                turnSum = turnSum + diceRolls.at(j);       //adds all dice rolls together
                
                if(diceRolls.at(j) == 1){
                    rolledOne = 1;                          // checks to see if a one was rolled
                }
            }
            cout << endl << endl;
            
            if(rolledOne == 1){                 //if a one is rolled, the turn is over and no score is added
                cout <<
                "Sorry Player " << i + 1 << ", you rolled a one and your turn is over\n\n\n";
            }
            else if(rolledOne == 0){
                sumPlayers.at(i) = turnSum + sumPlayers.at(i);     //if no ones are rolled, the sum of the dice is added to the player score vector and the next players turn begins
                
                cout <<
                "No ones were rolled, Player " << i + 1 << ". Your turn sum is: " << turnSum << " and is now added to your total score.\n\n";
                
                if(sumPlayers.at(i) >= 100){
                    winner = 1;
                    winNumber = i + 1;              //breaks game loop if a player wins
                    break;
                }
            }
        }
    }
    }
    return winNumber;
}



// numPlayers = 0 and classicOrVariation = q  and winnerFinal = 6 quits game 

int main(){
    
    srand(time(0));     // seed for dice roll function

    char classicOrVariation;
    int gameChoice;
    int numPlayers;
    vector<string> players();
    int winnerFinal;
    
    cout << 
    "****************************************************************************************************" << endl <<
    "* '||''|.   ||             '||''|.    ||                      ..|'''.|                             *" << endl <<
    "*  ||   || ...    ... .     ||   ||  ...    ....    ....     .|'     '   ....   .. .. ..     ....  *" << endl <<
    "*  ||...|'  ||   || ||      ||    ||  ||  .|   '' .|...||    ||    .... '' .||   || || ||  .|...|| *" << endl <<
    "*  ||       ||    |''       ||    ||  ||  ||      ||         '|.    ||  .|' ||   || || ||  ||      *" << endl <<
    "* .||.     .||.  '||||.    .||...|'  .||.  '|...'  '|...'     ''|...'|  '|..'|' .|| || ||.  '|...' *" << endl <<
    "*               .|....'                                                                            *" << endl << 
    "****************************************************************************************************" << endl;

    cout <<
            "______________________________________________________________________________________________________________________________\n" <<
            "                                                   CLASSIC PIG RULES\n\n" <<
            "-2 to 4 players race to reach 100 points.\n" <<
            "-Each turn, a player repeatedly rolls a die until either a 1 is rolled or the player holds and\n scores the sum of the rolls\n" <<
            "-At any time during a player's turn, the player is faced with two decisions:\n" <<
            "   * roll - If the player rolls a\n" <<
            "        - 1: the player scores nothing and it becomes the opponent's turn.\n" <<
            "        - 2 to 6: the number is added to the player's turn total and the player's turn continues.\n" <<
            "   * hold - The turn total is added to the player's score and it becomes the opponent's turn.\n" <<
            "_____________________________________________________________________________________________________________________________\n";
    
    cout << 
    "Please enter the number of players [2-4]. Type 0 to quit:\n";
    cin >> numPlayers;
    while( numPlayers != 2 && numPlayers != 3 && numPlayers !=4){
        if((numPlayers > 1)&&(numPlayers < 5)){
            break;
        }
        else if(numPlayers == 0){
            cout << "Goodbye\n";                                        // decides number of players with valid parameters based on game rules
            return 0;
        }
        else{
            cout << "Incorrect number of players, please try again:\n";
            cin >> numPlayers;
        }
    }

// numPlayers = 0 and classicOrVariation = q  and winnerFinal = 6 quits game   

    //this section guides the user through picking the game variation they would like to play
    if(numPlayers != 0){    
        while(classicOrVariation != 'q'){
            cout <<
            "Do you want to play classic Pig or a variation? [Type c for classic and v for variation or q to quit]:\n";
            cin >> classicOrVariation;
    
            if(classicOrVariation == 'c'){
                cout <<
                "\n\nYou have selected classic Pig.\n\n";               //since rules for classic pig are displayed at the beginning, selecting "c" automatically starts the game
                
                gameChoice = 1;
                winnerFinal = ClassicPigGame(numPlayers);
                break;
            }
            else if(classicOrVariation == 'v'){
                cout <<
                "\n\nYou have selected to play a variation of pig.\n" <<
                "___________________________________________________________________________________________________\n\n\n\n";
                
                do{
                gameChoice = ChooseGame();
                
                    if(gameChoice == 2){
                    winnerFinal = TwoDicePigGame(numPlayers);
                    }
                    else if(gameChoice == 3){
                    winnerFinal = BigPigGame(numPlayers);               //launches correct game based on user choice from variation screen
                    }
                    else if(gameChoice == 4){
                    winnerFinal = HogGame(numPlayers);
                    }
                    else{
                        cout << "Invalid input, please try again.\n\n";
                    }
                    
                    break;
                    
                }while((gameChoice != 2) && (gameChoice != 3) && (gameChoice != 4));
            }
            else if(classicOrVariation == 'q'){
                winnerFinal = 6;                          //provides option to quit
                break;
            }
            else{
                cout <<
                "Input error, please enter a correct statement.\n";     //error message for incorrect input
            }
        
        }
    }
    else{ 
        cout << "Goodbye\n";  //menu quit conditon
    }
    if(winnerFinal == 6){
        cout << "Goodbye\n";        //game quit conditon
    }
    else if((numPlayers != 0) && (classicOrVariation != 'q') && (winnerFinal != 6)){
        cout << "WINNER IS PLAYER " << winnerFinal;     //outputs the winner 
    }
    else if(winnerFinal == 6){
        cout << "Goodbye\n";   // prints goodbye if a user quit is determined
    }
    
return 0;
}

