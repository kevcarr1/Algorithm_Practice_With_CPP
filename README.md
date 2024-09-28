# CPP-Learning_Algorithms

A learning repository where commits on the main branch are tagged with the newly introduced algorithm. Previous commits should have a starter function.

## Building the Codebase

This codebase uses Bazel for it's build infrastructure.

At a high level, all you need to know is that the top-level directory should contain a WORKSPACE file and a MODULE.bazel file. There will be nothing in these files.

The BUILD file is also required and will contain the actual build instructions.

_To build the CPP binary, run the following command:_
<pre>
bazel build //:main
</pre>

This will build the binary and store it in the bazel-bin directory.

_To run the compiled binary, run:_
<pre>
./bazel-bin/main
</pre>
