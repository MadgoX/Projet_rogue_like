LVL1 = map_niveau1
LVL2 = map_niveau2
LVL3 = map_niveau3
MAP = create_map
TRES = tresors
COUL = couloir
AFF = affichage_map
PAR = partie
CC = gcc
FLAGS = -lncurses
PROG=rogue_like

${PROG} : main.o ${MAP}.o ${TRES}.o ${PAR}.o ${LVL1}.o ${LVL2}.o ${LVL3}.o ${AFF}.o ${COUL}.o
	${CC} main.o ${MAP}.o ${TRES}.o ${PAR}.o ${LVL1}.o ${LVL2}.o ${LVL3}.o ${AFF}.o ${COUL}.o -o ${PROG} ${FLAGS}

main.o : main.c
	${CC} -c main.c ${FLAGS}

${MAP}.o : ${MAP}.c
	${CC} -c ${MAP}.c ${FLAGS}

${AFF}.o : ${AFF}.c
	${CC} -c ${AFF}.c ${FLAGS}

${TRES}.o : ${TRES}.c
	${CC} -c ${TRES}.c ${FLAGS}
	
${PAR}.o : ${PAR}.c
	${CC} -c ${PAR}.c ${FLAGS}

${LVL1}.o: ${LVL1}.c
	${CC} -c ${LVL1}.c ${FLAGS}

${LVL2}.o: ${LVL2}.c
	${CC} -c ${LVL2}.c ${FLAGS}

${LVL3}.o: ${LVL3}.c
	${CC} -c ${LVL3}.c ${FLAGS}

${COUL}.o: ${COUL}.c
	${CC} -c ${COUL}.c ${FLAGS}

clean:
	- rm *.o
	- rm rogue_like

all : rogue_like ${FLAGS}
