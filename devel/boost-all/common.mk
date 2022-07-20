
PORTVERSION=	1.80.0.b1
PORTVERSUFFIX=	${PORTVERSION:C/\.[0-9]+$//}
DISTNAME=	boost_${PORTVERSION:S/./_/g}

DISTINFO_FILE?=	${.CURDIR}/../boost-all/distinfo

CATEGORIES=	devel
MAINTAINER=	office@FreeBSD.org

MASTER_SITES=	https://boostorg.jfrog.io/artifactory/main/release/${PORTVERSION}/source/ \
		https://boostorg.jfrog.io/artifactory/main/beta/${PORTVERSION:S/.b/.beta/g}/source/ \
		SF/boost/boost/${PORTVERSION}

USES+=		tar:bzip2
