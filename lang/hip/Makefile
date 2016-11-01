# Created by: Johannes Dieterich <dieterich@ogolem.org>
# $FreeBSD$

PORTNAME=	hip
PORTVERSION=	2.0
CATEGORIES=	lang

MAINTAINER=	dieterich@ogolem.org
COMMENT=	HIP allows developers to convert CUDA code to portable C++

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	opencl>=0:devel/opencl
LIB_DEPENDS=	libOpenCL.so:devel/ocl-icd
RUN_DEPENDS=	opencl>=0:devel/opencl

BROKEN_FreeBSD_9=	hip is only supported on FreeBSD 10.1 and newer
ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON_amd64=	only builds and is supported on amd64

USE_GITHUB=	yes
GH_ACCOUNT=	RadeonOpenCompute
GH_PROJECT=	HIP
GH_TAGNAME=	85de2a0

USE_LDCONFIG=	yes
USES=		cmake

CMAKE_ARGS+=	

.include <bsd.port.mk>
