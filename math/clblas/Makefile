# Created by: Johannes Dieterich <dieterich@ogolem.org>
# $FreeBSD$

PORTNAME=	clblas
PORTVERSION=	2.6
DISTVERSIONPREFIX=      v
CATEGORIES=	math

MAINTAINER=     dieterich@ogolem.org
COMMENT=        Software library containing BLAS functions written in OpenCL

LICENSE=        APACHE20
LICENSE_FILE=   ${WRKSRC}/LICENSE

LIB_DEPENDS=    libOpenCL.so:${PORTSDIR}/devel/opencl

ONLY_FOR_ARCHS= amd64

USE_GITHUB=	yes
GH_ACCOUNT=	clMathLibraries
GH_PROJECT=	clBLAS
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	9731ea2

USE_LDCONFIG=	yes
USES=	cmake

CMAKE_ARGS+=	-DBUILD_TEST=OFF -DBUILD_KTEST=OFF -DSUFFIX_LIB=""

CMAKE_SOURCE_PATH=	${WRKSRC}/src

post-install:
	@${RM} -r ${STAGEDIR}/usr/local/share/clBLAS

.include <bsd.port.mk>
