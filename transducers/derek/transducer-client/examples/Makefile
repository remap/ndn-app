all: Transducers.jar

edu/ucla/cens/pdc/transducers/client/NOOPTransducer.class:
	javac -d . -cp ../src:../../../../libpdc/dist/libpdc.jar NOOPTransducer.java

Transducers.jar: edu/ucla/cens/pdc/transducers/client/NOOPTransducer.class
	jar -cf Transducers.jar edu
