#include "deck-of-cards.hpp"
DeckOfCards::DeckOfCards() {
  currentCard = 0;
  while (moreCards()) {
    deck.push_back(dealCard());
  }
  currentCard = 0;
}
Card DeckOfCards::dealCard() {
  int face, suit;
  suit = currentCard / Card::totalFaces;
  face = currentCard % Card::totalFaces;
  ++currentCard;
  Card card(face, suit);
  return card;
}
bool DeckOfCards::moreCards() const {
  return currentCard != 52;
}