rogue_like : create_map.o tresors.o
	gcc create_map.o tresors.o -o rogue_like
create_map.o : create_map.c
	gcc -c create_map.c
tresors.o : tresors.c
	gcc -c tresors.c