# $FreeBSD$

PORTNAME=	clover
PORTVERSION=	${MESAVERSION}
PORTREVISION=	${DRIREVISION}
CATEGORIES=	lang

COMMENT=	Mesa "Clover" OpenCL library

BUILD_DEPENDS=	libclc>=0.0.r222830:${PORTSDIR}/devel/libclc
LIB_DEPENDS=	libdrm.so:${PORTSDIR}/graphics/libdrm \
		libOpenCL.so:${PORTSDIR}/lang/ocl-icd \
		libexpat.so:${PORTSDIR}/textproc/expat2

USE_XORG=	glproto x11 xext xxf86vm xdamage xfixes dri2proto \
		presentproto xvmc xshmfence
USES+=		compiler:c++11-lang

.include <bsd.port.options.mk>

.include "${.CURDIR}/../../graphics/libGL/Makefile.common"

#MESA_BUILD_WRKSRC=	src/util src/glsl src/mesa src/gallium
MESA_INSTALL_WRKSRC=	src/gallium/targets/opencl src/gallium/targets/pipe-loader

.if !defined(WITH_NEW_MESA)
IGNORE=	Mesa OpenCL is only supported with Mesa 10.x
.endif

# we need the clang port too even if it is not used to compile because
# the clover code needs some of the clang includes to build.
BUILD_DEPENDS+=	clang${MESA_LLVM_VER}>=0:${PORTSDIR}/lang/clang${MESA_LLVM_VER}

.include "${.CURDIR}/../../graphics/libGL/Makefile.targets"

post-install:
	cp -Rp ${WRKSRC}/include/CL ${STAGEDIR}${PREFIX}/include/
	@${MV} ${STAGEDIR}/etc/OpenCL ${STAGEDIR}${PREFIX}/etc/

.include <bsd.port.mk>
