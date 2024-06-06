# cqueue
Concurrent queue evaluations


## Sample outputs
with debug enabled
-DCMAKE_BUILD_TYPE=Debug


```
/Users/kmg/projects/cqueue/cmake-build-debug/cqueue
2024-06-06T21:04:42+05:30
Running /Users/kmg/projects/cqueue/cmake-build-debug/cqueue
Run on (16 X 2300 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB
  L1 Instruction 32 KiB
  L2 Unified 256 KiB (x8)
  L3 Unified 16384 KiB
Load Average: 3.95, 4.34, 2.99
***WARNING*** Library was built as DEBUG. Timings may be affected.
-------------------------------------------------------------------------------------------------------------
Benchmark                                                                   Time             CPU   Iterations
-------------------------------------------------------------------------------------------------------------
QueueBenchmark/LinkedAtomicQueue/10000                                    124 ns          123 ns      4802184
QueueBenchmark/LinkedAtomicQueue/32768                                    118 ns          117 ns      5695456
QueueBenchmark/LinkedAtomicQueue/100000                                   112 ns          111 ns      6506907
QueueBenchmark/LinkedAtomicQueueMany/iterations:10000/threads:1          1220 ns         1212 ns        10000
QueueBenchmark/LinkedAtomicQueueMany/iterations:10000/threads:2          1561 ns         3092 ns        20000
QueueBenchmark/LinkedAtomicQueueMany/iterations:10000/threads:4          1489 ns         5883 ns        40000
QueueBenchmark/LinkedAtomicQueueMany/iterations:10000/threads:8          1554 ns        12311 ns        80000
QueueBenchmark/LinkedAtomicQueueMany/iterations:10000/threads:16         1794 ns        27039 ns       160000
QueueBenchmark/LinkedAtomicQueueMany/iterations:10000/threads:32         1606 ns        25736 ns       320000
QueueBenchmark/LinkedAtomicQueueMany/iterations:10000/threads:64         1421 ns        22926 ns       640000
QueueBenchmark/LinkedAtomicQueueMany/iterations:10000/threads:128        1458 ns        23683 ns      1280000
QueueBenchmark/LinkedAtomicQueueMany/iterations:10000/threads:256        1350 ns        23113 ns      2560000
QueueBenchmark/LinkedAtomicQueueMany/iterations:10000/threads:512        1292 ns        22926 ns      5120000
QueueBenchmark/LinkedAtomicQueueMany/iterations:10000/threads:1024       1519 ns        25070 ns     10240000
QueueBenchmark/NonBlockingQueue/10000                                     159 ns          147 ns      4319041
QueueBenchmark/NonBlockingQueue/32768                                     146 ns          145 ns      4867567
QueueBenchmark/NonBlockingQueue/100000                                    141 ns          140 ns      4762747
QueueBenchmark/NonBlockingQueueMany/iterations:10000/threads:1           1399 ns         1399 ns        10000
QueueBenchmark/NonBlockingQueueMany/iterations:10000/threads:2           3573 ns         5720 ns        20000
QueueBenchmark/NonBlockingQueueMany/iterations:10000/threads:4           3968 ns        13309 ns        40000
QueueBenchmark/NonBlockingQueueMany/iterations:10000/threads:8           4167 ns        29258 ns        80000
QueueBenchmark/NonBlockingQueueMany/iterations:10000/threads:16          4814 ns        70533 ns       160000
QueueBenchmark/NonBlockingQueueMany/iterations:10000/threads:32          4959 ns        76744 ns       320000
QueueBenchmark/NonBlockingQueueMany/iterations:10000/threads:64          4899 ns        76867 ns       640000
QueueBenchmark/NonBlockingQueueMany/iterations:10000/threads:128         5373 ns        82432 ns      1280000
QueueBenchmark/NonBlockingQueueMany/iterations:10000/threads:256         5571 ns        87436 ns      2560000
QueueBenchmark/NonBlockingQueueMany/iterations:10000/threads:512         5285 ns        85366 ns      5120000
QueueBenchmark/NonBlockingQueueMany/iterations:10000/threads:1024        5341 ns        85061 ns     10240000

Process finished with exit code 0

```

