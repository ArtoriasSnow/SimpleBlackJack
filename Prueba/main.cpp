//
//  main.cpp
//  Prueba
//
//  Created by Avantgarde on 8/6/17.
//  Copyright © 2017 Avantgarde. All rights reserved.
//

#include <iostream>
#include <ctime>
using namespace std;


int randomNumber;

int yourCards[5];
int enemyCards[5];

int nextPlayerCardPosition;
int nextEnemyCardPosition;

int playerFinalScore;
int enemyFinalScore;


void InitGame(){
    
    nextPlayerCardPosition = 0;
    nextEnemyCardPosition = 0;
    
    playerFinalScore = 0;
    enemyFinalScore = 0;
    
}


int GetRandomNumber(){

        return (rand()%12)+1;
}

void KeepCard(int card, int position, int deck[5]){
    
    deck[position] = card;
    
}

int CheckDeckScore(int deck[5], int final_score){
    
    int arrayLenght = sizeof(deck)/sizeof(deck[0]);
    
    
    for (int i = 0; i < arrayLenght; i++){
        
        final_score += deck[i];
        
    }
    
    return final_score;
    
}

bool EnemyDecision(){
    
    int number = GetRandomNumber();
    
    if(number % 2 == 0){
        
        return true;
    }
    
    return false;
}



void PlayerTurn(){

    string response = "";
    cout << "Do you want a card? y/n";
    cin >> response;
    
    if(response == "y"){
    
        KeepCard(GetRandomNumber(), nextPlayerCardPosition, yourCards);
        
    }
    
    nextPlayerCardPosition += 1;
    
}

void EnemyTurn(){
    
    cout << "It's time to enemy turn! \n";
    
    int score = CheckDeckScore(enemyCards, enemyFinalScore);
    
    if(score >= 21){
    
        cout << "Enemy doesn't want more cards";
    }else if(score > 17 && score < 21){
    
        //We are going to "simulate" a simple IA for the enemy
        if(EnemyDecision()){
        
            cout << "Enemy wants a card more";
            KeepCard(GetRandomNumber(), nextEnemyCardPosition, enemyCards);
        }else {
        
            cout << "Enemty doesn't want more cards";
        }
        
    }else{
    
        cout << "Enemy wants a card more";
        KeepCard(GetRandomNumber(), nextEnemyCardPosition, enemyCards);
        
    }
    
    nextEnemyCardPosition += 1;

    
}





void GameOver(){

    if(playerFinalScore > 21){
    
        cout << "Sorry, you lose. To much points!\n";
    }else if(playerFinalScore > enemyFinalScore){
    
        cout << "You win!";
    }
}





void PrintDeck(int deck[5]){

    int arrayLenght = sizeof(deck)/sizeof(deck[0]);
    
    for (int i = 0; i < arrayLenght; i++){
        
        cout << deck[i] << "\n";
        
    }
    
}






int main(int argc, const char * argv[]) {
    
    //This is necesary to generate "pseudo-truly" random numbers before the loop
    srand((unsigned)time(NULL));

    InitGame();
    
    for(int i = 0; i < 5; i++){
    
        PlayerTurn();
        EnemyTurn();
    }
    
    cout << "Enemy Score: \n";
    cout << CheckDeckScore(enemyCards, enemyFinalScore) << " points \n";
    cout << "Player Score: \n";
    cout << CheckDeckScore(yourCards, playerFinalScore) << " points \n";;
    GameOver();
    
    return 0;
}

