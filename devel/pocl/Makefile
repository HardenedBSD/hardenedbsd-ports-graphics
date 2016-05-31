# Created by: Johannes Dieterich <dieterich@ogolem.org>, initial port by O. Hartman <ohartman@zedat.fu-berlin.de>
# $FreeBSD$

PORTNAME=	pocl
PORTVERSION=	0.11
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	graphics@freebsd.org
COMMENT=	Portable computing language

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/llvm36/bin/llvm-config:${PORTSDIR}/devel/llvm36
LIB_DEPENDS=	libOpenCL.so:${PORTSDIR}/devel/opencl \
		libhwloc.so:${PORTSDIR}/devel/hwloc \
		libltdl.so${PORTSDIR}/devel/libltdl

ONLY_FOR_ARCHS=	amd64

USE_GITHUB=	yes
GH_TAGNAME=	ae18e7e

USE_LDCONFIG=	yes
USE_GL=		gl glew
USES=		cmake

CMAKE_ARGS+=	-DWITH_LLVM_CONFIG=${LOCALBASE}/llvm36/bin/llvm-config \
		-DPOCL_INSTALL_ICD_VENDORDIR=${LOCALBASE}/etc/OpenCL/vendors \
		-DOPENCL_LIBRARIES=${LOCALBASE}/lib/libOpenCL.so
#-DDEFAULT_ENABLE_ICD=ON -DDEFAULT_TESTS_USE_ICD=ON -DDEFAULT_DIRECT_LINKAGE=OFF -DOPENCL_LIBRARIES=/usr/loca/lib/libOpenCL.so -DHOST_LD_FLAGS="-L${LOCALBASE}/lib -shared -lm"

PLIST_SUB+=	OSARCH=${OPSYS:tl}${OSREL}

.include <bsd.port.mk>
