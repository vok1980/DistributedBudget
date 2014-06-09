#!/bin/sh

cpucount=`grep -c "^processor.*:" /proc/cpuinfo`

if [ -z "$PREFIX" ]; then
	PREFIX="$(pwd)/env/default"
fi

echo "cpucount = $cpucount"
echo "PREFIX = $PREFIX"


download()
{
	if [ -f $1 ]; then
		echo "$1 already exists"
	else
		wget $2
	fi	
}

#rm -rf downloads
mkdir -p downloads
cd downloads

download cppunit-1.12.1.tar.gz 		http://downloads.sourceforge.net/cppunit/cppunit-1.12.1.tar.gz 
download poco-1.4.6p2-all.tar.gz 	http://pocoproject.org/releases/poco-1.4.6/poco-1.4.6p2-all.tar.gz
download protobuf-2.5.0.tar.bz2 	http://protobuf.googlecode.com/files/protobuf-2.5.0.tar.bz2

tar -xf cppunit-1.12.1.tar.gz
tar -xf poco-1.4.6p2-all.tar.gz
tar -xf protobuf-2.5.0.tar.bz2

mkdir -p ${PREFIX}
echo "PREFIX = ${PREFIX}"


cd cppunit-1.12.1 
make clean
./configure --prefix="${PREFIX}" LDFLAGS="-ldl"
make -j${cpucount} && make check && sudo make install || ( echo "failed to install cppunit" && exit 1 )

#sudo apt-get install openssl libssl-dev

cd ../poco-1.4.6p2-all
make clean
./configure --prefix="${PREFIX}" --omit=CppUnit,XML,Util,Data,Data/SQLite,Data/ODBC,Data/MySQL,Zip,PageCompiler,PageCompiler/File2Page
make -j${cpucount} && sudo make install || ( echo "failed to install poco" && exit 1 )

cd ../protobuf-2.5.0
make clean
./configure --prefix="${PREFIX}" 
make -j${cpucount} && sudo make install || ( echo "failed to install protobuf" && exit 1 )

