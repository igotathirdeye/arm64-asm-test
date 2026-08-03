cd /root
git clone https://github.com/raysan5/raylib.git
cd raylib/src
make PLATFORM=PLATFORM_DRM CC=aarch64-linux-gnu-gcc
