#include <pybind11/pybind11.h>
#include <matplot/matplot.h>
#include <vector>
#include <AudioFile.h>

namespace mp = matplot;

namespace py = pybind11;

void plot(char pathToAudio[])
{
    AudioFile<float> audioFile;
    bool load = audioFile.load(pathToAudio);

    if (!load)
    {
        std::cerr << "Incorrect audio path";
    }

    std::vector<float> samples = audioFile.samples[0];
    if (samples.size() > 500)
    {
        samples.erase(samples.begin() + 500, samples.end());
    }

    auto plot = mp::figure(true);
    mp::plot(samples);
    mp::show();
}

PYBIND11_MODULE(_PROJ3, m)
{
    m.doc() = R"pbdoc(
        An attempt at making a python library to display signals using c++ and pybind 11
    )pbdoc";

    m.def("plot", &plot, R"pbdoc(Plots an audio file)pbdoc");

    m.attr("__version__") = "cryingOutLoud";
}
