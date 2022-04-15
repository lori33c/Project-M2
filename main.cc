#include <iostream>
#include <string>
#include <vector>
#include "cpputils/graphics/image.h"
#include "opponent.h"
#include "player.h"

int main() {
  // Input Filenames
  std::string player_image_file;
  std::string opponent_image_file;
  std::string player_projectile_file;
  std::string opponent_projectile_file;

  // Prompt user to input file names
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
  Player goodCat(400, 300);
  goodCat.SetFile(player_image_file);
  goodCat.Draw(gameScreen);
  Opponent evilCat(200, 300);
  evilCat.SetFile(opponent_image_file);
  evilCat.Draw(gameScreen);
  PlayerProjectile PlaProj(300, 200);
  PlaProj.SetFile(player_projectile_file);
  PlaProj.Draw(gameScreen);
  OpponentProjectile OppProj(500, 400);
  OppProj.SetFile(opponent_projectile_file);
  OppProj.Draw(gameScreen);
  gameScreen.ShowUntilClosed();
  return 0;
}
