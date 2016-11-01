# Created by: Johannes Dieterich <dieterich@ogolem.org>
# $FreeBSD$

PORTNAME=	roc
PORTVERSION=	2.0
CATEGORIES=	devel

MAINTAINER=	dieterich@ogolem.org
COMMENT=	Boltzmann thunk library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	opencl>=0:devel/opencl
LIB_DEPENDS=	libOpenCL.so:devel/ocl-icd
RUN_DEPENDS=	opencl>=0:devel/opencl

BROKEN_FreeBSD_9=	roc is only supported on FreeBSD 10.1 and newer
ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON_amd64=	only builds and is supported on amd64

USE_GITHUB=	yes
GH_ACCOUNT=	RadeonOpenCompute
GH_PROJECT=	ROCT-Thunk-Interface
GH_TAGNAME=	71b9ff5

USE_LDCONFIG=	yes
USES=		cmake

CMAKE_ARGS+=	

#CMAKE_SOURCE_PATH=	${WRKSRC}/src

.include <bsd.port.mk>
