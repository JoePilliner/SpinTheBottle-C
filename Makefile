bin/spinthebottle : src/spinthebottle.c Makefile
	mkdir -p bin/
	cc -o bin/spinthebottle src/spinthebottle.c