#include <iostream>
#include <string>
#include <vector>
#include "cpputils/graphics/image.h"
#include "opponent.h"
#include "player.h"

int main() {
  // Filename Variables
  std::string player_image_file;
  std::string player_projectile_file;
  std::string opponent_projectile_file;

  // Create game screen
  graphics::Image gameScreen(800, 600);

  // Call each Draw member function and pass the game screen as argument
  Opponent evilCat(400, 300);
  evilCat.Draw(gameScreen);
  Player goodCat(400, 300);
  goodCat.Draw(gameScreen);
  OpponentProjectile OppProj(500, 400);
  OppProj.Draw(gameScreen);
  PlayerProjectile PlaProj(300, 200);
  PlaProj.Draw(gameScreen);
  gameScreen.ShowUntilClosed();
  return 0;
}
