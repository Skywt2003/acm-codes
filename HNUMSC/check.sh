#!/bin/bash

./make_data_F > data.in
./F < data.in > data.out
./F0 < data.in > data0.out
diff data.out data0.out
