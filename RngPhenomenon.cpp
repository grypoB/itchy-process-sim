#include "RngPhenomenon.h"
#include "random.h"

namespace {
    double DEFAULT_MIN(0.  );
    double DEFAULT_MAX(100.);
}

RngPhenomenon::RngPhenomenon() : Phenomenon(), min_(DEFAULT_MIN), max_(DEFAULT_MAX) {}
RngPhenomenon::RngPhenomenon(State* pState, double min, double max) 
    : Phenomenon(pState), min_(min), max_(max)  {}

RngPhenomenon::~RngPhenomenon() {}

double RngPhenomenon::gen_val_phen(double) {
    return Rand::rand(min_, max_);
}
