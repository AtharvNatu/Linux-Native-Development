libmode="static"

if [ "$libmode" = "static" ]
then
    # Static Linking
    gcc -c One.c
    gcc -c Two.c

    # Static Library
    ar -rcs libtest.a One.o Two.o

    # Link Library To Executable
    gcc -o TestStaticNew Test.c ./libtest.a

else
    # Dynamic Linking
    gcc -c -fPIC One.c
    gcc -c -fPIC Two.c

    gcc -shared -s -o libtest.so One.o Two.o

    # Link Library To Executable
    gcc -o TestDynamic Test.c ./libtest.so
fi



