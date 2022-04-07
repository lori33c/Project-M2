#include <iostream>
#include <string>
#include <vector>
#include "cpputils/graphics/image.h"
#include "opponent.h"
#include "player.h"

int main() {
  // Filename Variables
  std::string player_image_file;
  std::string opponent_image_file;
  std::string player_projectile_file;
  std::string opponent_projectile_file;

  // Prompt the user to input file names
  std::cout << "Please provide player image filename: ";
  std::cin >> player_image_file;
  std::cout << "Please provide opponent image filename: ";
  std::cin >> opponent_image_file;
  std::cout << "Please provide player projectile image filename: ";
  std::cin >> player_projectile_file;
  std::cout << "Please provide opponent projectile image filename: ";
  std::cin >> opponent_projectile_file;  

  // Create game screen
  graphics::Image gameScreen(800, 600);

  // Call each Draw member function and pass the game screen as argument
  Opponent evilCat(400, 300);
  evilCat.Draw(gameScreen, opponent_image_file);
  Player goodCat(400, 300);
  goodCat.Draw(gameScreen, player_image_file);

  // gameScreen.ShowUntilClosed();
  return 0;
}
