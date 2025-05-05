# Single-Step Compile and Link
# gcc -o app hello_lsp.c


# Step - 1 -> Pre-Processor
gcc -E -o app.i hello_lsp.c

# Step - 2 -> Compiler
gcc -S app.i -o app.s

# Step - 3 -> Assembler
gcc -c app.s -o app.o

# Step - 4 -> Linker
gcc app.o -o app

./app

