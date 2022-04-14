#include <iostream>
#include <string>
#include <vector>
#include "cpputils/graphics/image.h"
#include "opponent.h"
#include "player.h"

int main() {
  // Create game screen
  graphics::Image gameScreen(800, 600);

  // Call each Draw member function and pass the game screen as argument
  Player goodCat(400, 300);
  goodCat.Draw(gameScreen);
  Opponent evilCat(200, 300);
  evilCat.Draw(gameScreen);
  PlayerProjectile PlaProj(300, 200);
  PlaProj.Draw(gameScreen);
  OpponentProjectile OppProj(500, 400);
  OppProj.Draw(gameScreen);
  gameScreen.ShowUntilClosed();
  return 0;
}
