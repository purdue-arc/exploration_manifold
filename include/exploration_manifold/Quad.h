class Quad {
public:
    Quad(const double& certainty, const double& variance, const double& normalAngle);
    ~Quad();

    double getVariance();
    double getCertainty();
    double normalAngle();

private:
    const double& variance;
    const double& certainty;
    const double& normalAngle;
};
