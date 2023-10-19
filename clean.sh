#!/bin/bash

# Function to be executed on exit
cleanup() {
    make clean
}

# Trap Ctrl+C and execute cleanup function
trap cleanup EXIT

# Your commands go here
make all
./lublu