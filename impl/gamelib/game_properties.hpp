#ifndef GAME_GAMEPROPERTIES_HPP
#define GAME_GAMEPROPERTIES_HPP

#include <color/color.hpp>
#include <color/palette.hpp>
#include <vector.hpp>
#include <string>

class GP {
public:
    GP() = delete;

    static std::string GameName() { return "Color Catapult"; }
    static std::string AuthorName() { return "Laguna_999"; }
    static std::string JamName() { return "1hgj389"; }
    static std::string JamDate() { return "2022-10-08"; }
    static std::string ExplanationText()
    {
        return "Get as many Blocks in your Color\n[W,S] to move\nhold/release [Space] to fire\n"
               "duration of [Space] press determines x position of hit";
    }

    static jt::Vector2f GetWindowSize() { return jt::Vector2f { 1200, 800 }; }
    static float GetZoom() { return 2.0f; }
    static jt::Vector2f GetScreenSize() { return GetWindowSize() * (1.0f / GetZoom()); }

    static jt::Color PaletteBackground() { return GP::getPalette().getColor(0); }
    static jt::Color PaletteFontFront() { return GP::getPalette().getColor(2); }
    static jt::Color PalleteFrontHighlight1() { return GP::getPalette().getColor(3); }
    static jt::Color PalleteFrontHighlight2() { return GP::getPalette().getColor(4); }
    static jt::Color PaletteFontShadow() { return GP::getPalette().getColor(1); }
    static jt::Color PaletteFontCredits() { return GP::getPalette().getColor(2); }

    static jt::Palette getPalette();

    static int PhysicVelocityIterations();
    static int PhysicPositionIterations();
    static jt::Vector2f PlayerSize();
    static float catapultMovementSpeed();
};

#endif
