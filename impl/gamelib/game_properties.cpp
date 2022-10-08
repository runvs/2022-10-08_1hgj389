#include "game_properties.hpp"

jt::Palette GP::getPalette()
{
    static auto const p = jt::Palette::parseGPL(R"(GIMP Palette
#Palette Name: CMYK4
#Description: a slightly different palette based on CMYK colors
#Colors: 5
47 47 47 2f2f2f
152 152 152 989898
233 233 233 e9e9e9
130 255 89 82ff59
126 56 255 7e38ff
)");
    return p;
}

int GP::PhysicVelocityIterations() { return 20; }

int GP::PhysicPositionIterations() { return 20; }
jt::Vector2f GP::PlayerSize() { return jt::Vector2f { 16.0f, 16.0f }; }
float GP::catapultMovementSpeed() { return 40.0f; }
