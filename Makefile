LVL1 = map_niveau1
LVL2 = map_niveau2
LVL3 = map_niveau3
MAP = create_map
TRES = tresors
COUL = placement_coul
AFF = affichage_map
CC = gcc


rogue_like : main.o ${MAP}.o ${TRES}.o ${LVL1}.o ${LVL2}.o ${LVL3}.o ${AFF}.o
	${CC} main.o ${MAP}.o ${TRES}.o ${LVL1}.o ${LVL2}.o ${LVL3}.o ${AFF}.o -o rogue_like

main.o : main.c
	${CC} -c main.c

${MAP}.o : ${MAP}.c
	${CC} -c ${MAP}.c

${AFF}.o : ${AFF}.c
	${CC} -c ${AFF}.c

${TRES}.o : ${TRES}.c
	${CC} -c ${TRES}.c

${LVL1}.o: ${LVL1}.c
	${CC} -c ${LVL1}.c

${LVL2}.o: ${LVL2}.c
	${CC} -c ${LVL2}.c

${LVL3}.o: ${LVL3}.c
	${CC} -c ${LVL3}.c

map1: ${LVL1}.o ${MAP}.o ${AFF}.o
	${CC} ${LVL1}.o ${MAP}.o ${AFF}.o -o map1

map2: ${LVL2}.o ${MAP}.o ${AFF}.o
	${CC} ${LVL2}.o ${MAP}.o ${AFF}.o -o map2

map3:  ${LVL3}.o ${MAP}.o ${AFF}.o
	${CC} ${LVL3}.o ${MAP}.o ${AFF}.o -o map3

couloir: ${COUL}.c
	${CC} ${COUL}.c -o couloir

tresors: ${TRES}.o ${MAP}.o
	${CC} ${TRES}.o ${MAP}.o -o tresors

clean:
	- rm *.o
	- rm rogue_like
	- rm map1
	- rm map2
	- rm map3

all : rogue_like map1 map2 map3 tresors
