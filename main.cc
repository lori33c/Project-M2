#include <iostream>
#include <string>
#include <vector>
#include "cpputils/graphics/image.h"
#include "opponent.h"

int main() {
  // Create game screen
  graphics::Image gameScreen(800, 600);

  // Call each Draw member function and pass the game screen as argument
  Opponent evilCat(400, 300);
  evilCat.Draw(gameScreen);
  gameScreen.ShowUntilClosed();
  return 0;
}
