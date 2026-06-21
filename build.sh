sudo apt install wget build-essential
sudo apt install libdrm2:arm64 libdrm-dev:arm64
sudo apt install libgbm1:arm64 libgbm-dev:arm64
sudo apt install libudev1:arm64 libudev-dev:arm64
sudo apt install libinput10:arm64 libinput-dev:arm64
sudo apt install libxkbcommon0:arm64 libxkbcommon-dev:arm64

wget https://www.libsdl.org/release/SDL2-2.30.5.tar.gz
tar xf SDL2-2.30.5.tar.gz
cd SDL2-2.30.5
./configure --host=aarch64-linux-gnu --build=x86_64-linux-gnu \
    CC=aarch64-linux-gnu-gcc \
    CXX=aarch64-linux-gnu-g++ \
    --enable-video-kmsdrm --disable-video-x11 --disable-video-wayland
make -j$(nproc)
sudo make install
sudo ldconfig
