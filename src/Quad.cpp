include "exploration_manifold/Quad.h"

namespace purdue_arc
{

  Quad::Quad(const double& certainty, const double& variance, const double& normal[])
  {
    this.certainty = certainty;
    this.variance = variance;
    this.normal = normal;
  }

  Quad::~Quad() = delete()

  double Quad::getVariance()
  {
    return variance;
  }

  double Quad::getCertainty()
  {
    return certainty;
  }

  double Quad::getNormal()
  {
    return normal;
  }
}
