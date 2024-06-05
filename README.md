# cqueue
Concurrent queue evaluations


## Sample outputs
with debug enabled
-DCMAKE_BUILD_TYPE=Debug


```
Users/kmg/projects/cqueue/cmake-build-debug/cqueue
2024-06-05T22:08:10+05:30
Running /Users/kmg/projects/cqueue/cmake-build-debug/cqueue
Run on (16 X 2300 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB
  L1 Instruction 32 KiB
  L2 Unified 256 KiB (x8)
  L3 Unified 16384 KiB
Load Average: 36.84, 203.43, 153.56
***WARNING*** Library was built as DEBUG. Timings may be affected.
-------------------------------------------------------------------------------------------------------------
Benchmark                                                                   Time             CPU   Iterations
-------------------------------------------------------------------------------------------------------------
QueueBenchmark/NonBlockingQueue/10000                                     145 ns          144 ns      5295729
QueueBenchmark/NonBlockingQueue/32768                                     132 ns          132 ns      4832452
QueueBenchmark/NonBlockingQueue/100000                                    126 ns          126 ns      5683571
QueueBenchmark/NonBlockingQueueMany/iterations:10000/threads:1           1298 ns         1283 ns        10000
QueueBenchmark/NonBlockingQueueMany/iterations:10000/threads:2           3597 ns         5763 ns        20000
QueueBenchmark/NonBlockingQueueMany/iterations:10000/threads:4           3800 ns        12793 ns        40000
QueueBenchmark/NonBlockingQueueMany/iterations:10000/threads:8           4584 ns        32085 ns        80000
QueueBenchmark/NonBlockingQueueMany/iterations:10000/threads:16          4789 ns        70775 ns       160000
QueueBenchmark/NonBlockingQueueMany/iterations:10000/threads:32          4562 ns        72336 ns       320000
QueueBenchmark/NonBlockingQueueMany/iterations:10000/threads:64          4566 ns        73049 ns       640000
QueueBenchmark/NonBlockingQueueMany/iterations:10000/threads:128         4457 ns        75400 ns      1280000
QueueBenchmark/NonBlockingQueueMany/iterations:10000/threads:256         4384 ns        73982 ns      2560000
QueueBenchmark/NonBlockingQueueMany/iterations:10000/threads:512         4284 ns        74204 ns      5120000
QueueBenchmark/NonBlockingQueueMany/iterations:10000/threads:1024        5384 ns        87342 ns     10240000
QueueBenchmark/LinkedAtomicQueue/10000                                    140 ns          140 ns      5060217
QueueBenchmark/LinkedAtomicQueue/32768                                    140 ns          140 ns      4920049
QueueBenchmark/LinkedAtomicQueue/100000                                   139 ns          139 ns      5037638
QueueBenchmark/LinkedAtomicQueueMany/iterations:10000/threads:1          1410 ns         1409 ns        10000
QueueBenchmark/LinkedAtomicQueueMany/iterations:10000/threads:2          1850 ns         3700 ns        20000
QueueBenchmark/LinkedAtomicQueueMany/iterations:10000/threads:4          1639 ns         6553 ns        40000
QueueBenchmark/LinkedAtomicQueueMany/iterations:10000/threads:8          2036 ns        16192 ns        80000
QueueBenchmark/LinkedAtomicQueueMany/iterations:10000/threads:16         2580 ns        40502 ns       160000
QueueBenchmark/LinkedAtomicQueueMany/iterations:10000/threads:32         2205 ns        36789 ns       320000
QueueBenchmark/LinkedAtomicQueueMany/iterations:10000/threads:64         1847 ns        30731 ns       640000
QueueBenchmark/LinkedAtomicQueueMany/iterations:10000/threads:128        2140 ns        35614 ns      1280000
QueueBenchmark/LinkedAtomicQueueMany/iterations:10000/threads:256        1903 ns        31494 ns      2560000
QueueBenchmark/LinkedAtomicQueueMany/iterations:10000/threads:512        1829 ns        30894 ns      5120000
QueueBenchmark/LinkedAtomicQueueMany/iterations:10000/threads:1024       1970 ns        33375 ns     10240000

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