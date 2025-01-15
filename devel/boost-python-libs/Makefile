PORTNAME=	boost-libs
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

COMMENT=	Framework for interfacing Python and C++
WWW=		https://www.boost.org/

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE_1_0.txt

PATCHDIR=	${.CURDIR}/../boost-libs/files

BUILD_DEPENDS=	bjam:devel/boost-jam \
		${PYNUMPY}
LIB_DEPENDS=	libboost_thread.so:devel/boost-libs

USES=		python:3.9-3.11  # upper bound inherited from math/py-numpy
USE_PYTHON=	flavors

#LDFLAGS+=	-Wl,--as-needed

OPTIONS_DEFINE=	DEBUG OPTIMIZED_CFLAGS

OPTIONS_RADIO=	MPI
OPTIONS_RADIO_MPI=	OPENMPI MPICH
OPTIONS_DEFAULT=	OPENMPI
# Use Use MPICH option for 32-bit architecture.
# See https://github.com/open-mpi/ompi/issues/3195 for details.
OPTIONS_DEFAULT_armv6=	MPICH
OPTIONS_DEFAULT_armv7=	MPICH
OPTIONS_DEFAULT_i386=	MPICH
OPTIONS_DEFAULT_powerpc=MPICH
OPTIONS_EXCLUDE_armv6=	OPENMPI
OPTIONS_EXCLUDE_armv7=	OPENMPI
OPTIONS_EXCLUDE_i386=	OPENMPI
OPTIONS_EXCLUDE_powerpc=OPENMPI

MPICH_USES=	mpi:mpich
OPENMPI_USES=	mpi:openmpi
MPICH_MAKE_ARGS+=	--with-mpi
OPENMPI_MAKE_ARGS+=	--with-mpi

.include "${.CURDIR}/../boost-all/common.mk"

.include "${.CURDIR}/../boost-all/compiled.mk"

MAKE_ENV+=	PYTHON_ROOT="${LOCALBASE}"\
		PYTHON_VERSION="${PYTHON_VERSION}"\
		PYTHON_INCLUDES="${PYTHON_INCLUDEDIR}"\
		PYTHON_LIB_PATH="${PYTHON_LIBDIR}"

MAKE_ARGS+=	--with-python
#MAKE_ARGS+=	--without-container
#MAKE_ARGS+=	--without-graph
ALL_TARGET=	stage

.include <bsd.port.pre.mk>

.if ${PYTHON_VER} == ${PYTHON_DEFAULT}
PLIST_SUB+=	PY_DEFAULT_ONLY=""
.else
PLIST_SUB+=	PY_DEFAULT_ONLY="@comment "
.endif

.if ${PORT_OPTIONS:MMPICH} || ${PORT_OPTIONS:MOPENMPI}
PLIST_SUB+=	MPI=""
.else
PLIST_SUB+=	MPI="@comment "
.endif

pre-build:
	@${ECHO_CMD} "using python : " ${PYTHON_VER} " : " ${PYTHON_CMD} " : " ${PYTHON_INCLUDEDIR} ";" >> ${WRKSRC}/tools/build/src/site-config.jam
.if ${PORT_OPTIONS:MMPICH} || ${PORT_OPTIONS:MOPENMPI}
	@${ECHO_CMD} "using mpi : " ${MPICXX} ";" >> ${WRKSRC}/tools/build/src/site-config.jam
.endif

do-install:
.if ${PORT_OPTIONS:MMPICH} || ${PORT_OPTIONS:MOPENMPI}
	@cd ${WRKSRC}/stage/lib && ${PAX} -rw -p p libboost_mpi* ${STAGEDIR}${PREFIX}/lib
.endif
	@cd ${WRKSRC}/stage/lib && ${PAX} -rw -p p libboost_numpy* ${STAGEDIR}${PREFIX}/lib
	@cd ${WRKSRC}/stage/lib && ${PAX} -rw -p p libboost_python* ${STAGEDIR}${PREFIX}/lib

# CMake part
.if ${PORT_OPTIONS:MMPICH} || ${PORT_OPTIONS:MOPENMPI}
	@cd ${WRKSRC}/stage/lib && ${PAX} -rw -p p cmake/boost_mpi*/*-py${PYTHON_VER}.cmake ${STAGEDIR}${PREFIX}/lib
.endif
	@cd ${WRKSRC}/stage/lib && ${PAX} -rw -p p cmake/boost_numpy*/*-py${PYTHON_VER}.cmake ${STAGEDIR}${PREFIX}/lib
	@cd ${WRKSRC}/stage/lib && ${PAX} -rw -p p cmake/boost_python*/*-py${PYTHON_VER}.cmake ${STAGEDIR}${PREFIX}/lib
.if ${PYTHON_VER} == ${PYTHON_DEFAULT}
.	if ${PORT_OPTIONS:MMPICH} || ${PORT_OPTIONS:MOPENMPI}
		@cd ${WRKSRC}/stage/lib && ${PAX} -rw -p p cmake/boost_mpi*/*-config*.cmake ${STAGEDIR}${PREFIX}/lib
.	endif
	@cd ${WRKSRC}/stage/lib && ${PAX} -rw -p p cmake/boost_numpy*/*-config*.cmake ${STAGEDIR}${PREFIX}/lib
	@cd ${WRKSRC}/stage/lib && ${PAX} -rw -p p cmake/boost_python*/*-config*.cmake ${STAGEDIR}${PREFIX}/lib
.endif
	@${FIND} ${STAGEDIR}${PREFIX}/lib/cmake -type f -exec \
		${REINPLACE_CMD} -i '' -e 's,${STAGEDIR},,' {} +

post-install:
# display pkg-message
	@${TOUCH} ${PKGMESSAGE}
	@${CAT} ${PKG_MESSAGE_FILE_THREADS} >> ${PKGMESSAGE}
	@${ECHO_CMD} >> ${PKGMESSAGE}
	@${CAT} ${PKG_MESSAGE_FILE_PYTHON} >> ${PKGMESSAGE}
	@${ECHO_CMD} >> ${PKGMESSAGE}
	@${REINPLACE_CMD} \
		-e "s|%%LOCALBASE%%|${LOCALBASE}|g" \
		-e "s|%%PYTHON_INCLUDEDIR%%|${PYTHON_INCLUDEDIR}|g" \
		-e "s|%%PYTHON_LIBDIR%%|${PYTHON_LIBDIR}|g" \
		-e "s|%%PYTHON_VERSION%%|${PYTHON_VERSION}|g" ${PKGMESSAGE}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libboost_*.so.${BOOST_SHARED_LIB_VER}

.include <bsd.port.post.mk>
