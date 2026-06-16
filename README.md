# ARM64-asm-test
uhhh just click Download as ZIP

if you're on like x86_64/anything not ARM64 do this:

`sudo apt update`

`sudo apt install gcc-aarch64-linux-gnu`

`sudo apt install qemu-user`

`aarch64-linux-gnu-as -o test.o test.s`

`aarch64-linux-gnu-ld -static -o test test.o`

`qemu-aarch64 ./test`


> [!NOTE]
> for ARM64 just run these commands:
> 
> `as test.s -o test.o`
>
> `ld test.o -o test`
>
> to run the test file:
> 
> `./test`
>
> `echo $?`
