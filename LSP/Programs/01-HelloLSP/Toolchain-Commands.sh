# Single-Step Compile and Link
# gcc -o App $1


# Step - 1 -> Pre-Processor
gcc -E -o App.i HelloLSP.c

# Step - 2 -> Compiler
gcc -S App.i -o App.s

# Step - 3 -> Assembler
gcc -c App.s -o App.o

# Step - 4 -> Linker
gcc App.o -o App

./App

