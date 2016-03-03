#ifndef PolygonShape_h_
#define PolygonShape_h_

#include "../Shape.h"
#include "../Transform.h"
#include <glm/glm.hpp>
#define _USE_MATH_DEFINES
#include <math.h>

class PolygonShape : public Shape
{
public:
  PolygonShape()
  {
    Shape::m_type = Shape::eCircle;
  }

  virtual ~PolygonShape()
  {
  }

  virtual void computeAabb(AABB & p_aabb, Transform2d const & p_transform)
  {
    p_aabb.setCenter(p_transform.pos + p_transform.applyRotation(pos));
    p_aabb.setSize(glm::u64vec2(radius * 1.05, radius * 1.05));
  }
  virtual void calculateMassData(MassData & p_massData, glm::float32 p_density)
  {
    glm::dvec2 dpos = static_cast<glm::dvec2>(pos);
    p_massData.mass = p_density * M_PI * radius * radius;
    p_massData.center = pos;
    p_massData.inertia = p_massData.mass * (0.5f * radius * radius + glm::dot(dpos, dpos));
  }
  virtual bool TestPoint(const Transform2d& p_transform, const glm::i64vec2 & p_pos) const
  {
    glm::dvec2 distance = static_cast<glm::dvec2>(p_pos - p_transform.pos + p_transform.applyRotation(pos));
    return glm::dot(distance, distance) <= radius * radius;
  }

  glm::i64vec2 pos;
  glm::u64 radius;
};

#endif