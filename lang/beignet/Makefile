# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	beignet
PORTVERSION=	1.0.2
CATEGORIES=	lang
MASTER_SITES=	https://01.org/sites/default/files/
DISTVERSIONSUFFIX=	-source

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	OpenCL library for Intel GPUs

BUILD_DEPENDS=	clang${LLVMVER}:${PORTSDIR}/lang/clang${LLVMVER} \
		opencl>=0:${PORTSDIR}/devel/opencl
LIB_DEPENDS=	libOpenCL.so:${PORTSDIR}/lang/ocl-icd \
		libdrm.so:${PORTSDIR}/graphics/libdrm
RUN_DEPENDS=	opencl>=0:${PORTSDIR}/devel/opencl

WRKSRC=		${WRKDIR}/Beignet-${PORTVERSION}-Source

USES=		cmake gmake pkgconfig shebangfix
USE_XORG=	sm ice x11 xext xfixes
USE_GL=		gl
SHEBANG_FILES=	src/git_sha1.sh backend/kernels/compile.sh
LLVMVER=	35

CMAKE_ARGS+=	-DLLVM_CONFIG_EXECUTABLE=${LOCALBASE}/bin/llvm-config${LLVMVER}

ONLY_FOR_ARCHS=	i386 amd64

post-patch:
	@${REINPLACE_CMD} -e 's|llvm-as|llvm-as${LLVMVER}|g; \
		s|llvm-link|llvm-link${LLVMVER}|g' \
		${WRKSRC}/backend/src/libocl/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|clang |clang${LLVMVER} |g' \
		${WRKSRC}/backend/src/libocl/CMakeLists.txt \
		${WRKSRC}/backend/kernels/compile.sh

post-install:
	@${RM} -rf ${STAGEDIR}${PREFIX}/include/CL

.include <bsd.port.mk>
