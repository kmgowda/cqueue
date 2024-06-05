# cqueue
Concurrent queue evaluations


## Sample output

```
/Users/kmg/projects/cqueue/cmake-build-debug/cqueue
2024-06-05T21:58:29+05:30
Running /Users/kmg/projects/cqueue/cmake-build-debug/cqueue
Run on (16 X 2300 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB
  L1 Instruction 32 KiB
  L2 Unified 256 KiB (x8)
  L3 Unified 16384 KiB
Load Average: 36.57, 28.60, 21.05
***WARNING*** Library was built as DEBUG. Timings may be affected.
-------------------------------------------------------------------------------------------------------------
Benchmark                                                                   Time             CPU   Iterations
-------------------------------------------------------------------------------------------------------------
QueueBenchmark/NonBlockingQueue/10000                                     145 ns          143 ns      4701331
QueueBenchmark/NonBlockingQueue/32768                                     137 ns          135 ns      5023323
QueueBenchmark/NonBlockingQueue/100000                                    133 ns          132 ns      5355941
QueueBenchmark/NonBlockingQueueMany/iterations:10000/threads:1           1296 ns         1290 ns        10000
QueueBenchmark/NonBlockingQueueMany/iterations:10000/threads:2           3482 ns         5531 ns        20000
QueueBenchmark/NonBlockingQueueMany/iterations:10000/threads:4           3940 ns        13129 ns        40000
QueueBenchmark/NonBlockingQueueMany/iterations:10000/threads:8           4226 ns        30048 ns        80000
QueueBenchmark/NonBlockingQueueMany/iterations:10000/threads:16          4972 ns        70712 ns       160000
QueueBenchmark/NonBlockingQueueMany/iterations:10000/threads:32          4582 ns        69750 ns       320000
QueueBenchmark/NonBlockingQueueMany/iterations:10000/threads:64          4546 ns        71185 ns       640000
QueueBenchmark/NonBlockingQueueMany/iterations:10000/threads:128         4574 ns        74853 ns      1280000
QueueBenchmark/NonBlockingQueueMany/iterations:10000/threads:256         4304 ns        70982 ns      2560000
QueueBenchmark/NonBlockingQueueMany/iterations:10000/threads:512         4382 ns        71143 ns      5120000
QueueBenchmark/NonBlockingQueueMany/iterations:10000/threads:1024        4740 ns        75432 ns     10240000
QueueBenchmark/LinkedAtomicQueue/10000                                    141 ns          135 ns      5128468
QueueBenchmark/LinkedAtomicQueue/32768                                    134 ns          134 ns      5263712
QueueBenchmark/LinkedAtomicQueue/100000                                   131 ns          130 ns      5249029
QueueBenchmark/LinkedAtomicQueueMany/iterations:10000/threads:1          1296 ns         1295 ns        10000
QueueBenchmark/LinkedAtomicQueueMany/iterations:10000/threads:2          1738 ns         3463 ns        20000
QueueBenchmark/LinkedAtomicQueueMany/iterations:10000/threads:4          1555 ns         6196 ns        40000
QueueBenchmark/LinkedAtomicQueueMany/iterations:10000/threads:8          1777 ns        14094 ns        80000
QueueBenchmark/LinkedAtomicQueueMany/iterations:10000/threads:16         1958 ns        29761 ns       160000
QueueBenchmark/LinkedAtomicQueueMany/iterations:10000/threads:32         1724 ns        27845 ns       320000
QueueBenchmark/LinkedAtomicQueueMany/iterations:10000/threads:64         1859 ns        29293 ns       640000
QueueBenchmark/LinkedAtomicQueueMany/iterations:10000/threads:128        1725 ns        27955 ns      1280000
QueueBenchmark/LinkedAtomicQueueMany/iterations:10000/threads:256        1538 ns        25178 ns      2560000
QueueBenchmark/LinkedAtomicQueueMany/iterations:10000/threads:512        1700 ns        28024 ns      5120000
QueueBenchmark/LinkedAtomicQueueMany/iterations:10000/threads:1024       1865 ns        29765 ns     10240000

Process finished with exit code 0
```