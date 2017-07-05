#include "card.hpp"
const char *Card::faceNames[Card::totalFaces] = {"Ace", "Deuce", "Three", "Four", "Five", "Six", 
                              "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
const char *Card::suitNames[Card::totalSuits] = {"Hearts", "Diamonds", "Clubs", "Spades"};
Card::Card(int cardFace, int cardSuit) {
  face = cardFace;
  suit =cardSuit;
}
std::string Card::toString() const {
  std::string result = "";
  result = result + faceNames[face] + " of " + suitNames[suit];
  return result;
}
int Card::getFace() const {
  return face;
}
int Card::getSuit() const {
  return suit;
}