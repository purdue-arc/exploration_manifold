include "exploration_manifold/Quad.h"

Quad::Quad(const double& certainty, const double& variance, const double& normalAngle)
{
  this->certainty = certainty;
  this->variance = variance;
  this->normalAngle = normalAngle;
}

Quad::~Quad() = default;

double Quad::getVariance()
{
  return variance;
}

double Quad::getCertainty()
{
  return certainty;
}

double Quad::getNormalAngle()
{
  return normalAngle;
}
