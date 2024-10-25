cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    deps = [
        "//src/TestData:TestData",
        "//src/SortingAlgorithms:SortingAlgorithms",
        "//src/Practice:Practice",
        "//src/Benchmarking:Benchmark",
        "//src/SearchingAlgorithms:SearchingAlgorithms",
    ],
    copts = ["-g"]
)

cc_binary(
    name = "sanitize",
    srcs = ["main.cpp"],
    deps = [
        "//src/TestData:TestData",
        "//src/SortingAlgorithms:SortingAlgorithms",
        "//src/Practice:Practice",
        "//src/Benchmarking:Benchmark",
        "//src/SearchingAlgorithms:SearchingAlgorithms",
    ],
    copts = ["-fsanitize=address"],
    linkopts = ["-fsanitize=address"],
)