LVL1 = map_niveau1
LVL2 = map_niveau2
LVL3 = map_niveau3
MAP = create_map
TRES = tresors
COUL = placement_coul
AFF = affichage_map
CC = gcc
FLAGS=-Wall -g
SDL_DIR=${HOME}/Projet_rogue_like/SDL2
SDL_LIB_DIR=${SDL_DIR}/lib
SDL_INC_DIR=${SDL_DIR}/include
LIBS=-L${SDL_LIB_DIR} -lSDL2 -lSDL2_ttf
INCS=-I${SDL_INC_DIR}
PROG=rogue_like

${PROG} : main.o ${MAP}.o ${TRES}.o ${LVL1}.o ${LVL2}.o ${LVL3}.o ${AFF}.o
	${CC} main.o ${MAP}.o ${TRES}.o ${LVL1}.o ${LVL2}.o ${LVL3}.o ${AFF}.o -o ${PROG} ${LIBS} ${INCS} ${FLAGS}

main.o : main.c
	${CC} -c main.c ${LIBS} ${INCS} ${FLAGS}

${MAP}.o : ${MAP}.c
	${CC} -c ${MAP}.c ${LIBS} ${INCS} ${FLAGS}

${AFF}.o : ${AFF}.c
	${CC} -c ${AFF}.c ${LIBS} ${INCS} ${FLAGS}

${TRES}.o : ${TRES}.c
	${CC} -c ${TRES}.c ${LIBS} ${INCS} ${FLAGS}

${LVL1}.o: ${LVL1}.c
	${CC} -c ${LVL1}.c ${LIBS} ${INCS} ${FLAGS}

${LVL2}.o: ${LVL2}.c
	${CC} -c ${LVL2}.c ${LIBS} ${INCS} ${FLAGS}

${LVL3}.o: ${LVL3}.c
	${CC} -c ${LVL3}.c ${LIBS} ${INCS} ${FLAGS}


clean:
	- rm *.o
	- rm rogue_like

all : rogue_like ${LIBS} ${INCS} ${FLAGS}
