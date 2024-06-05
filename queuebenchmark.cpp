//
// Created by kmg on 04/06/24.
//
#include <benchmark/benchmark.h>
#include "QueueInterface.h"

using cqueue::QueueInterface;
using cqueue::NonBlockingQueue;
using cqueue::LinkedAtomicQueue;

class QueueBenchmark: public ::benchmark::Fixture {


public:
    std::shared_ptr<QueueInterface<int>> nonBlkqueue_p;
    std::shared_ptr<QueueInterface<int>> atomiqueue_p;

    QueueBenchmark() {
        nonBlkqueue_p = nullptr;
        atomiqueue_p = nullptr;
    }

    ~QueueBenchmark() = default;

    void SetUp(benchmark::State& state) override {
        if (state.thread_index() == 0) {
            nonBlkqueue_p = std::make_shared<NonBlockingQueue<int>>();
            atomiqueue_p =  std::make_shared<LinkedAtomicQueue<int>>();
        }
    }

    void TearDown(benchmark::State& state) override {
        if (state.thread_index() == 0) {
            nonBlkqueue_p = nullptr;
            atomiqueue_p = nullptr;
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

BENCHMARK_DEFINE_F(QueueBenchmark, NonBlockingQueueMany)(benchmark::State& state) {
    int tmp = 1;
    int size = 10;
    for(auto _ :state) {
        for(int i=0; i < size; i++)
            nonBlkqueue_p->add(i+1);
        for(int i=0; i < size; i++)
            nonBlkqueue_p->poll(tmp);
    }
}

BENCHMARK_DEFINE_F(QueueBenchmark, LinkedAtomicQueue)(benchmark::State& state) {
    int tmp = 1;
    for(auto _ :state) {
        atomiqueue_p->add(1);
        atomiqueue_p->poll(tmp);
    }
}

BENCHMARK_DEFINE_F(QueueBenchmark, LinkedAtomicQueueMany)(benchmark::State& state) {
    int tmp = 1;
    int size = 10;
    for(auto _ :state) {
        for(int i=0; i < size; i++)
            atomiqueue_p->add(i+1);
        for(int i=0; i < size; i++)
            atomiqueue_p->poll(tmp);
    }
}


BENCHMARK_REGISTER_F(QueueBenchmark, LinkedAtomicQueue)->Unit(benchmark::kNanosecond)->Range(10000, 100000);
BENCHMARK_REGISTER_F(QueueBenchmark, LinkedAtomicQueueMany)->Unit(benchmark::kNanosecond)->ThreadRange(1, 1024)->Iterations(10000);
BENCHMARK_REGISTER_F(QueueBenchmark, NonBlockingQueue)->Unit(benchmark::kNanosecond)->Range(10000, 100000);
BENCHMARK_REGISTER_F(QueueBenchmark, NonBlockingQueueMany)->Unit(benchmark::kNanosecond)->ThreadRange(1, 1024)->Iterations(10000);
