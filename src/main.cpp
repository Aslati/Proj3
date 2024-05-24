#include <pybind11/pybind11.h>
#include <matplot/matplot.h>
#include <vector>
#include <cmath>
#include <math.h>
// #include <AudioFile.h>
#include <corecrt_math_defines.h>

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

namespace mp = matplot;

namespace py = pybind11;

int add(int i, int j)
{
    return i + j;
}

void plot()
{
    std::vector<double> x = mp::linspace(0, 2 * M_PI);
    std::vector<double> y = mp::transform(x, [](auto x)
                                          { return sin(x); });
    mp::plot(x, y);

    mp::show();
}

PYBIND11_MODULE(_PROJ3, m)
{
    m.doc() = R"pbdoc(
        Pybind11 example plugin
        -----------------------

        .. currentmodule:: scikit_build_example

        .. autosummary::
           :toctree: _generate

           add
           subtract
    )pbdoc";

    m.def("add", &add, R"pbdoc(
        Add two numbers

        Some other explanation about the add function.
    )pbdoc");

    m.def("subtract", [](int i, int j)
          { return i - j; }, R"pbdoc(
        Subtract two numbers

        Some other explanation about the subtract function.
    )pbdoc");

    m.def("plot", &plot, R"pbdoc(a plotting function)pbdoc");

    m.attr("__version__") = "cryingOutLoud";
}
