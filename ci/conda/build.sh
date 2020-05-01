#!/usr/bin/env bash

# Fail on error
set -e

python binder/generate/run.py

rm -Rf build
mkdir build
cd build

cmake .. -G "Ninja" \
    -DCMAKE_BUILD_TYPE="Release" \
    -DENABLE_SMESH=ON \
    -DENABLE_NETGEN=ON \
    -DPTHREAD_INCLUDE_DIRS=$PREFIX

ninja install

cd ..
python setup.py install --prefix=$PREFIX
