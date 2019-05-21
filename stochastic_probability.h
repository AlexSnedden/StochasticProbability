#ifndef STOCHASTIC_PROBABILITY_H
#define STOCHASTIC_PROBABILITY_H

typedef unsigned int uint;
typedef unsigned char uchar;

class StochasticProbability {
    private:
        uchar *bitstream;
        uint precision;
        uint array_length;

    public:
        StochasticProbability(double, uint);
        uchar *get_bitstream();
        uint get_precision();
        uint get_array_length();
        double get_double();
};

StochasticProbability operator *(StochasticProbability, StochasticProbability);
StochasticProbability operator +(StochasticProbability, StochasticProbability);
StochasticProbability operator ~(StochasticProbability);
#endif
