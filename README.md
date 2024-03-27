A one on one blackjack game between you and the shuffler.

The goal of the card game is for the player’s cards to total more than the dealer’s without going over a total of 21 (aka a “bust”). Non face-cards have the value shown on the card (i.e. 2-10) while Jacks, Queens, and Kings have a value of 10. Aces are special in that they have a value of 11 by default unless that value would cause the player to bust (i.e. have a total greater than 21) in which case the Ace may count as just 1.

Gameplay starts with the player who must decide whether to “stand” (not ask for another card) or “hit” (ask for another card in an attempt to get closer to a count of 21, or even hit 21 exactly). Thus, a player may stand on the two cards originally dealt him/her, or he/she may ask the dealer for additional cards, one at a time, until the player either decides to stand on the total (if it is 21 or under), or goes “bust” (if it is over 21). In the latter case, the player loses immediately and the game is OVER (i.e. the dealer need not play or take any cards).

In 21, ace cards can be counted as EITHER 11 or 1. The combination of an ace with another card is known as a “soft hand,” because the player can count the ace as a 1 or 11, and either draw cards or not. For example with a “soft 17” (e.g. an ace and a 6), the total is 7 or 17. While a count of 17 is a good hand, the player may wish to draw for a higher total. If the player draws a card that causes a bust by counting the ace as an 11, the player is allowed to count the ace as a 1 instead and continue playing by standing or hitting (asking the dealer for additional cards, one at a time). Going back to our example, if the player hits and receives a 5 (e.g. their hand contains an ace, 6, and 5), the player can now let their Ace be a 1 for a total of 12 and continue gameplay. If the player were to hit and receive a second ace, then it too can count as a 1. Thus, any ACE can be counted as either 11 or 1, whichever helps make the sum total of the player’s hand closer to 21 without going over. In your code, you should count an ACE as 11 unless doing so causes the sum to be over 21 in which case you can recalculate the sum, making the ACE worth 1. Again, if there are 2 or more aces in a hand, one of them can count as 11 while the others can be counted as 1 each.

If the player did not “bust” the dealer now plays. Her face-down card is turned up. If the total is 17 or more, the dealer must stand. If the total is 16 or under, the dealer must take a card. She must continue to take cards until the total is 17 or more, at which point the dealer must stand. If the dealer has an ace, and counting it as 11 would bring her total to 17 or more (but not over 21), she must count the ace as 11 and stand. The dealer’s decisions, then, are automatic (prescribed) on all plays, whereas the player has always has choice, taking zero or more cards.
