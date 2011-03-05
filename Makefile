CCNX_LIB=$(HOME)/3rd_party/ccnx/lib/ccn.jar
MONGODB_LIB=$(HOME)/3rd_party/mongo-2.4.jar
BOUNCYCASTLE_LIB=$(HOME)/3rd_party/ccnx/lib/bcprov-jdk16-143.jar

LIBPDC_LIB=libpdc/dist/libpdc.jar
PDC_LIB=pdc/dist/pdc.jar

PDC_MAIN=edu.ucla.cens.pdc.Main

ANT_CLASSPATH=-Dlibs.ccnx.classpath="$(CCNX_LIB)" -Dlibs.mongodb.classpath="$(MONGODB_LIB)" -Dlibs.BouncyCastle.classpath="$(BOUNCYCASTLE_LIB)"
JAVA_CLASSPATH=$(CCNX_LIB):$(MONGODB_LIB):$(BOUNCYCASTLE_LIB):$(LIBPDC_LIB):$(PDC_LIB)

#java -cp "/home/takeda/3rd_party/ccnx/lib/ccn.jar:/home/takeda/3rd_party/mongo-2.4.jar:/home/takeda/3rd_party/ccnx/lib/bcprov-jdk16-143.jar:/home/takeda/ndn-app/libpdc/dist/libpdc.jar:/home/takeda/ndn-app/pdc/dist/pdc.jar" edu.ucla.cens.pdc.Main

all: pdc.jar
run: pdc.jar
	java -ea -cp "$(JAVA_CLASSPATH)" $(PDC_MAIN) $(ARGS)

pdc.jar:
	cd pdc && ant $(ANT_CLASSPATH) jar

.DUMMY: all run pdc.jar
