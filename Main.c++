#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

class Player {
public:
    std::vector<std::pair<std::string, int>> board;
    Player(int numCards) : board(28, {"", -1}) {
        for (int i = 0; i < numCards; ++i) {
            board[i] = {"", 0};
        }
    }
    
    void placeCard(int position, std::pair<std::string, int> card) {
        if (position >= 0 && position < 28) {
            board[position] = card;
        }
    }
    
    void moveCard(int from, int to) {
        if (from >= 0 && from < 28 && to >= 0 && to < 28) {
            std::swap(board[from], board[to]);
        }
    }
    
    void displayBoard() {
        std::cout << "Board: \n";
        for (size_t i = 0; i < board.size(); ++i) {
            if (board[i].first != "") {
                std::cout << i + 1 << ") " << board[i].first << " - " << board[i].second << "\n";
            } else {
                std::cout << i + 1 << ") [Empty] \n";
            }
        }
    }
};

int main() {
    std::vector<std::string> colors = {"red", "green", "blue", "yellow"};
    std::vector<int> numbers;
    for (int i = 1; i <= 13; i++) numbers.push_back(i);

    std::vector<std::pair<std::string, int>> cards;
    for (const auto& color : colors) {
        for (int num : numbers) {
            cards.push_back({color, num});
            cards.push_back({color, num});
        }
    }
    cards.push_back({"Joker", 0});
    cards.push_back({"Joker", 0});

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(cards.begin(), cards.end(), g);

    std::vector<Player> players;
    players.emplace_back(15); // First player gets 15 cards
    for (int i = 1; i < 4; ++i) {
        players.emplace_back(14); // Other players get 14 cards
    }

    int currentIndex = 0;
    for (size_t i = 0; i < players.size(); ++i) {
        for (size_t j = 0; j < (i == 0 ? 15 : 14); ++j) {
            if (currentIndex < cards.size()) {
                players[i].placeCard(j, cards[currentIndex++]);
            }
        }
    }

    for (size_t i = 0; i < players.size(); ++i) {
        std::cout << "Player " << i + 1 << "\n";
        players[i].displayBoard();
    }
    
    std::cout << "Remaining Cards:\n";
    for (size_t i = currentIndex; i < cards.size(); ++i) {
        std::cout << cards[i].first << " - " << cards[i].second << "\n";
    }
    return 0;
}
