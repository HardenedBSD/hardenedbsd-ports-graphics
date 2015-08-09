# Created by: Johannes Dieterich <dieterich@ogolem.org>
# $FreeBSD$

PORTNAME=	clfft
PORTVERSION=	2.6.1
DISTVERSIONPREFIX=      v
CATEGORIES=	math

MAINTAINER=     dieterich@ogolem.org
COMMENT=        Software library containing FFT functions written in OpenCL 

LICENSE=        APACHE20
LICENSE_FILE=   ${WRKSRC}/LICENSE

LIB_DEPENDS=    libOpenCL.so:${PORTSDIR}/devel/opencl

ONLY_FOR_ARCHS= amd64

USE_GITHUB=	yes
GH_ACCOUNT=	clMathLibraries
GH_PROJECT=	clFFT
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	1ca97a4

USE_LDCONFIG=	yes
USES=	cmake

CMAKE_ARGS+=	-DBUILD_CLIENT=OFF -DBUILD_TEST=OFF -DSUFFIX_LIB=""

CMAKE_SOURCE_PATH=	${WRKSRC}/src

.include <bsd.port.mk>
