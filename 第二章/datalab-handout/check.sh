#!/usr/bin/env bash

./dlc -e bits.c
make btest
./btest
make clean