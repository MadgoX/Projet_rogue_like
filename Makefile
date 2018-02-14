

LVL1 = map_niveau1
LVL2 = map_niveau2
MAP = create_map
TRES = tresor
COUL=placement_coul
CC = gcc





rogue_like : ${MAP}.o ${TRES}.o
	gcc ${MAP}.o ${TRES}.o -o rogue_like

${MAP}.o : ${MAP}.c
	${CC} -c ${MAP}.c

${TRES}.o : ${TRES}.c
	${CC} -c ${TRES}.c

${LVL1}.o: ${LVL1}.c
	${CC} -c ${LVL1}.c

${LVL2}.o: ${LVL2}.c
	${CC} -c ${LVL2}.c


map1: ${LVL1}.c 
	${CC} ${LVL1}.c -o map1

map2: ${LVL2}.c
	${CC} ${LVL2}.c -o map2

couloir: ${COUL}.c
	${CC} ${COUL}.c -o couloir

clean:
	- rm *.o
	- rm rogue_like
	- rm map_niveau1
	- rm map_niveau2