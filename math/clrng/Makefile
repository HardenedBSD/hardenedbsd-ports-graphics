# Created by: Johannes Dieterich <dieterich@ogolem.org>
# $FreeBSD$

PORTNAME=	clrng
PORTVERSION=	1.0.0
DISTVERSIONPREFIX=      v
CATEGORIES=	math

MAINTAINER=     dieterich@ogolem.org
COMMENT=        Software library containing BLAS functions written in OpenCL

LICENSE=        BSD
LICENSE_FILE=   ${WRKSRC}/LICENSE

LIB_DEPENDS=    libOpenCL.so:${PORTSDIR}/devel/opencl

ONLY_FOR_ARCHS= amd64

USE_GITHUB=	yes
GH_ACCOUNT=	clMathLibraries
GH_PROJECT=	clRNG
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	1f35bc4

USE_LDCONFIG=	yes
USES=	cmake

CMAKE_ARGS+=	-DBUILD_CLIENT=OFF -DBUILD_TEST=OFF -DSUFFIX_LIB="" -DSUFFIX_BIN=""

CMAKE_SOURCE_PATH=	${WRKSRC}/src

.include <bsd.port.mk>
