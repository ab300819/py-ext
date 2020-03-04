from distutils.core import setup
from distutils.extension import Extension

hello = Extension(
    'hello',
    sources=['greet.cpp', 'greet_ext.cpp'],
    libraries=['boost_python37-mt']
)

setup(
    name='hello',
    version='0.1',
    ext_modules=[hello]
)
