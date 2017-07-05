#include "player.hpp"
#include <iostream>
#include <string>
void Player::init(std::string name, Player::Role role) {
  m_name = name;
  m_role = role;
}
Player::Role Player::role() const {
  return m_role;
}
void Player::answer() const {
  std::string s_role = "";
  switch(role()) {
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
  std::cout << m_name << ": Shh... I am a " << s_role <<"." << std::endl;
}
void Player::pretend() const {
  std::cout << m_name << ": I am the villager!!" << std::endl;
}
Player::Player() {
  m_role = Role::Uninitialized;
  m_name = "";
}
Player::~Player() {
  m_role = Role::Uninitialized;
  m_name = "";
}