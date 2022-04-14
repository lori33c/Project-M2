// Similar to the opponent.cc (look there for reference)
#include "player.h"
#include "opponent.h"
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
  std::string player_image_file;
  std::cout << "Please provide player image filename: ";
  std::cin >> player_image_file;

  DrawPlayerImage(player_image_file);
  graphics::Image player;
  player.Load(player_image_file);

  //moving location of player on screen
  for(int i = 0; i < kWidth; i++){
    for(int j = 0; j < kHeight; j++){
      graphics::Color color = player.GetColor(i,j);
      gameScreen.SetColor(x_ + i, y_ + j, color);
    }
  }
}

  // 3. Create IntersectsWith(Opponent) 
bool Player::IntersectsWith(Opponent opp) {
    bool intersects = true;
    int opp_w = opp.GetWidth();
    int opp_h = opp.GetHeight();
    int opp_x = opp.GetX();
    int opp_y = opp.GetY();

    int playerLeft = x_;
    int playerRight = playerLeft + kWidth;
    int playerTop = y_;
    int playerBottom = playerTop + kHeight;

    int oppLeft = opp_x;
    int oppRight = oppLeft + opp_w;
    int oppTop = opp_y;
    int oppBottom = oppTop + opp_h;

    return !(playerLeft > oppRight || playerBottom < oppTop || oppRight < playerLeft || oppBottom < playerTop);
}

bool Player::IntersectsWith(OpponentProjectile OppProj) {
    bool intersects = false;
    int OppProj_w = OppProj.GetWidth();
    int OppProj_h = OppProj.GetHeight();
    int OppProj_x = OppProj.GetX();
    int OppProj_y = OppProj.GetY();

    int playerLeft = x_;
    int playerRight = playerLeft + kWidth;
    int playerTop = y_;
    int playerBottom = playerTop + kHeight;

    int OpponentProjectileLeft = OppProj_x;
    int OpponentProjectileRight = OpponentProjectileLeft + OppProj_w;
    int OpponentProjectileTop = OppProj_y;
    int OpponentProjectileBottom = OpponentProjectileTop + OppProj_h;

    return !(playerLeft > OpponentProjectileRight || playerBottom < OpponentProjectileTop || OpponentProjectileRight < playerLeft || OpponentProjectileBottom < playerTop);
}

// 4. Create PLayerProjectile class
PlayerProjectile::PlayerProjectile() : x_(0), y_(0){}
PlayerProjectile::PlayerProjectile(int x, int y) : x_(x), y_(y) {}
void PlayerProjectile::SetX(int x) {x_ = x;}
void PlayerProjectile::SetY(int y) {y_ = y;}
int PlayerProjectile::GetX() {return x_;}
int PlayerProjectile::GetY() {return y_;}
int PlayerProjectile::GetWidth() { return kWidth_; }
int PlayerProjectile::GetHeight() { return kHeight_; }
void PlayerProjectile::DrawPlaProjImage(std::string player_projectile_file) {
  const int PlaProj_size = 5;
	graphics::Image PlayerProjectile_image(PlaProj_size, PlaProj_size);
	PlayerProjectile_image.DrawCircle(PlaProj_size/2, PlaProj_size/2, PlaProj_size/2, 0, 255, 0);
	PlayerProjectile_image.SaveImageBmp(player_projectile_file);
}
void PlayerProjectile::Draw(graphics::Image& gameScreen) {
  std::string player_projectile_file;
  std::cout << "Please provide player projectile image filename: ";
  std::cin >> player_projectile_file;

  DrawPlaProjImage(player_projectile_file);
  graphics::Image PlayerProjectile;
  PlayerProjectile.Load(player_projectile_file);
  for (int i = 0; i < kWidth_; i++){
    for (int j = 0; j < kHeight_; j++){
      graphics::Color color = PlayerProjectile.GetColor(i,j);
      gameScreen.SetColor(x_ + i, y_ + j, color);
    }
  }
}

bool PlayerProjectile::IntersectsWith(Opponent opp) {
    bool intersects = true;
    int opp_w = opp.GetWidth();
    int opp_h = opp.GetHeight();
    int opp_x = opp.GetX();
    int opp_y = opp.GetY();

    int oppProjLeft = x_;
    int oppProjRight = x_ + kWidth_;
    int oppProjTop = y_;
    int oppProjBottom = y_ + kHeight_;

    int oppLeft = opp_x;
    int oppRight = opp_x + opp_w;
    int oppTop = opp_y;
    int oppBottom = oppTop + opp_h;

    return !(oppProjLeft > oppRight || oppProjBottom < oppTop || oppRight < oppProjLeft || oppBottom < oppProjTop);
}

// No member function "IntersectsWith" in "Player Projectile"
