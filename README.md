## prerequisite
    npm install -g node-gyp
    or
    npm install -g node-gyp@latest

Depending on your operating system, you will need to install:
On Unix
Python v3.7, v3.8, v3.9, or v3.10
make
A proper C/C++ compiler toolchain, like GCC



##Project commands
npm init --y
node-gyp configure
node-gyp configure --msvs_version=2015
node-gyp build
#together
node-gyp configure build  
or
node-gyp clean configure build

for 32 bit from 64 bit pc
node-gyp clean configure build --verbose --arch=ia32
