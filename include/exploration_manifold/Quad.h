namespace purdue_arc
{
class Quad {
public:
    Quad(const double& certainty, const double& variance, const double& normal[3]);
    ~Quad();

    double getVariance();
    double getCertainty();
    double[] getNormal();

private:
    const double& variance;
    const double& certainty;
    const double& normal[3];
};
}
