
#include <iostream>
#include <sstream>

#include "benchmark/benchmark.h"
#include "clique.hpp"
#include "graph.hpp"
#include "graph_generator.hpp"

static void BM_cliqueBruteForce(benchmark::State& state) {
  size_t graphSize = state.range(0);
  auto cliqueSize = graphSize / 2;
  auto graph = graph::graphWithClique(graphSize, cliqueSize);
  for (auto _ : state) {
    graph::maxCliqueBruteForce(graph);
  }
}

static void BM_clique(benchmark::State& state) {
  size_t graphSize = state.range(0);
  auto cliqueSize = graphSize / 2;
  auto graph = graph::graphWithClique(graphSize, cliqueSize);
  for (auto _ : state) {
    graph::maxClique(graph);
  }
}

BENCHMARK(BM_cliqueBruteForce)->DenseRange(4, 10, 2);
BENCHMARK(BM_clique)->DenseRange(4, 32, 2);

BENCHMARK_MAIN();
