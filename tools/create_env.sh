#!/bin/sh

PREFIX="$(pwd)/env/default"

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
make -j4 && make install
