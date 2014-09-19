#!/bin/sh
    for i in test_head.cpp; do
        echo "compiling $i"
        g++ serial.cpp -ggdb `pkg-config --cflags opencv libserial`  -o `basename $i .cpp` $i `pkg-config --libs opencv libserial`;
    done
