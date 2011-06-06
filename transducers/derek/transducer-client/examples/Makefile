all: Transducers.jar

edu/ucla/cens/pdc/transducers/client/NOOPTransducer.class:
	javac -d . -cp ../src:../../../../libpdc/dist/libpdc.jar NOOPTransducer.java

edu/ucla/cens/pdc/transducers/client/CounterMultiplier.class:
	javac -d . -cp ../src:../../../../libpdc/dist/libpdc.jar CounterMultiplier.java

Transducers.jar: edu/ucla/cens/pdc/transducers/client/NOOPTransducer.class edu/ucla/cens/pdc/transducers/client/CounterMultiplier.class
	jar -cf Transducers.jar edu

clean:
	rm -rf edu Transducers.jar
