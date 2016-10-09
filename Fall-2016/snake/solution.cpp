#include <bits/stdc++.h>

using namespace std;

enum hand_result { 
    nada, one_pair, two_pair, triple, straight, normal_flush, 
    full_house, quadruple, straight_flush, royal_flush 
};

map<string, int> card_ids = {
    {"2", 0}, {"3", 1}, {"4", 2}, {"5", 3}, {"6", 4}, {"7", 5}, {"8", 6},
    {"9", 7}, {"10", 8}, {"J", 9}, {"Q", 10}, {"K", 11}, {"A", 12},
};

map<char, int> suit_ids = {{'H', 0}, {'D', 1}, {'S', 2}, {'C', 3}};

bool hands[2][4][13];
int hand_numbers[2][13], hand_suits[2][4];

bool has_straight_ending_with(int player, int end_num) {
    bool result = true;
    for (int i = 0; i < 5; ++i)
        result &= (end_num - i == -1 ? hand_numbers[player][12] : hand_numbers[player][end_num - i]);
    return result;
}

bool has_any_straight(int player) {
    for (int i = 12; i > 2; --i)
        if (has_straight_ending_with(player, i))
            return true;
    return false;
}

bool has_flush(int player) {
    return hand_suits[player][0] == 5 || hand_suits[player][1] == 5 
        || hand_suits[player][2] == 5 || hand_suits[player][3] == 5;
}

bool has_n_num_counts(int player, int n, int count) {
    for (int i = 0; i < 13 && n; ++i)
        if (hand_numbers[player][i] == count)
            --n;
    return !n;
}

int break_tie(hand_result player1, hand_result player2) {
    bool player1_has_high = false, player2_has_high = false;
    if (player1 == straight || player1 == straight_flush) {
        if (has_straight_ending_with(0, 3) && !has_straight_ending_with(1, 3)) return 1;
        if (!has_straight_ending_with(0, 3) && has_straight_ending_with(1, 3)) return -1;
    }
    for (int x = 4; x > 0 && !player1_has_high && !player2_has_high; --x) {
        for (int i = 12; i > -1 && !player1_has_high && !player2_has_high; --i) {
            if (hand_numbers[0][i] == x && hand_numbers[1][i] != x) player1_has_high = true;
            if (hand_numbers[1][i] == x && hand_numbers[0][i] != x) player2_has_high = true;
        }
    }
    if (player2_has_high) return 1;
    if (player1_has_high) return -1;
    return 0;
}

hand_result get_hand_result(int player) {
    if (has_straight_ending_with(player, 12) && has_flush(player)) return royal_flush;
    if (has_any_straight(player) && has_flush(player)) return straight_flush;
    if (has_n_num_counts(player, 1, 4)) return quadruple;
    if (has_n_num_counts(player, 1, 3) && has_n_num_counts(player, 1, 2)) return full_house;
    if (has_flush(player)) return normal_flush;
    if (has_any_straight(player)) return straight;
    if (has_n_num_counts(player, 1, 3)) return triple;
    if (has_n_num_counts(player, 2, 2)) return two_pair;
    if (has_n_num_counts(player, 1, 2)) return one_pair;
    return nada;
}

int winning(hand_result player1, hand_result player2) {
    if (player1 == player2) return break_tie(player1, player2);
    return player2 > player1 ? 1 : -1;
}

pair<string, char> hands_input[2][5];

void set_hand_position(int player, int suit, int number, int change) {
    hands[player][suit][number] += change;
    hand_numbers[player][number] += change;
    hand_suits[player][suit] += change;
}

int main() {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> hands_input[i][j].first >> hands_input[i][j].second;
            set_hand_position(i, suit_ids[hands_input[i][j].second], card_ids[hands_input[i][j].first], 1);
        }
    }

    hand_result player1 = get_hand_result(0);
    hand_result player2 = get_hand_result(1);

    int winning_state = winning(player1, player2);

    for (int card = 0; card < 5; ++card) {
        set_hand_position(1, suit_ids[hands_input[1][card].second], card_ids[hands_input[1][card].first], -1);
        for (int suit = 0; suit < 4; ++suit) {
            for (int number = 0; number < 13; ++number) {
                if (!hands[0][suit][number] && !hands[1][suit][number]) {
                    set_hand_position(1, suit, number, 1);
                    winning_state = max(winning_state, winning(player1, get_hand_result(1)));
                    set_hand_position(1, suit, number, -1);
                }
            }
        }
        set_hand_position(1, suit_ids[hands_input[1][card].second], card_ids[hands_input[1][card].first], 1);
    }

    if (winning_state == 1) cout << "WIN\n";
    else if (winning_state == 0) cout << "TIE\n";
    else cout << "LOSE\n";
}
