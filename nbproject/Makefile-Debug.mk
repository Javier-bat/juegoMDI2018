#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Animacion.o \
	${OBJECTDIR}/Asteroide.o \
	${OBJECTDIR}/Bala.o \
	${OBJECTDIR}/Configuracion.o \
	${OBJECTDIR}/Controles.o \
	${OBJECTDIR}/Luna.o \
	${OBJECTDIR}/Menu.o \
	${OBJECTDIR}/MenuPausa.o \
	${OBJECTDIR}/MenuPrincipal.o \
	${OBJECTDIR}/PantallaJuego.o \
	${OBJECTDIR}/Ship.o \
	${OBJECTDIR}/gameOver.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=`pkg-config --libs sfml-all`  

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/juegomdi2018

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/juegomdi2018: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/juegomdi2018 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Animacion.o: Animacion.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags sfml-all`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Animacion.o Animacion.cpp

${OBJECTDIR}/Asteroide.o: Asteroide.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags sfml-all`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Asteroide.o Asteroide.cpp

${OBJECTDIR}/Bala.o: Bala.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags sfml-all`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Bala.o Bala.cpp

${OBJECTDIR}/Configuracion.o: Configuracion.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags sfml-all`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Configuracion.o Configuracion.cpp

${OBJECTDIR}/Controles.o: Controles.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags sfml-all`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Controles.o Controles.cpp

${OBJECTDIR}/Luna.o: Luna.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags sfml-all`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Luna.o Luna.cpp

${OBJECTDIR}/Menu.o: Menu.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags sfml-all`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Menu.o Menu.cpp

${OBJECTDIR}/MenuPausa.o: MenuPausa.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags sfml-all`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MenuPausa.o MenuPausa.cpp

${OBJECTDIR}/MenuPrincipal.o: MenuPrincipal.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags sfml-all`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MenuPrincipal.o MenuPrincipal.cpp

${OBJECTDIR}/PantallaJuego.o: PantallaJuego.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags sfml-all`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PantallaJuego.o PantallaJuego.cpp

${OBJECTDIR}/Ship.o: Ship.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags sfml-all`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Ship.o Ship.cpp

${OBJECTDIR}/gameOver.o: gameOver.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags sfml-all`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gameOver.o gameOver.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags sfml-all`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
