# ARM64-asm-test
uhhh just click Download as ZIP

if you're on like x86_64/anything not ARM64 do this:

`sudo apt update`

`sudo apt install gcc-aarch64-linux-gnu`

`sudo apt install qemu-user`

and then run compile.sh.

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
