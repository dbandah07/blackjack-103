/*******************************************************************************
 * CS 103 PR1 Twenty-One (Blackjack) Project
/******************************************************************************/

// Add other #includes if you need
#include <iostream>
#include <cstdlib>

using namespace std;

/* Prototypes */
void shuffle(int cards[]);
void printCard(int id);
int cardValue(int id);
void printHand(int hand[], int numCards);
int getBestScore(int hand[], int numCards);

const int NUM_CARDS = 52;

/**
 * Global arrays to be used as look-up tables. You 
 */
 // ♥, ♠, ♦, ♣
const char* suit[4] = {"\U00002665","\U00002660","\U00002666","\U00002663"}; // H, S, D, C
const char* type[13] = 
  {"2","3","4","5","6","7",
   "8","9","10","J","Q","K","A"};
const int value[13] = {2,3,4,5,6,7,8,9,10,10,10,10,11};

/**
 * Should permute the deck of cards, effectively shuffling it.
 * You must use the Fisher-Yates / Durstenfeld shuffle algorithm
 *  described in the assignment writeup.
 */
void shuffle(int cards[])
{
  /******** You complete ****************/
  /* 
  To shuffle an array a of n elements (indices 0..n-1):
  for i from n−1 downto 1 do
  j ← random integer such that 0 ≤ j ≤ i
      (i.e. use a modulus operation on the random number)
  exchange a[j] and a[i]
  */

  for (int i = NUM_CARDS - 1; i > 0; i--) {
    int j = rand() % (i + 1); // 0 <= j <= i

    // exchange:
    int temp = cards[i];
    cards[i] = cards[j];
    cards[j] = temp;
  }


}

/**
 * Prints the card in a "pretty" format:   "type-suit"
 *  Examples:  K-C  (King of clubs), 2-H (2 of hearts)
 *  Valid Types are: 2,3,4,5,6,7,8,9,10,J,Q,K,A
 *  Valid Suits are: H, D, C, S
 *
 *  Must use the suit and type arrays to lookup
 *   the appropriate characters to print.
 */
void printCard(int id)
{
  /******** You complete ****************/

 int cardSuit = id / 13; // there are 13 cards in each suit
 int cardType = id % 13;     // there are 4 types

 cout << type[cardType] << suit[cardSuit];
//  cout << "DEBUG id = " << id << "Type = " << type[id%13] << "Suit =" << suit[id/13] << endl; 
 // if (id < 0 || id >= NUM_CARDS) {
 //   return;
 // }
  

 // cout << type[(id%13) - 2] << suit[(id/13) +3];

}

/**
 * Returns the numeric value of the card.
 *  Should return 11 for an ACE and can then
 *  be adjusted externally based on the sum of the score.
 *
 * Must use the values array to lookup the appropriate
 *  card return value.
 */
int cardValue(int id)
{
  /******** You complete ****************/
  //   const int value[13] = {2,3,4,5,6,7,8,9,10,10,10,10,11};
  // if (id < 0 || id >= NUM_CARDS) {
  //   return -1;
  // }
  
//  int cardVal = id % 13;
  return value[id % 13];
}

/**
 * Should print out each card in the hand separated by a space and
 * then print a newline at the end.  
 * Should use printCard() to print out each card.
 */
void printHand(int hand[], int numCards)
{
  /******** You complete ****************/
  for (int i = 0; i < numCards; i++) {
  //  cout << "DEBUG: printing card = " << hand[i] << endl;
    printCard(hand[i]);
    cout << " ";
  }
  cout << endl;

}

/**
 * Should return the total score of the provided hand.  
 * ACES should be treated as 11s to make the highest possible hand
 *  and only being reduced to 1s as needed to avoid busting.
 */
int getBestScore(int hand[], int numCards)
{
  /******** You complete ****************/
  // REMEMBER ACE CAN = 1 if (pscore + ace[value: 11] > 21);
  int score = 0;
  int ace = 0;
  
  for (int i = 0; i < numCards; i++) {
    score += cardValue(hand[i]);

    if (cardValue(hand[i]) == 11) {
      ace++;
    }
  }

  while (score > 21 && ace > 0) {
    score -= 10; 
    ace--;
  }
  return score;
}

/**
 * Main program logic for the game of 21
 */
