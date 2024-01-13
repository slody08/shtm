# About
```
       _     _             
   ___| |__ | |_ _ __ ___  
  / __| '_ \| __| '_ ` _ \ 
  \__ \ | | | |_| | | | | |
  |___/_| |_|\__|_| |_| |_|

```

shtm - minimalistic, shell-like task manager built on pure C++

# Usage
+ '+' - new task (+TODO: Code)
+ '=' - toggle task (=1)
+ '-' - remove task (-1)
+ 'q' - exit the vitm (q)

# Building
### Dependencies:
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

### Building
1. Retrieve source code from github
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
