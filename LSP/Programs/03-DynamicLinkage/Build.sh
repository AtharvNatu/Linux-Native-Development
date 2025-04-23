clear

# Dynamic Linking
gcc -c -fPIC MyMath.c

# -nostartfiles flag is used to skip default implementations of _init() and _fini() defined in crti.o
gcc -shared -nostartfiles -s -o libmymath.so MyMath.o

# Link Library To Executable
gcc -o LoadTimeApp MyMathImplicitClient.c ./libmymath.so

# Explicit Linking
gcc -o RunTimeApp MyMathExplicitClient.c





