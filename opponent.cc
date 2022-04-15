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
  std::string opponent_file = "opponent.bmp";
  
  DrawOppImage(opponent_file);
  graphics::Image Opponent;
  Opponent.Load(opponent_file);
  for (int i = 0; i < kWidth_; i++){
    for (int j = 0; j < kHeight_; j++){
      graphics::Color color = Opponent.GetColor(i,j);
      gameScreen.SetColor(x_ + i, y_ + j, color);
    }
  }
}

OpponentProjectile::OpponentProjectile() : x_(0), y_(0){}
OpponentProjectile::OpponentProjectile(int x, int y) {
  x_ = x;
  y_ = y;
}
void OpponentProjectile::SetX(int x) {x_ = x;}
void OpponentProjectile::SetY(int y) {y_ = y;}
int OpponentProjectile::GetX() {return x_;}
int OpponentProjectile::GetY() {return y_;}
int OpponentProjectile::GetWidth() { return kWidth_; }
int OpponentProjectile::GetHeight() { return kHeight_; }
void OpponentProjectile::DrawOppProjImage(std::string opponent_projectile_file) {
  const int OppProj_size = 5;
	graphics::Image OpponentProjectile_image(OppProj_size, OppProj_size);
	OpponentProjectile_image.DrawCircle(OppProj_size/2, OppProj_size/2, OppProj_size/2, 255, 0, 0);
	OpponentProjectile_image.SaveImageBmp(opponent_projectile_file);
}
void OpponentProjectile::Draw(graphics::Image& gameScreen) {
  std::string opponent_projectile_file = "opponentprojectile.bmp";
  
  DrawOppProjImage(opponent_projectile_file);
  graphics::Image OpponentProjectile;
  OpponentProjectile.Load(opponent_projectile_file);
  for (int i = 0; i < kWidth_; i++){
    for (int j = 0; j < kHeight_; j++){
      graphics::Color color = OpponentProjectile.GetColor(i,j);
      gameScreen.SetColor(x_ + i, y_ + j, color);
    }
  }
}
