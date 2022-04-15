// Similar to opponent.h (look there for reference)
#ifndef PLAYER_H
#define PLAYER_H

#include "cpputils/graphics/image.h"
#include <string>
#include "opponent.h"
class Player{
    private:
        int x_, y_;
        const int kWidth = 50;
        const int kHeight = 50;
    public:
        Player();
        Player(int x, int y);
        std::string file;
        void SetX(int x);
        void SetY(int y);
        void SetFile(std::string name);
        int GetX();
        int GetY();
        int GetWidth();
        int GetHeight();
        void DrawPlayerImage(std::string player_image_file);
        void Draw(graphics::Image& gameScreen);
        bool IntersectsWith(Opponent opp);
        bool IntersectsWith(OpponentProjectile OppProj);
};

class PlayerProjectile {
    private:
    int x_;
    int y_;
    const int kWidth_ = 5;
    const int kHeight_ = 5;
    public:
    PlayerProjectile();
    PlayerProjectile(int x, int y);
    std::string file;
    int GetX();
    int GetY();
    int GetWidth();
    int GetHeight();
    void SetX(int x);
    void SetY(int y);
    void SetFile(std::string name);
    void DrawPlaProjImage(std::string player_projectile_file);
    void Draw(graphics::Image& gameScreen);
    bool IntersectsWith(Opponent opp);
};
#endif

