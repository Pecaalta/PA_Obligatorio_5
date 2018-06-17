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
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Contacto.o \
	${OBJECTDIR}/Conversaciones.o \
	${OBJECTDIR}/Estado.o \
	${OBJECTDIR}/Fecha.o \
	${OBJECTDIR}/Foto.o \
	${OBJECTDIR}/Grupo.o \
	${OBJECTDIR}/ICollection/Integer.o \
	${OBJECTDIR}/ICollection/String.o \
	${OBJECTDIR}/ICollection/collections/List.o \
	${OBJECTDIR}/ICollection/collections/ListIterator.o \
	${OBJECTDIR}/ICollection/collections/ListNode.o \
	${OBJECTDIR}/ICollection/collections/OrderedDictionary.o \
	${OBJECTDIR}/ICollection/collections/OrderedDictionaryEntry.o \
	${OBJECTDIR}/ICollection/interfaces/ICollectible.o \
	${OBJECTDIR}/ICollection/interfaces/ICollection.o \
	${OBJECTDIR}/ICollection/interfaces/IDictionary.o \
	${OBJECTDIR}/ICollection/interfaces/IIterator.o \
	${OBJECTDIR}/ICollection/interfaces/IKey.o \
	${OBJECTDIR}/ICollection/interfaces/OrderedKey.o \
	${OBJECTDIR}/InterfazGrafica.o \
	${OBJECTDIR}/Mensaje.o \
	${OBJECTDIR}/Miembro.o \
	${OBJECTDIR}/Miembro_Conversacion.o \
	${OBJECTDIR}/Sistema.o \
	${OBJECTDIR}/Usuario.o \
	${OBJECTDIR}/Video.o \
	${OBJECTDIR}/Visto.o \
	${OBJECTDIR}/factory.o \
	${OBJECTDIR}/generadorId.o \
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
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/pa_obligatorio_5_2.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/pa_obligatorio_5_2.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/pa_obligatorio_5_2 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Contacto.o: Contacto.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Contacto.o Contacto.cpp

${OBJECTDIR}/Conversaciones.o: Conversaciones.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Conversaciones.o Conversaciones.cpp

${OBJECTDIR}/Estado.o: Estado.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Estado.o Estado.cpp

${OBJECTDIR}/Fecha.o: Fecha.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Fecha.o Fecha.cpp

${OBJECTDIR}/Foto.o: Foto.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Foto.o Foto.cpp

${OBJECTDIR}/Grupo.o: Grupo.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Grupo.o Grupo.cpp

${OBJECTDIR}/ICollection/Integer.o: ICollection/Integer.cpp
	${MKDIR} -p ${OBJECTDIR}/ICollection
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ICollection/Integer.o ICollection/Integer.cpp

${OBJECTDIR}/ICollection/String.o: ICollection/String.cpp
	${MKDIR} -p ${OBJECTDIR}/ICollection
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ICollection/String.o ICollection/String.cpp

${OBJECTDIR}/ICollection/collections/List.o: ICollection/collections/List.cpp
	${MKDIR} -p ${OBJECTDIR}/ICollection/collections
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ICollection/collections/List.o ICollection/collections/List.cpp

${OBJECTDIR}/ICollection/collections/ListIterator.o: ICollection/collections/ListIterator.cpp
	${MKDIR} -p ${OBJECTDIR}/ICollection/collections
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ICollection/collections/ListIterator.o ICollection/collections/ListIterator.cpp

${OBJECTDIR}/ICollection/collections/ListNode.o: ICollection/collections/ListNode.cpp
	${MKDIR} -p ${OBJECTDIR}/ICollection/collections
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ICollection/collections/ListNode.o ICollection/collections/ListNode.cpp

${OBJECTDIR}/ICollection/collections/OrderedDictionary.o: ICollection/collections/OrderedDictionary.cpp
	${MKDIR} -p ${OBJECTDIR}/ICollection/collections
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ICollection/collections/OrderedDictionary.o ICollection/collections/OrderedDictionary.cpp

${OBJECTDIR}/ICollection/collections/OrderedDictionaryEntry.o: ICollection/collections/OrderedDictionaryEntry.cpp
	${MKDIR} -p ${OBJECTDIR}/ICollection/collections
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ICollection/collections/OrderedDictionaryEntry.o ICollection/collections/OrderedDictionaryEntry.cpp

${OBJECTDIR}/ICollection/interfaces/ICollectible.o: ICollection/interfaces/ICollectible.cpp
	${MKDIR} -p ${OBJECTDIR}/ICollection/interfaces
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ICollection/interfaces/ICollectible.o ICollection/interfaces/ICollectible.cpp

${OBJECTDIR}/ICollection/interfaces/ICollection.o: ICollection/interfaces/ICollection.cpp
	${MKDIR} -p ${OBJECTDIR}/ICollection/interfaces
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ICollection/interfaces/ICollection.o ICollection/interfaces/ICollection.cpp

${OBJECTDIR}/ICollection/interfaces/IDictionary.o: ICollection/interfaces/IDictionary.cpp
	${MKDIR} -p ${OBJECTDIR}/ICollection/interfaces
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ICollection/interfaces/IDictionary.o ICollection/interfaces/IDictionary.cpp

${OBJECTDIR}/ICollection/interfaces/IIterator.o: ICollection/interfaces/IIterator.cpp
	${MKDIR} -p ${OBJECTDIR}/ICollection/interfaces
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ICollection/interfaces/IIterator.o ICollection/interfaces/IIterator.cpp

${OBJECTDIR}/ICollection/interfaces/IKey.o: ICollection/interfaces/IKey.cpp
	${MKDIR} -p ${OBJECTDIR}/ICollection/interfaces
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ICollection/interfaces/IKey.o ICollection/interfaces/IKey.cpp

${OBJECTDIR}/ICollection/interfaces/OrderedKey.o: ICollection/interfaces/OrderedKey.cpp
	${MKDIR} -p ${OBJECTDIR}/ICollection/interfaces
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ICollection/interfaces/OrderedKey.o ICollection/interfaces/OrderedKey.cpp

${OBJECTDIR}/InterfazGrafica.o: InterfazGrafica.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/InterfazGrafica.o InterfazGrafica.cpp

${OBJECTDIR}/Mensaje.o: Mensaje.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Mensaje.o Mensaje.cpp

${OBJECTDIR}/Miembro.o: Miembro.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Miembro.o Miembro.cpp

${OBJECTDIR}/Miembro_Conversacion.o: Miembro_Conversacion.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Miembro_Conversacion.o Miembro_Conversacion.cpp

${OBJECTDIR}/Sistema.o: Sistema.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sistema.o Sistema.cpp

${OBJECTDIR}/Usuario.o: Usuario.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Usuario.o Usuario.cpp

${OBJECTDIR}/Video.o: Video.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Video.o Video.cpp

${OBJECTDIR}/Visto.o: Visto.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Visto.o Visto.cpp

${OBJECTDIR}/factory.o: factory.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/factory.o factory.cpp

${OBJECTDIR}/generadorId.o: generadorId.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/generadorId.o generadorId.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

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
