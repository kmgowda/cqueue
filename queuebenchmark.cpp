//
// Created by kmg on 04/06/24.
//
#include <benchmark/benchmark.h>
#include "QueueInterface.h"

using cqueue::QueueInterface;
using cqueue::NonBlockingQueue;

class QueueBenchmark: public ::benchmark::Fixture {


public:
    std::shared_ptr<QueueInterface<int>> nonBlkqueue_p;

    QueueBenchmark() {
        nonBlkqueue_p = nullptr;
    }

    ~QueueBenchmark() = default;

    void SetUp(benchmark::State& state) override {
        if (state.thread_index() == 0) {
            nonBlkqueue_p = std::make_shared<NonBlockingQueue<int>>();
        }
    }

    void TearDown(benchmark::State& state) override {
        if (state.thread_index() == 0) {
            nonBlkqueue_p = nullptr;
        }
    }
};

BENCHMARK_DEFINE_F(QueueBenchmark, NonBlockingQueue)(benchmark::State& state) {
    int tmp = 1;
    for(auto _ :state) {
        nonBlkqueue_p->add(1);
        nonBlkqueue_p->poll(tmp);
    }
}

BENCHMARK_DEFINE_F(QueueBenchmark, LinkedAtomicQueue)(benchmark::State& state) {
    int tmp = 1;
    for(auto _ :state) {
        nonBlkqueue_p->add(1);
        nonBlkqueue_p->poll(tmp);
    }
}


BENCHMARK_REGISTER_F(QueueBenchmark, NonBlockingQueue)->Unit(benchmark::kNanosecond)->Range(10000, 100000);
BENCHMARK_REGISTER_F(QueueBenchmark, NonBlockingQueue)->Unit(benchmark::kNanosecond)->ThreadRange(1, 1024)->Iterations(10000);
BENCHMARK_REGISTER_F(QueueBenchmark, LinkedAtomicQueue)->Unit(benchmark::kNanosecond)->Range(10000, 100000);
BENCHMARK_REGISTER_F(QueueBenchmark, LinkedAtomicQueue)->Unit(benchmark::kNanosecond)->ThreadRange(1, 1024)->Iterations(10000);
