# Flora

This is a hobby project that I am working on with a friend from school. The
project implements an infinitely explorable field of flowers generated using
wave function collapse. Currently, the windowing and OpenGL function loading is
all managed by SFML, but we have plans to hand-write a cross-platform windowing
library and OpenGL function loading system, just for funsies.

## Compiling

The two main platforms supported are Windows and Linux. See the appropriate
section below for instructions on how to compile on your platform.

### Windows

Building on Windows is supported, though begrudgingly. Just kidding. To build
this program, ensure that you have the lastest version of Visual Studio
installed with *Desktop Development with C++* enabled, as well as the latest
version of CMake.

Once you have those, clone the git repository onto your system and open the
project in Visual Studio. The CMake cache should be automatically generated,
but it does take a little bit. Check the output window for progress. Once the
cache is ready, ensure that `flora.exe` is selected next to the green arrow at
the top, then click the arrow to run. Everything should just work at this
point. If something does not work, that is an issue. Feel free to file any
issues you experience with the build process on GitHub.

### Linux

You made the right choice. To compile this program, you will need all of the
libraries required to build SFML, since we build that from source. As detailed
above, we hope to eliminate the dependency on SFML in the future, but this is
where we are for now. You can find a complete and up-to-date list of SFML's
build dependencies [here](sfml-build-deps). They should all be available
through your system's package manager.

Once you have those, ensure that you have a C++ compiler which supports at
least C\++23. This should not be too big of an issue, just be aware that the
main feature used from C++23 is `std::expected`. You should also have a build
tool like Make or Ninja installed, as well as the CMake build system generator.
Once you have all of that, simply run the following commands in the root of the
project:

```bash
cmake -B build
cmake --build build
build/flora
```

And you're in business!

[sfml-build-deps]: https://www.sfml-dev.org/tutorials/3.0/getting-started/build-from-source/#installing-dependencies

## License

This code is licensed under the MIT license. Do what you wish with the code,
but make sure that all of the original authors are properly credited.
