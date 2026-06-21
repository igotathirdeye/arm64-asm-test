# ARM64-asm-test
uhhh just click Download as ZIP

> [!IMPORTANT]
> Supported environments:
>
> Native Linux
>
> ARM64 Linux (not tested but should work)

> [!NOTE]
> WSL used to be a supported environment, however since it does not expose /dev/dri, the farthest you will get is the menu. the main part will just show a black screen since SDL cannot get the KMS/DRM to work properly if /dev/dri isn't there (source: whatever i remembered from probably a senior dev on StackOverflow)
>
> You *might* be able to edit the graphics to use the /dev/dxg but i don't think it's worth it.

> [!CAUTION]
> DO NOT USE Crostini, it does not have ARM64 on the repos (atleast from my testers), so the libncurses packages will not install

if you're on like x86_64/anything not ARM64 do this:

`sudo apt update`

`sudo apt install gcc-aarch64-linux-gnu`

`sudo apt install g++-aarch64-linux-gnu`

`sudo apt install qemu-user`

`sudo apt install libncurses-dev:arm64` 

`sudo apt install libncursesw5-dev:arm64`

if you get errors about could not find the arm64 packages, do this:

`sudo dpkg --add-architecture arm64`

and then try again.

if it still doesn't work you're fucked (amd64 will not work :) )

once you're done installing the packages, run compile.sh.

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
