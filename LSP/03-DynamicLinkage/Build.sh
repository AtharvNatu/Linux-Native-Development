clear

# Dynamic Linking
gcc -c -fPIC my_math.c

# -nostartfiles flag is used to skip default implementations of _init() and _fini() defined in crti.o
gcc -shared -nostartfiles -s -o libmymath.so my_math.o

# Link Library To Executable
gcc -o app1 load_time_client.c ./libmymath.so

# Explicit Linking
gcc -o app2 run_time_client.c





