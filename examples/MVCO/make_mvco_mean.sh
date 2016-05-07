#!/usr/bin/env sh
# Compute the mean image from the imagenet training lmdb
# N.B. this is available in data/ilsvrc12

EXAMPLE=examples/MVCO
DATA=data/MVCO
TOOLS=build/tools

$TOOLS/compute_image_mean $DATA/mvco_train_lmdb \
  $DATA/mvco_mean.binaryproto

echo "Done."