without debug :
-DCMAKE_BUILD_TYPE=Release

```
//Users/kmg/projects/cqueue/cmake-build-debug/cqueue
2024-06-05T22:21:16+05:30
Running /Users/kmg/projects/cqueue/cmake-build-debug/cqueue
Run on (16 X 2300 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB
  L1 Instruction 32 KiB
  L2 Unified 256 KiB (x8)
  L3 Unified 16384 KiB
Load Average: 29.60, 137.01, 163.90
-------------------------------------------------------------------------------------------------------------
Benchmark                                                                   Time             CPU   Iterations
-------------------------------------------------------------------------------------------------------------
QueueBenchmark/LinkedAtomicQueue/10000                                   66.1 ns         65.8 ns      9550577
QueueBenchmark/LinkedAtomicQueue/32768                                   63.5 ns         63.4 ns     11119407
QueueBenchmark/LinkedAtomicQueue/100000                                  63.2 ns         63.2 ns     11420740
QueueBenchmark/LinkedAtomicQueueMany/iterations:10000/threads:1           583 ns          583 ns        10000
QueueBenchmark/LinkedAtomicQueueMany/iterations:10000/threads:2          1291 ns         2578 ns        20000
QueueBenchmark/LinkedAtomicQueueMany/iterations:10000/threads:4          1377 ns         5495 ns        40000
QueueBenchmark/LinkedAtomicQueueMany/iterations:10000/threads:8          1506 ns        12013 ns        80000
QueueBenchmark/LinkedAtomicQueueMany/iterations:10000/threads:16         1453 ns        22920 ns       160000
QueueBenchmark/LinkedAtomicQueueMany/iterations:10000/threads:32         1476 ns        23418 ns       320000
QueueBenchmark/LinkedAtomicQueueMany/iterations:10000/threads:64         1375 ns        22668 ns       640000
QueueBenchmark/LinkedAtomicQueueMany/iterations:10000/threads:128        1293 ns        21303 ns      1280000
QueueBenchmark/LinkedAtomicQueueMany/iterations:10000/threads:256        1255 ns        21094 ns      2560000
QueueBenchmark/LinkedAtomicQueueMany/iterations:10000/threads:512        1392 ns        23228 ns      5120000
QueueBenchmark/LinkedAtomicQueueMany/iterations:10000/threads:1024       1234 ns        21107 ns     10240000
QueueBenchmark/NonBlockingQueue/10000                                    37.8 ns         37.6 ns     18480043
QueueBenchmark/NonBlockingQueue/32768                                    39.7 ns         39.6 ns     17273672
QueueBenchmark/NonBlockingQueue/100000                                   39.3 ns         39.3 ns     17619504
QueueBenchmark/NonBlockingQueueMany/iterations:10000/threads:1            395 ns          394 ns        10000
QueueBenchmark/NonBlockingQueueMany/iterations:10000/threads:2            906 ns         1444 ns        20000
QueueBenchmark/NonBlockingQueueMany/iterations:10000/threads:4           1343 ns         4434 ns        40000
QueueBenchmark/NonBlockingQueueMany/iterations:10000/threads:8           1712 ns        11866 ns        80000
QueueBenchmark/NonBlockingQueueMany/iterations:10000/threads:16          2137 ns        29846 ns       160000
QueueBenchmark/NonBlockingQueueMany/iterations:10000/threads:32          1961 ns        31184 ns       320000
QueueBenchmark/NonBlockingQueueMany/iterations:10000/threads:64          1902 ns        31104 ns       640000
QueueBenchmark/NonBlockingQueueMany/iterations:10000/threads:128         1688 ns        28816 ns      1280000
QueueBenchmark/NonBlockingQueueMany/iterations:10000/threads:256         1625 ns        29016 ns      2560000
QueueBenchmark/NonBlockingQueueMany/iterations:10000/threads:512         1661 ns        29826 ns      5120000
QueueBenchmark/NonBlockingQueueMany/iterations:10000/threads:1024        1695 ns        28785 ns     10240000

Process finished with exit code 0

```