# this qemu-stuff folder is for me to emulate Raspberry Pi OS Legacy Lite 64 bit on QEMU

so if you're already on like ARM64 gtfo of this folder, and delete it if you want :)

anyways here's the links to the resources:
https://github.com/luisespino/assembly/tree/main/emulate-raspios-arm64-on-qemu, and yes this link is spanish but whatever

https://www.raspberrypi.com/software/operating-systems/, for this one scroll down and click Download on Raspberry Pi OS Legacy Lite 64 bit

btw if you're on windows fuck you, WSL doesn't work either, so you'll need an actual Linux machine

> [!NOTE]
> WSL does technically work, however it is slower than a depressed snail with asthma.

anyways here's the guide to get test.s on the VM:

`sudo apt update`

`sudo apt install git`

`git clone https://github.com/igotathirdeye/arm64-asm-test.git`

`cd arm64-asm-test`

`as test.s -o test.o`

`ld test.o -o test`

`./test`

`echo $?`
