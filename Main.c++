#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

int main() {
    // Define colors and numbers
    std::vector<std::string> colors = {"red", "green", "blue", "yellow"};
    std::vector<int> numbers;
    for (int i = 1; i <= 13; i++) {
        numbers.push_back(i);
    }

    // Initialize an empty vector to hold the cards
    std::vector<std::pair<std::string, int>> cards;

    // Generate cards with two of each color and number combination
    for (const auto& color : colors) {
        for (const auto& number : numbers) {
            cards.push_back(std::make_pair(color, number));
            cards.push_back(std::make_pair(color, number));
        }
    }

    // Add two Joker cards without any color or number
    cards.push_back(std::make_pair("Joker", 0));
    cards.push_back(std::make_pair("Joker", 0));

    // Shuffle the cards to get a random arrangement
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(cards.begin(), cards.end(), g);

    // Display all randomized cards
    std::cout << "Randomized Cards:" << std::endl;
    int i = 0;
    for (const auto& card : cards) {
        std::cout << ++i << ")";
        
            std::cout << card.first << " - " << card.second << std::endl;
        
    }
    std::cout << std::endl;

    // Define players
    std::vector<std::vector<std::pair<std::string, int>>> players(4);

    // Distribute cards to players in the specified sequence
    int currentIndex = 0;
    int playerIndex = 0;
    std::vector<int> sequence = {3, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
    for (int count : sequence) {
        for (int j = 0; j < count; ++j) {
            players[playerIndex].push_back(cards[currentIndex]);
            ++currentIndex;
            if (currentIndex >= cards.size()) {
                break;
            }
        }
        playerIndex = (playerIndex + 1) % 4;
    }

    // Display each player's cards
    for (size_t j = 0; j < players.size(); ++j) {
        std::cout << "Player " << (j + 1) << " Cards:" << std::endl;
        int a=1;
        for (const auto& card : players[j]) {
            if (card.first == "Joker") {
                std::cout <<a++<< ")Joker" << std::endl;
            } else {
                std::cout <<a++<<")"<< card.first << " - " << card.second << std::endl;
            }
        }
        std::cout << std::endl;
    }

    // Display the remaining cards
    std::cout << "Remaining Cards:" << std::endl;
    for (size_t j = currentIndex; j < cards.size(); ++j) {
        if (cards[j].first == "Joker") {
            std::cout << j<<")"<< "Joker" << std::endl;
        } else {
            std::cout << j<<")"<<cards[j].first << " - " << cards[j].second << std::endl;
        }
    }

    return 0;
}