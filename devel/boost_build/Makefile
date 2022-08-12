PORTNAME=	boost_build
DISTVERSION=	4.9.2
CATEGORIES=	devel

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	Extensible cross-platform build tool suite

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${LOCALBASE}/bin/bjam:devel/boost-jam

USES=		compiler:c++11-lang python:test shebangfix tar:bzip2

USE_GITHUB=	yes
GH_ACCOUNT=	boostorg
GH_PROJECT=	build
GH_TAGNAME=	405d34a

CONFLICTS_INSTALL=	b2

SHEBANG_GLOB=	*.py

SUB_FILES=	pkg-message

do-build:
	@cd ${WRKSRC} && CXXFLAGS="${CXXFLAGS}" CXX="${CXX}" ./bootstrap.sh

do-install:
	cd ${WRKSRC} && ./b2 toolset=${CHOSEN_COMPILER_TYPE} install --prefix=${STAGEDIR}${PREFIX}

do-test: # test target fails: https://github.com/boostorg/build/issues/698
	cd ${WRKSRC} && ./b2 toolset=${CHOSEN_COMPILER_TYPE} test --prefix=${STAGEDIR}${PREFIX}

.include <bsd.port.mk>
