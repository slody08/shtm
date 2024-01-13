# shtm
## Usage
+ '+' - new task (+TODO: Code)
+ '=' - toggle task (=1)
+ '-' - remove task (-1)
+ 'q' - exit the vitm (q)

## Building
#### Dependencies:
+ gcc
+ make
+ cmake

To install dependencies, use:
+ For Arch distributions:
```
sudo pacman -S gcc make cmake
```

+ For Ubuntu/Debian distributions:
```
sudo apt install build-essentials cmake
```

#### Building
1. Get source code from github
```
git clone https://github.org/slody08/shtm.git
```

2. Build it
```
cd shtm
mkdir build
cd build
cmake ..
make
```
