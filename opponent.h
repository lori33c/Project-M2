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
        std::string file;
        // Accessors
        int GetX();
        int GetY();
        int GetWidth();
        int GetHeight();
        // Mutators
        void SetX(int x);
        void SetY(int y);
        void SetFile(std::string name);
        void DrawOppImage(std::string opponent_image_file);
        void Draw(graphics::Image& gameScreen);
};

class OpponentProjectile {
    private:
    int x_;
    int y_;
    const int kWidth_ = 5;
    const int kHeight_ = 5;
    public:
    OpponentProjectile();
    OpponentProjectile(int x, int y);
    std::string file;
    int GetX();
    int GetY();
    int GetWidth();
    int GetHeight();
    void SetFile(std::string name);
    void SetX(int x);
    void SetY(int y);
    void DrawOppProjImage(std::string opponent_projectile_file);
    void Draw(graphics::Image& gameScreen);
};

#endif
