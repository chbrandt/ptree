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
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=
AS=as

# Macros
CND_PLATFORM=GNU-MacOSX
CND_CONF=Release
CND_DISTDIR=dist

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/ptree_bit.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/ptree_getoccurrences.o \
	${OBJECTDIR}/ptree_destroy.o \
	${OBJECTDIR}/search_text4key.o \
	${OBJECTDIR}/ptree_print.o \
	${OBJECTDIR}/ptree_library.o \
	${OBJECTDIR}/ptree_create.o

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
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-Release.mk dist/Release/GNU-MacOSX/ptree

dist/Release/GNU-MacOSX/ptree: ${OBJECTFILES}
	${MKDIR} -p dist/Release/GNU-MacOSX
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/ptree ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/ptree_bit.o: nbproject/Makefile-${CND_CONF}.mk ptree_bit.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.c) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/ptree_bit.o ptree_bit.c

${OBJECTDIR}/main.o: nbproject/Makefile-${CND_CONF}.mk main.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.c) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.c

${OBJECTDIR}/ptree_getoccurrences.o: nbproject/Makefile-${CND_CONF}.mk ptree_getoccurrences.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.c) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/ptree_getoccurrences.o ptree_getoccurrences.c

${OBJECTDIR}/ptree_destroy.o: nbproject/Makefile-${CND_CONF}.mk ptree_destroy.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.c) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/ptree_destroy.o ptree_destroy.c

${OBJECTDIR}/search_text4key.o: nbproject/Makefile-${CND_CONF}.mk search_text4key.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.c) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/search_text4key.o search_text4key.c

${OBJECTDIR}/ptree_print.o: nbproject/Makefile-${CND_CONF}.mk ptree_print.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.c) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/ptree_print.o ptree_print.c

${OBJECTDIR}/ptree_library.o: nbproject/Makefile-${CND_CONF}.mk ptree_library.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.c) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/ptree_library.o ptree_library.c

${OBJECTDIR}/ptree_create.o: nbproject/Makefile-${CND_CONF}.mk ptree_create.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.c) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/ptree_create.o ptree_create.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf:
	${RM} -r build/Release
	${RM} dist/Release/GNU-MacOSX/ptree

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
