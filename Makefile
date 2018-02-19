LVL1 = map_niveau1
LVL2 = map_niveau2
LVL3 = map_niveau3
MAP = create_map
TRES = tresors
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

map1: ${LVL1}.o ${MAP}.o
	${CC} ${LVL1}.o ${MAP}.o -o map1

map2: ${LVL2}.o ${MAP}.o
	${CC} ${LVL2}.o ${MAP}.o -o map2

map3:  ${LVL3}.o ${MAP}.o
	${CC} ${LVL3}.o ${MAP}.o -o map1

couloir: ${COUL}.c
	${CC} ${COUL}.c -o couloir

tresors: ${TRES}.o ${MAP}.o
	${CC} ${TRES}.o ${MAP}.o -o tresors

clean:
	- rm *.o
	- rm rogue_like
	- rm map_niveau1
	- rm map_niveau2

all : rogue_like map1 map2 map3 tresors
