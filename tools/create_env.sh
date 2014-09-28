#!/bin/sh

cpucount=`grep -c "^processor.*:" /proc/cpuinfo`

if [ -z "$PREFIX" ]; then
#	PREFIX="$(pwd)/env/default"
	PREFIX="/usr/local"
fi

echo "cpucount = $cpucount"
echo "PREFIX = $PREFIX"


download()
{
	if [ -f $1 ]; then
		echo "$1 already exists"
	else
		wget ${2}${1}
        tar -xf ${1}
	fi	
}

#rm -rf downloads
mkdir -p downloads
cd downloads

CPPUNIT:=cppunit-1.12.1
POCO:=poco-1.4.6p4-all
PROTOBUF:=protobuf-2.6.0


download ${CPPUNIT}.tar.gz 		    http://downloads.sourceforge.net/cppunit/ 
download ${POCO}.tar.gz 	        http://pocoproject.org/releases/poco-1.4.6/
download ${PROTOBUF}.tar.bz2 	    https://protobuf.googlecode.com/svn/rc/



mkdir -p ${PREFIX}
echo "PREFIX = ${PREFIX}"


cd ${CPPUNIT} 
make clean
./configure --prefix="${PREFIX}" LDFLAGS="-ldl"
make -j${cpucount} && make check && sudo make install || ( echo "failed to install cppunit" && exit 1 )

#sudo apt-get install openssl libssl-dev

cd ../${POCO}
make clean
./configure --prefix="${PREFIX}" --omit=CppUnit,XML,Util,Data,Data/SQLite,Data/ODBC,Data/MySQL,Zip,PageCompiler,PageCompiler/File2Page
make -j${cpucount} && sudo make install || ( echo "failed to install poco" && exit 1 )


if [ "/usr/local" = "$PREFIX" ]; then
	PREFIX="/usr"	# see protobuf readme for /usr/local issue
fi

cd ../${PROTOBUF}
make clean
./configure --prefix="${PREFIX}" 
make -j${cpucount} && sudo make install || ( echo "failed to install protobuf" && exit 1 )

