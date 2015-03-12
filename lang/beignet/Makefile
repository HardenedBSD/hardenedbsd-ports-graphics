# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	beignet
PORTVERSION=	1.0.1
CATEGORIES=	lang
MASTER_SITES=	https://01.org/sites/default/files/
DISTVERSIONSUFFIX=	-src

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Required library functions for OpenCL C programming language

BUILD_DEPENDS=	clang${LLVMVER}:${PORTSDIR}/lang/clang${LLVMVER}
LIB_DEPENDS=	libOpenCL.so:${PORTSDIR}/lang/ocl-icd \
		libdrm.so:${PORTSDIR}/graphics/libdrm

WRKSRC=		${WRKDIR}/Beignet-${PORTVERSION}-Source

USES=		cmake gmake pkgconfig shebangfix
#tar:xz
USE_XORG=	ice x11 xext xfixes
USE_GL=		gl
SHEBANG_FILES=	src/git_sha1.sh backend/kernels/compile.sh
LLVMVER=	35

CMAKE_ARGS+=	-DLLVM_CONFIG_EXECUTABLE=${LOCALBASE}/bin/llvm-config${LLVMVER}

#CC=clang35
#CXX=clang++35
#CPP=clang-cpp35

post-patch:
	@${REINPLACE_CMD} -e 's|llvm-as|llvm-as${LLVMVER}|g; \
		s|llvm-link|llvm-link${LLVMVER}|g' \
		${WRKSRC}/backend/src/libocl/CMakeLists.txt

post-install:
	@${MV} ${STAGEDIR}/etc/OpenCL ${STAGEDIR}${PREFIX}/etc/

.include <bsd.port.mk>
