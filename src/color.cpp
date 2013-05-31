#include <fstream>
#include <glm/glm.hpp>
#include "macro.hpp"
#include "color.hpp"

struct ColorImpl {
  float r;
  float g;
  float b;
  float opacity;

  ColorImpl (float _r, float _g, float _b, float _o) 
    : r(_r), g(_g), b(_b), opacity(_o) {}

  glm::vec3 vec3 () const {
    return glm::vec3 (this->r, this->g, this->b);
  }

  glm::vec4 vec4 () const {
    return glm::vec4 (this->r, this->g, this->b, this->opacity);
  }
};

DELEGATE4_BIG4        (Color,float,float,float,float)
GETTER                (float,Color,r)
GETTER                (float,Color,g)
GETTER                (float,Color,b)
GETTER                (float,Color,opacity)
DELEGATE_CONST        (glm::vec3,Color,vec3)
DELEGATE_CONST        (glm::vec4,Color,vec4)

Color :: Color (float r, float g, float b) : Color (r,g,b,1.0f) {}
Color :: Color (const glm::vec3& v)        : Color (v.x, v.y, v.z) {}
Color :: Color (const glm::vec4& v)        : Color (v.x, v.y, v.z, v.w) {}

std::ostream& operator<<(std::ostream& os, const Color& c) {
  os << "Color { red = "   << c.r () 
     <<       ", green = " << c.g () 
     <<       ", blue = "  << c.b () 
     << "}";
  return os;
}
