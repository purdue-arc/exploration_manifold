namespace purdue_arc
{

    struct HalfEdge

class HalfEdge {
public:
    HalfEdge(const double& certainty, const double& variance);
    ~HalfEdge();


    double[] getBaseVertex();
    std::shared_ptr<Quad> getParentQuad();

    double[] getParentNormal();
private:
    // Other lniks
    double[] baseVertex;
    std::shared_ptr<Quad> parentQuad;

    // Linked half-edges
    std::shared_ptr<HalfEdge> prevEdge;
    std::shared_ptr<HalfEdge> twinEdge;
    std::shared_ptr<HalfEdge> nextEdge;

};
}
