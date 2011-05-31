#! /bin/sh

JAVADOCDIR=javadoc

if [ ! -d src ]; then
	echo "You supposed to call this command from the root directory"
	exit 10
fi

if [ -d $JAVADOCDIR ]; then
	echo "Removing $JAADOCDIR ..."
	rm -rf $JAVADOCDIR
fi

mkdir $JAVADOCDIR

echo "Generating javadoc..."
find src -name '*.java' | xargs javadoc -private -d javadoc

