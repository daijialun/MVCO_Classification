#!/usr/bin/env sh

./build/tools/caffe train \
    --solver=models/mvco_caffenet/solver.prototxt
