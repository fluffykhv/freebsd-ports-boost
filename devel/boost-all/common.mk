
PORTVERSION=	1.77.0
PORTVERSUFFIX=	${PORTVERSION:C/\.[0-9]+$//}
DISTNAME=	boost_${PORTVERSION:S/./_/g}

CATEGORIES=	devel
MAINTAINER=	office@FreeBSD.org

MASTER_SITES=	https://dl.bintray.com/boostorg/release/${PORTVERSION}/source/ \
		SF/boost/boost/${PORTVERSION}

LICENSE=	BSL
LICENSE_FILE=	${WRKDIR}/${DISTNAME}/LICENSE_1_0.txt

USES+=		tar:bzip2
