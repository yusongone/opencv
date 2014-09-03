#!/bin/sh
    for i in *.cpp; do
        echo "compiling $i"
        g++ -ggdb `pkg-config --cflags libserial` -o `basename $i .cpp` $i `pkg-config --libs libserial`;
    done
