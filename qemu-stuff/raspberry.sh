#!/bin/bash
# copied from: https://github.com/luisespino/assembly/tree/main/emulate-raspios-arm64-on-qemu, only thing i changed was the ^ to \ , and changed the path, and added #!/bin/bash (and added these comments but do i really need to say that?)
# also why the fuck is the echo the only english part of the README
"qemu-system-aarch64" \
  -M raspi3b \
  -cpu cortex-a53 \
  -m 1G -smp 4 \
  -kernel kernel8.img \
  -sd raspios.img  \
  -dtb bcm2710-rpi-3-b-plus.dtb \
  -append "rw earlyprintk loglevel=8 console=ttyAMA0,115200
  dwc_otg.lpm_enable=0 root=/dev/mmcblk0p2 rootdelay=1" \
  -serial stdio \
  -usb -device usb-mouse -device usb-kbd \
  -device usb-net,netdev=net0 \
  -netdev user,id=net0,hostfwd=tcp::5555-:22

echo QEMU is finished
