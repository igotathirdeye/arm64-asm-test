echo "compiling C file"
aarch64-linux-gnu-gcc -c menu.c -o menu.o \
    -I/usr/include \

echo "compiling assembly file"
aarch64-linux-gnu-as -o test.o test.s

echo "linking"
aarch64-linux-gnu-gcc -nostartfiles -o test test.o menu.o \
    -L/usr/lib/aarch64-linux-gnu \
    -lncursesw

rm menu.o test.o

clear
echo "done"

qemu-aarch64 ./test
