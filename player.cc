// Similar to the opponent.cc (look there for reference)
#include "player.h"
#include <string>
Player::Player() : x_(0), y_(0){};
Player::Player(int x,int y) : x_(x), y_(y){
}
// 2. Create Player class
void Player::SetX(int x){x_ = x;}
void Player::SetY(int y){y_ = y;}
void Player::DrawPlayerImage(std::string player_image_file){
  const int size = 50;
  graphics::Image player_image(size, size);
  // Draws the face
  player_image.DrawCircle(size / 2, size / 2, size / 3,
                          167, 133, 106);
  player_image.DrawPolygon({25, 20, 10, 5, 10, 30}, 167, 133, 106);
  player_image.DrawPolygon({25, 20, 40, 5, 40, 30}, 167, 133, 106);

  // Draw the eyes
  player_image.DrawCircle(18, 20, 2, 0, 0, 0);
  player_image.DrawCircle(32, 20, 2, 0, 0, 0);

  // Draw mouth
  player_image.DrawPolygon({25, 25, 20, 32, 30, 32}, 243, 82, 120);

  // Draw nose
  player_image.DrawCircle(25, 25, 1, 0, 0, 0);

  // Saves the Player image
  player_image.SaveImageBmp(player_image_file);
}
  // draw member function
void Player::Draw(graphics::Image& gameScreen){
  DrawPlayerImage("player.bmp");
  graphics::Image player;
  player.Load("player.bmp");

  //moving location of player on screen
  for(int i = 0; i < kWidth; i++){
    for(int j = 0; j < kHeight; j++){
      graphics::Color color = player.GetColor(i,j);
      gameScreen.SetColor(x_ - kWidth/2 + i, y_ - kHeight/2 + j, color);
    }
  }
}
  // 3. Create IntersectsWith(Opponent) and
  // IntersectsWith(OpponentProjectile)



// 4. Create PLayerProjectile class
