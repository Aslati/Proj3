from skbuild import setup
from setuptools import find_packages

setup(
    name='scikit_build_example',
    version='0.0.1',
    packages=find_packages(where='src'),
    package_dir={'': 'src'},
    cmake_install_dir='src/scikit_build_example',
    include_package_data=True,
    setup_requires=['setuptools', 'scikit-build', 'cmake', 'pybind11', 'matplotplusplus'],
)