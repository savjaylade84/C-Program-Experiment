
#getting the file name 
echo -e '\e[2;33m[Enter File :]\e[0m'
read -p "" name

#prompting for the checking of the existing binary
echo -e '\e[2;33m[Check existing binary...]\e[0m'
echo "checking@/bin/$name"

#promting for th removing of the existing binary
echo -e '\e[2;33m[Attempt to remove existing binary..]\e[0m'
echo "removing@/bin/$name"
rm bin/$name

#compiling the file to make new binary
echo -e '\e[2;33m[Compiling...]\e[0m'
gcc -std=c11 -o $name $name.c

#prompting for preparing
echo -e '\e[2;33m[Preparing new binary...]\e[0m'
echo "working@/bin/$name"
mv $name bin

#executing the file
echo -e '\e[2;33m[Executing new binary...]\e[0m'
echo "touching@/bin/$name"
./bin/$name
