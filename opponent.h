#ifndef OPPONENT_H
#define OPPONENT_H

#include "cpputils/graphics/image.h"
#include <string>

class Opponent {
    private:
        int x_; // Represents opponent's location
        int y_;
        const int kWidth_ = 50; // size of opponent image
        const int kHeight_ = 50;
    public:
        Opponent();
        Opponent(int x, int y);
        // Accessors
        int GetX();
        int GetY();
        int GetWidth();
        int GetHeight();
        // Mutators
        void SetX(int x);
        void SetY(int y);
        void DrawOppImage(std::string opponent_image_file);
        void Draw(graphics::Image& gameScreen, std::string opponent_image_file);
};

class OpponentProjectile {
    // 1. Create Opponent Projectile
    // Create data members to represent location (x,y)
    // Create two constant data members kWidth_ and kHeight_
    // Create Draw Function
    private:
    int x_;
    int y_;
    const int kWidth_ = 5;
    const int kHeight_ = 5;
    public:
    OpponentProjectile();
    OpponentProjectile(int x, int y);
    int Getx();
    int Gety();
    int GetWidth();
    int GetHeight();
    void Setx(int x);
    void Sety(int y);
    void DrawOppProjImage(std::string opponent_projectile_file);
    void Draw(graphics::Image& gameScreen, std::string opponent_projectile_file);
};

#endif
