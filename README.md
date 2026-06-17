# ARM64-asm-test
uhhh just click Download as ZIP

if you're on like x86_64/anything not ARM64 do this:

`sudo apt update`

`sudo apt install gcc-aarch64-linux-gnu`

`sudo apt install qemu-user`

`sudo apt install libncurses-dev:arm64` 

`sudo apt install libncursesw5-dev:arm64`

if you get errors about could not find the arm64 packages, do this:

`sudo dpkg --add-architecture arm64`

and then try again.

if it still doesn't work you're fucked (amd64 will not work :) )

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
