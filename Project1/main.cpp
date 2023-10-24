#include "BiTree.h"
#include <benchmark/benchmark.h>

static void BM_paint(benchmark::State& state) {
    // Сздаем дерево и заполняем его данными
    BiTree root;
    root.add("20");
    root.add("2");
    root.add("3");
    root.add("10");
    root.add("5");
    root.add("6");
    root.add("1");
    root.add("8");
    root.add("7");
    root.add("4");
    root.add("11");
    root.add("15");
    root.add("13");
    root.add("28");
    root.add("15");
    root.FoundSymbol('2');
    root.FoundStr("20");

    for (auto _ : state) {
        // Измеряем время выполнения функции paint()
        root.paint();
    }
}

BENCHMARK(BM_paint);
BENCHMARK_MAIN();