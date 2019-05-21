#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "stochastic_probability.h"

StochasticProbability::StochasticProbability(double value, uint bit_precision) {
    precision = bit_precision;
    array_length = precision % 8 ? precision / 8 + 1: precision / 8;
    bitstream = (uchar*)calloc(1, array_length);
    for(int i=0; i < array_length; i++) {
        for(int bit=0; bit < 8; bit++) {
            if((double)rand() / (double)RAND_MAX < value) {
                bitstream[i] |= (1 << bit);
            }
        }
    }
}

uint StochasticProbability::get_precision() {
    return precision;
}

uint StochasticProbability::get_array_length() {
    return array_length;
}

uchar *StochasticProbability::get_bitstream() {
    return bitstream;
}

double StochasticProbability::get_double() {
    double lit_bits = 0.0;
    int t=0;
    for(int i=0; i < array_length; i++) {
        for(int bit=0; bit < 8; bit++) {
            lit_bits += (bitstream[i] & (1 << bit)) >> bit;
        }
    }
    return lit_bits / (double)precision;
}

StochasticProbability operator *(StochasticProbability sp1, StochasticProbability sp2) {
    StochasticProbability *sp3 = new StochasticProbability(0.0, sp1.get_precision());
    uchar *bs1 = sp1.get_bitstream();
    uchar *bs2 = sp2.get_bitstream();
    uchar *bs3 = sp3->get_bitstream();
    for(int i=0; i < sp1.get_array_length(); i++) {
        bs3[i] = bs1[i] & bs2[i];
    }
    return *sp3;
}

StochasticProbability operator +(StochasticProbability sp1, StochasticProbability sp2) {
    StochasticProbability *sp3 = new StochasticProbability(0.0, sp1.get_precision());
    uchar *bs1 = sp1.get_bitstream();
    uchar *bs2 = sp2.get_bitstream();
    uchar *bs3 = sp3->get_bitstream();
    for(int i=0; i < sp1.get_array_length(); i++) {
        bs3[i] = bs1[i] | bs2[i];
    }
    return *sp3;
}

StochasticProbability operator ~(StochasticProbability sp1) {
    StochasticProbability *sp2 = new StochasticProbability(0.0, sp1.get_precision());
    uchar *bs1 = sp1.get_bitstream();
    uchar *bs2 = sp2->get_bitstream();
    for(int i=0; i < sp1.get_array_length(); i++) {
        bs2[i] = ~bs1[i];
    }
    return *sp2;
}
