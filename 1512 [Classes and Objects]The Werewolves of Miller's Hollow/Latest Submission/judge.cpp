#include "judge.hpp"
#include <iostream>
#include <string>
void Judge::on(const Player* player) {
  m_players[m_players_count++] = player;
}
void Judge::call(Player::Role role) {
  std::string s_role = "";
  switch(role) {
    case 1: 
      s_role = "Villager";
      break;
    case 2:
      s_role = "Werewolf";
      break;
    case 3:
      s_role = "Seer";
      break;
    case 4:
      s_role = "Witch";
      break;
    case 5:
      s_role = "Hunter";
      break;
    default:
      break;
  }
  std::cout << "Calling: " << s_role << std::endl;
  for (int index = 0; index < m_players_count; ++index) {
    if (role == Player::Villager) {
      m_players[index] -> pretend();
    } else if (m_players[index] -> role() == role) {
      m_players[index] -> answer();
    }
  }
}
Judge::Judge() {
  m_players_count = 0;
  for (auto &player : m_players) {
    player = nullptr;
  }
}
Judge::~Judge() {
  m_players_count = 0;
  for (auto &player : m_players) {
    player = nullptr;
  }
}
