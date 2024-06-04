//
// Created by kmg on 26/05/24.
//

#include "benchmark/benchmark.h"

int main(int argc, char *argv[]) {
   benchmark::Initialize(&argc, argv);
   benchmark::RunSpecifiedBenchmarks();
}

