# 42-Pipex

 Project done with bonus part of handling multiple pipes.
**![pipex_mark](https://github.com/dejanzivanov/42-Pipex/blob/master/pipex.png)**

<!-- HOW TO -->
# How to use this project



Make sure that you have [GCC](https://gcc.gnu.org/) or [Clang](https://clang.llvm.org/) installed  
If you do not here is how to install them:

Install Clang:  
```
sudo apt-add-repository "deb http://apt.llvm.org/bionic/ llvm-toolchain-bionic-6.0 main"
```
```
sudo apt-get install -y clang-6.0 lld-6.0
```
Install GCC:  
```
sudo apt update
```
```
sudo apt install build-essential
```
```
sudo apt-get install manpages-dev
```
```
gcc --version
```
That’s it. GCC is now installed on your system, and you can start using it.  
<br/>

Clone the repository:  
```
https://github.com/dejanzivanov/42-Pipex.git
```
Change the directory:  
```
cd 42-Pipex
```
Run the make command: 
```
make
```
Executable 'pipex' will be generated. and you can perform following tests on it:  
```
./pipex infile "cat -e" "cat -e" "cat -e" outfile
```
