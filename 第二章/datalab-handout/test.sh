#!/usr/bin/env bash

./dlc -e bits.c
make clean
make btest
./btest