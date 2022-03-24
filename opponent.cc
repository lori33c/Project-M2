#include "opponent.h"
#include <string>

// Constructors
Opponent::Opponent() : x_(0), y_(0) {}
Opponent::Opponent(int x,int y) : x_(x), y_(y) {}

int Opponent::GetX() { return x_; }
int Opponent::GetY() { return y_; }
int Opponent::GetWidth() { return kWidth_; }
int Opponent::GetHeight() { return kHeight_; }

void Opponent::SetX(int x) { x_ = x; }
void Opponent::SetY(int y) { y_ = y; }

void Opponent::DrawOppImage(std::string opponent_image_file) {
  // 2. Create Opponent image (50 x 50 pixel)
  // 1. Create Opponent image (50 x 50 pixel)
  const int Opponent_size = 50;
  graphics::Image Opponent_image(Opponent_size, Opponent_size);

  // Draws the face
  Opponent_image.DrawCircle(Opponent_size / 2, Opponent_size / 2,
                            Opponent_size / 3, 0, 0, 0);
  Opponent_image.DrawPolygon({25, 20, 10, 5, 10, 30}, 0, 0, 0);
  Opponent_image.DrawPolygon({25, 20, 40, 5, 40, 30}, 0, 0, 0);

  // Draw the eyes
  Opponent_image.DrawCircle(18, 20, 2, 255, 0, 0);
  Opponent_image.DrawCircle(32, 20, 2, 255, 0, 0);

  // Draw mouth
  Opponent_image.DrawPolygon({25, 25, 20, 32, 30, 32}, 243, 0, 0);

  // Saves the Player image
  Opponent_image.SaveImageBmp(opponent_image_file);
}

void Opponent::Draw(graphics::Image& gameScreen) {
  // Pass by reference 
  // So any changes to image is reflected
  DrawOppImage("opponent.bmp");
  graphics::Image opponent;
  opponent.Load("opponent.bmp");

  //Draw Opponent on location of screen
  for (int i = 0; i < kWidth_; i++){
    for (int j = 0; j <kHeight_; j++) {
      // For each pixel in opponent_image, get the color
      graphics::Color color = opponent.GetColor(i,j);

      // Set the color of the pixel on the screen
      gameScreen.SetColor(x_ - kWidth_/2 + i, y_ - kHeight_/2 + j, color);
    }
  }
}
