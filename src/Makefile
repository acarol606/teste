LINK_TARGET = ted

OBJECTS = main.o parametros.o geo.o arvore.o figuras.o arvore.o

PROJECT_NAME = ted

# Make Macro defined by 3 macro expansions
REBUILDABLES = $(OBJECTS)

all: $(LINK_TARGET)
	echo All done

# Dependencies
main.o: parametros.h figuras.h arvore.h geo.h svg.h 
parametros.o: parametros.h
arvore.o: arvore.h
geo.o: geo.h figuras.h arvore.h

$(LINK_TARGET): $(OBJECTS) 
# $@ expands to the rule's target (LINK_TARGET)
# $^ expands to the rule's dependencies (OBJECTS)
# Note that -lm is used because of the dependency on math.h
# gcc -fstack-protector-all -std=c99 -g -o $@ $^ -lm
	gcc -std=c99 -Wall -o $@ $^ -lm

%.o : %.c
# $@ for the pattern-matched target
# $< for the pattern-matched dependency
# gcc -fstack-protector-all -std=c99 -g -o $@ -c $<
	gcc -std=c99 -Wall -g -o $@ -c $<
# Cleaning build environment

run: 
	./$(PROJECT_NAME) -e /home/util/Desktop/projeto2/entrada -f 00-reg-01.geo 


clear: 
	rm *.o;
	rm $(PROJECT_NAME);
	cd ..;cd output; rm *.svg; rm *.txt

clean:
# -f forced deletion 
# -i interacts with the user
# -r recursive removal
# -rf (DO NOT USE!)
# touch is just to prevent error message when file doesn’t exist
	touch $(REBUILDABLES)
	rm $(REBUILDABLES)
	echo done cleaning
	