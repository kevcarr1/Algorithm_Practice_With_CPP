cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    deps = [
        "//src/TestData:TestData",
        "//src/SortingAlgorithms:SortingAlgorithms",
        "//src/Practice:Practice",
        "//src/Benchmarking:Benchmark",
        "//src/SearchingAlgorithms:SearchingAlgorithms",
        "//src/GeneralAlgorithms:GeneralAlgorithms",
        "//src/utils:Utils",
        "//src/Stats:Stats",
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
        "//src/GeneralAlgorithms:GeneralAlgorithms",
    ],
    copts = ["-fsanitize=address"],
    linkopts = ["-fsanitize=address"],
)