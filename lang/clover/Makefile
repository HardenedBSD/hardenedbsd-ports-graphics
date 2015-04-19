# $FreeBSD$

PORTNAME=	clover
PORTVERSION=	${MESAVERSION}
PORTREVISION=	0
CATEGORIES=	lang

COMMENT=	Mesa "Clover" OpenCL library

LIB_DEPENDS=	libdrm.so:${PORTSDIR}/graphics/libdrm \
		libOpenCL.so:${PORTSDIR}/lang/ocl-icd \
		libexpat.so:${PORTSDIR}/textproc/expat2

USE_XORG=	glproto x11 xext xxf86vm xdamage xfixes dri2proto \
		presentproto xvmc xshmfence

.include <bsd.port.options.mk>

# temp until all mesa ports can use llvm34+ (needs 8.4 EOL)
MESA_LLVM_VER=35

.include "${.CURDIR}/../../graphics/libGL/Makefile.common"

#MESA_BUILD_WRKSRC=	src/util src/glsl src/mesa src/gallium
MESA_INSTALL_WRKSRC=	src/gallium/targets/opencl src/gallium/targets/pipe-loader

.include "${.CURDIR}/../../graphics/libGL/Makefile.targets"

post-install:
	cp -Rp ${WRKSRC}/include/CL ${STAGEDIR}${PREFIX}/include/
	@${MV} ${STAGEDIR}/etc/OpenCL ${STAGEDIR}${PREFIX}/etc/

.include <bsd.port.mk>
