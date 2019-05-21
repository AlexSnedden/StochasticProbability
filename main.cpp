#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "stochastic_probability.h"

int main() {
    srand(time(NULL));
    StochasticProbability sp1 = StochasticProbability(0.5, 100000);
    StochasticProbability sp2 = StochasticProbability(0.5, 100000);

    StochasticProbability sp3 = sp1+sp2;
    printf("%f\n", sp3.get_double());
}
