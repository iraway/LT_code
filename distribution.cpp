#include "distribution.h"

Distribution::Distribution()
{

}

std::vector<double> Distribution::ideal_distribution(const size_t N){
    double probabilities_sum = 0.;
    probabilities_sum += 1./N;

    std::vector<double> probabilities;
    probabilities.push_back(0);
    probabilities.push_back(1./N);

    for(size_t i = 2; i < N + 1; i++){
        double num = 1. / ((double)i * ((double)i - 1));
        probabilities.push_back(num);
        probabilities_sum += num;
    }

    assert(probabilities_sum >= 1. - EPSILON and probabilities_sum <= 1. + EPSILON and "The ideal distribution should be standardized");
    return probabilities;
}

std::vector<double> Distribution::robust_distribution(const size_t N){
    const size_t M = N / 2 + 1;
    const double R = (double) N / M;
    std::vector<double> probabilities;
    probabilities.push_back(0);
    for(size_t i = 1; i < M; i++){
        probabilities.push_back(1./(i * M));
    }
    probabilities.push_back(log(R/ ROBUST_FAILURE_PROBABILITY) / M);
    for(size_t i = M + 1; i < N + 1; i++){
        probabilities.push_back(0);
    }

    std::vector<double> ideal = this->ideal_distribution(N);

    std::transform(probabilities.begin(), probabilities.end(), ideal.begin(),
                   probabilities.begin(), std::plus<double>());

    double sum_of_probabilities = std::accumulate(probabilities.begin(), probabilities.end(),
                                   decltype(probabilities)::value_type(0));

    std::transform(probabilities.begin(), probabilities.end(), probabilities.begin(),
                   std::bind2nd(std::divides<double>(), sum_of_probabilities));

    sum_of_probabilities = std::accumulate(probabilities.begin(), probabilities.end(),
                                       decltype(probabilities)::value_type(0));

    assert(sum_of_probabilities >= 1. - EPSILON and sum_of_probabilities <= 1. + EPSILON and "The robust distribution should be standardized");
/*
    M = N // 2 + 1
    R = N / M
    extra_proba = [0] + [1 / (i * M) for i in range(1, M)]
    extra_proba += [math.log(R / ROBUST_FAILURE_PROBABILITY) / M]  # Spike at M
    extra_proba += [0 for k in range(M+1, N+1)]
    probabilities = np.add(extra_proba, ideal_distribution(N))
    probabilities /= np.sum(probabilities)
    probabilities_sum = np.sum(probabilities)

    assert probabilities_sum >= 1 - EPSILON and probabilities_sum <= 1 + EPSILON, "The robust distribution should be standardized"
    return probabilities
  */
   return probabilities;
}

Distribution::~Distribution(){

}
