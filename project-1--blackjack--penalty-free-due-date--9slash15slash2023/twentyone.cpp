/*******************************************************************************
 * CS 103 Twenty-One (Blackjack) Project
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
const char suit[4] = {'H','S','D','C'};
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
  int n = NUM_CARDS;
  for (int i = 0; i < n; i++) //number each cards into cards[]
  {
    cards[i] = i;
  }
  for (int i = n-1; i > 0; i--) //swap function
  {
    int j = rand() % (i + 1); //random generator
    int temp = cards[i]; //exchange
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
  cout << type[id % 13] << "-" << suit[id / 13] << " ";
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
  for (int i = 0; i < numCards; i++)
  {
    printCard(hand[i]);
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
  int sum = 0; 
  int ace = 0;
  for (int i = 0; i < numCards; i++) //goes through each card
  {
    if (cardValue(hand[i]) == 11) //is card is an Ace
    {
      sum += 11; //add 11 to sum
      ace += 1; //add the amount of how much Ace's there are
    }
    else 
    {
      sum += cardValue(hand[i]); //add the card value to sum
    }
  }
  if (sum <= 21) //if the sum is less than 21 or 21, it is best score
  {
    return sum;
  }
  else
  {
    int j = 0;
    while (j < ace && (sum > 21)) //replaces ace's new value as 1, till the sum is lesser than 21
    {
      sum -= 10; //-11+1
      j++; //only till the amount of Ace's presented in the array
    }
    return sum;
  }
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
  int seed = atoi(argv[1]);
  srand(seed);

  int cards[52];
  int dhand[9];
  int phand[9];
  //---------------------------------------
  // Do not change this code -- End
  //---------------------------------------

  /******** You complete ****************/
  for (int i = 0; i < 9; i++) //only nine cards available to each player
  {
    dhand[i] = 0; //set everything to 0
    phand[i] = 0; //to get rid of garbage values
  }

  bool game = true;
  while (game) //continues if player responses 'y'
  {
    shuffle(cards);
    phand[0] = cards[0]; //setting the cards to each player manually, by alternating
    dhand[0] = cards[1];
    phand[1] = cards[2];
    dhand[1] = cards[3];

    cout << "Dealer: ? ";
    printCard(dhand[1]);
    cout << endl;
    cout << "Player: "; printHand(phand, 2); 

    int p = 1; //phand[] most recent position
    int d = 1; //dhand[] most recent position
    int c = 3; //cards[] most recent position

    bool hs = true; 
    while (hs) //continues till player enters 's'
    {
      if (getBestScore(phand,2)==21) //when player receive 21 in the beginning
      {
        int p_sum = getBestScore(phand, 2); //output of 21
        int d_sum = getBestScore(dhand, d+1); //
        while (d_sum < 17) //if dealer's sum is less than 17, dealer eats card till it passes 17
        {
          c += 1; //add c so cards[] position moves to the next one
          d += 1; //dealer too
          dhand[d] = cards[c]; //dealer has a new card
          d_sum = getBestScore(dhand, d+1); //produce the new sum of dealer
        } 
        cout << "Dealer: "; printHand(dhand, d+1); 
        cout << "Win " << p_sum << " " << d_sum << endl;
        break;
      }
      else
      {
        cout << "Type 'h' to hit and 's' to stay: " << endl;
        char response = '-';
        cin >> response;
        if (response == 'h')
        {
          c += 1; //add c so cards[] position moves to the next one
          p += 1 ; //player too
          phand[p] = cards[c]; //player has a new card
          cout << "Player: "; printHand(phand, c-1); 
          int p_sum = getBestScore(phand, p+1); //find the sum of player's hand
          int d_sum = getBestScore(dhand, d+1); //find the sum of dealer's hand
          if (p_sum > 21) //if player's hand is more than 21-bust
          {
            cout << "Player busts" << endl;
            cout << "Lose " << p_sum << " " << d_sum << endl;
            hs = false; //leaves the while loop
          }
          else if (getBestScore(phand, p+1) == 21) //if player's hand equals to 21-wins immediately
          {
            while (d_sum < 17) //checks again if dealer's hand has sum less than 17
            {
              c += 1;
              d += 1;
              dhand[d] = cards[c];
              d_sum = getBestScore(dhand, d+1);
            } 
            cout << "Dealer: "; printHand(dhand, d+1);
            cout << "Win " << p_sum << " " << d_sum << endl;
            break; //leaves while loop
          }
          else if (d_sum > 21) //checks if dealer's sum is more than 21-bust
          {
            cout << "Dealer busts" << endl;
            cout << "Win " << p_sum << " " << d_sum << endl;
            hs = false;
          }
        }
        else if (response == 's')
        {
          int p_sum = getBestScore(phand, p+1);
          int d_sum = getBestScore(dhand, d+1); 
          while (d_sum <= 17) //checks again if dealer's hand has sum less than 17
          {
            c += 1; 
            d += 1;
            dhand[d] = cards[c]; //dealer has a new card
            d_sum = getBestScore(dhand, d+1); //renews dealer's card sum
          } 
          cout << "Dealer: "; printHand(dhand, d+1); //placed after while loop so that d_sum gets updated
          if (p_sum > 21) //if player's hand is more than 21-busts
          {
            cout << "Player busts" << endl;
            cout << "Lose " << p_sum << " " << d_sum << endl;
            hs = false;
          }
          else if (d_sum > 21) //if dealer's hand is more than 21-busts
          {
            cout << "Dealer busts" << endl;
            cout << "Win " << p_sum << " " << d_sum << endl;
            hs = false;
          }
          else if (p_sum > d_sum) //if player's sum is more than dealer's sum
          {
            cout << "Win " << p_sum << " " << d_sum << endl;
            hs = false;
          }
          else if (d_sum > p_sum) //if dealer's sum is more than player's sum
          {
            cout << "Lose " << p_sum << " " << d_sum << endl;
            hs = false;
          }
          else if (d_sum == p_sum) //tie
          {
            cout << "Tie " << p_sum << " " << d_sum << endl;
            hs = false;
          }
        }
      }
    }
    cout << endl << "Play again? [y/n]" << endl;
    char continueornot = '-';
    cin >> continueornot;
    if (continueornot == 'n') 
    {
      game = false; //cancels the first loop
    }
  }
  return 0;
}
