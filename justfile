alias b := build
CC := "clang"

build:
    {{CC}} *.c -O3 -std=c23 -o main

run: build
    ./main
    
clean:
    rm main

    
