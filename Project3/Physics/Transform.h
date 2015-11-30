#ifndef PhysTransform2d_h_
#define PhysTransform2d_h_

#include <glm/glm.hpp>

struct Transform2d
{
  Transform2d(glm::i64vec2 p_pos = glm::i64vec2(0,0), glm::fvec2 p_rot = glm::fvec2(0,0)) :
  pos(p_pos),
  rot(p_rot)
  { }
  glm::i64vec2 pos;
  glm::fvec2 rot;

  template <class T>
  inline T multiply(T p_pos) const
  {
    return T((rot.x * p_pos.x - rot.y * p_pos.y) + pos.x
      , (rot.y * p_pos.x + rot.x * p_pos.y) + pos.y);
  }

  template <class T>
  inline T applyRotation(T p_pos) const
  {
    return T((rot.x * p_pos.x - rot.y * p_pos.y)
      , (rot.y * p_pos.x + rot.x * p_pos.y));
  }

};


#endif