int main(int argc, char* argv[])
{
  //---------------------------------------
  // Do not change this code -- Begin
  //---------------------------------------
  if(argc < 2){
    cout << "Error - Please provide the seed value." << endl;
    return 1;
  }
  // g++ fault.cpp -o fault

  int seed = atoi(argv[1]);
  srand(seed);

  int cards[52];
  int dhand[9];
  int phand[9];
  //---------------------------------------
  // Do not change this code -- End
  //---------------------------------------

  /******** You complete ****************/

  // CHECKING SHUFFLE
 // for (int i = 0; i < NUM_CARDS; i++) {
 //   cards[i] = i;
 // }

  // shuffle(cards);


  
  //g++ -o program twentyone.cpp
  //./twentyone 37 */

  /* CHECKING PRINT:
  for (int i = 0; i < NUM_CARDS; i++) {
    printCard(i);
  } */
  
  /* CHECKING CARD VALUE:
  for (int i = 0; i < NUM_CARDS; i++) {
    cout << cardValue(i) << endl;
  }
  */
  
  /* CHECKING HAND:
  int hand[5] =  {0, 12, 3, 5, 8};
  printHand(hand, 5);
  */
  
  // intialize deck:


  





  char yn = 'y';

  while (yn == 'y') {
    for (int i = 0; i < NUM_CARDS; i++) {
      cards[i] = i;
    }
    
    shuffle(cards);


  // cout << "Shuffled Deck: ";
  // for (int i = 0; i < NUM_CARDS; i++ ) {
  //   cout << cards[i] << " ";
  // }
    
    int pCount = 0; // number in player's hand // CHANGED FROM 2,2,4
    int dCount = 0; // number in dealer's hand
    
    int cardCount = 0; // deck index

    int pScore = 0; // player score
    int dScore = 0; // dealer score
    
    
    char pChoice = 'h'; // whether or not will be playing again


  //  cout << "Shuffled Deck: ";
  //  for (int i = 0; i < NUM_CARDS; i++ ) {
  //    cout << cards[i] << " ";
  //  }
  //  cout << endl;


    // give player + dealer the first two cards
    phand[0] = cards[0];
    dhand[0] = cards[1];

    phand[1] = cards[2];
    dhand[1] = cards[3];
    
    cardCount = 4;
    pCount = 2;
    dCount = 2;
    dScore = getBestScore(dhand, dCount);

  //  cout << "DEBUG: dhand[0]" << dhand[0] << "dhand[1]" << dhand[1] << endl;
  //  cout << "DEBUG: phand[0]" << phand[0] << "phand[1]" << phand[1] << endl;


    cout << "Dealer: ? ";
    printCard(dhand[1]);
    cout << endl;
    
    cout << "Player: ";
    printHand(phand, pCount);

    // PLAYER TURN:
    while (pChoice == 'h' && getBestScore(phand, pCount) < 21) {    
      cout << "Type 'h' to hit and 's' to stay:" << endl;
      cin >> pChoice;

      if (pChoice == 'h') {
        // Player takes hit:

        phand[pCount] = cards[cardCount];
        pCount++;
        cardCount++;

        // Printing player cards:
        cout << "Player: ";
        printHand(phand, pCount);
        
        // Player score:
        pScore = getBestScore(phand, pCount); 
          
          if (pScore > 21) {
            cout << "Player busts" << endl; 
            
            cout << "Lose " << pScore << " " << getBestScore(dhand, dCount) << endl;
            
            break; 
          }
      }

      else if (pChoice == 's') {
        // stand, move to dealers turn;
        break;
      }
    }

  pScore = getBestScore(phand, pCount);
  if (pScore <= 21) {
    cout << "Dealer: ";
    dScore = getBestScore(dhand, dCount);
    while (dScore < 17) {
     
      dhand[dCount] = cards[cardCount];
      dCount++;
      cardCount++;

      dScore = getBestScore(dhand, dCount);
    }
    
    printHand(dhand, dCount);

    // Get score of player and dealer:
  //  pScore = getBestScore(phand, pCount);
  //  dScore = getBestScore(dhand, dCount);

    // Compare:
      if(dScore > 21){
        cout << "Dealer busts" << endl;
        cout << "Win " << pScore << " " << dScore << endl;

      }
      else if (pScore > dScore) {
        cout << "Win " << pScore << " " << dScore << endl;
      }
      else if (dScore > pScore) {
        cout << "Lose " << pScore << " " << dScore << endl;
      }
      else {
        cout << "Tie " << pScore << " " << dScore << endl;
      }
    }
  
    cout << endl << "Play again? [y/n]" << endl;
    cin >> yn;

    if (yn == 'n') {
      break;
    }
    else if (yn != 'y') {
      break; 
    }

  }
  return 0;
}
