#include "pch.h"
#include "../BlackJack/Game.cpp"
#include "../BlackJack/Hand.cpp" //this also includes the header
#include "../BlackJack/Deck.cpp"
#include "../BlackJack/House.cpp"
#include "../BlackJack/Player.cpp"
#include "../BlackJack/Round.cpp"



//declare objects below, and initialize in Test constructor
class HandTest : public ::testing::Test {
public:
    HandTest() : hand1_(), hand2_(), hand3_(),
        hand4_(), hand5_(), hand6_() {

        hand1_.add_card("10");
        hand1_.add_card("4");

        hand2_.add_card("8");
        hand2_.add_card("8");
        hand2_.add_card("8");

        hand3_.add_card("K");
        hand3_.add_card("Q");

        hand4_.add_card("J");
        hand4_.add_card("3");
        hand4_.add_card("10");

        hand5_.add_card("4");
        hand5_.add_card("A");

        hand6_.add_card("A");
        hand6_.add_card("A");
        hand6_.add_card("10");
        hand6_.add_card("10");
    };

protected:
    //number hands
    Hand hand1_;
    Hand hand2_;
    //includes face cards
    Hand hand3_;
    Hand hand4_;
    //include aces
    Hand hand5_;
    Hand hand6_;

};

//number cards
TEST_F(HandTest, CalculateNumberTest) {
    EXPECT_EQ(14, hand1_.calculate_hand());
    EXPECT_EQ(24, hand2_.calculate_hand());
    EXPECT_EQ(false, hand1_.bust());
    EXPECT_EQ(true, hand2_.bust());
}

//including face cards and number
TEST_F(HandTest, CalculateFaceTest) {
    EXPECT_EQ(20, hand3_.calculate_hand());
    EXPECT_EQ(23, hand4_.calculate_hand());
    EXPECT_EQ(false, hand3_.bust());
    EXPECT_EQ(true, hand4_.bust());
}

TEST_F(HandTest, SortHand) {

}

//method needs to add number/face cards before considering Aces!!!
TEST_F(HandTest, CalculateAceTest) {
    EXPECT_EQ(15, hand5_.calculate_hand());
    EXPECT_EQ(22, hand6_.calculate_hand());
    EXPECT_EQ(false, hand5_.bust());
    EXPECT_EQ(true, hand6_.bust());
}

class DeckTest : public ::testing::Test {
public:
    DeckTest() : deck1_(), deck2_(2), deck3_(4) {
        std::string dump;
        dump = deck2_.draw_card();
        dump = deck2_.draw_card();
        while (deck1_.size() > 0) {
            dump = deck1_.draw_card();
        }
    };

protected:
    Deck deck1_;
    Deck deck2_;
    Deck deck3_;
};

TEST_F(DeckTest, InitialDeckSize) {
    EXPECT_EQ(208, deck3_.size());
}

TEST_F(DeckTest, DrawCard) {
    EXPECT_EQ(102, deck2_.size());
}

TEST_F(DeckTest, EmptyDeck) {
    EXPECT_EQ(0, deck1_.size());
}


//testing next_move in House class
class HouseTesting : public ::testing::Test {
public:
    HouseTesting() : deck1_(1), deck2_(1), house1_(deck1_), house2_(deck2_) {};
protected:
    House house1_;
    House house2_;
    Deck deck1_;
    Deck deck2_;
};