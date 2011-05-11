PROTOC=protoc

gen-proto: gen
	$(PROTOC) -Isrc --java_out=gen `find src -name '*.proto'`

gen:
	mkdir gen
