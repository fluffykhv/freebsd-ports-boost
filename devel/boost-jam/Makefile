# Created by: Alexander Churanov <churanov.port.maintainer@gmail.com>

PORTNAME=	boost-jam
COMMENT=	Build tool from the boost.org

PLIST_FILES=	bin/bjam

LICENSE=	BSL
LICENSE_FILE=	${WRKDIR}/${DISTNAME}/LICENSE_1_0.txt

EXTRACT_AFTER_ARGS=	${DISTNAME}/${WRKSRC_SUBDIR} ${DISTNAME}/LICENSE_1_0.txt
MAKE_CMD=	./build.sh
ALL_TARGET=	${CHOSEN_COMPILER_TYPE} ${WITH_DEBUG:D--debug}
MAKE_FLAGS=	#
_MAKE_JOBS=	#
MAKEFILE=	#

USES=		compiler:c++11-lang

WRKSRC_SUBDIR=	tools/build/src/engine

.include "${.CURDIR}/../boost-all/common.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bjam ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
