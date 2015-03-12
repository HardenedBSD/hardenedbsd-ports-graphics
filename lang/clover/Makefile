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

.include "${.CURDIR}/../../graphics/libGL/bsd.mesalib.mk"

BUILD_WRKSRC=	${WRKSRC}/src/gallium/targets/opencl

.if !defined(WITH_NEW_MESA)
IGNORE=	Mesa OpenCL is only supported with Mesa 10.x
.endif

BUILD_DEPENDS+=	llvm${MESA_LLVM_VER}>=0:${PORTSDIR}/devel/llvm${MESA_LLVM_VER}
RUN_DEPENDS+=	llvm${MESA_LLVM_VER}>=0:${PORTSDIR}/devel/llvm${MESA_LLVM_VER}
CONFIGURE_ENV+=	LLVM_CONFIG=${LOCALBASE}/bin/llvm-config${MESA_LLVM_VER}

# we need the clang port too even if it is not used to compile because
# the clover code needs some of the clang includes to build.
BUILD_DEPENDS+=	clang${MESA_LLVM_VER}>=0:${PORTSDIR}/lang/clang${MESA_LLVM_VER}

CONFIGURE_ARGS+=--enable-gallium-llvm \
		--with-gallium-drivers=r300,r600,radeonsi,svga,swrast \
		--with-dri-drivers=" "

do-build:
	@cd ${WRKSRC}/src/gallium/auxiliary/pipe-loader/ && ${MAKE_CMD} libpipe_loader_client.la
	@cd ${WRKSRC}/src/gallium/state_trackers/clover/ && ${MAKE_CMD} libclover.la
	@cd ${WRKSRC}/src/gallium/auxiliary/ && ${MAKE_CMD} libgallium.la
	@cd ${WRKSRC}/src/util/ && ${MAKE_CMD} libmesautil.la
	@cd ${WRKSRC}/src/gallium/winsys/sw/null/ && ${MAKE_CMD} libws_null.la
	@cd ${WRKSRC}/src/gallium/winsys/sw/wrapper/ && ${MAKE_CMD} libwsw.la
	@cd ${WRKSRC}/src/gallium/winsys/sw/dri/ && ${MAKE_CMD} libswdri.la
	@cd ${WRKSRC}/src/gallium/winsys/sw/xlib/ && ${MAKE_CMD} libws_xlib.la
	@cd ${WRKSRC}/src/gallium/targets/opencl && ${MAKE_CMD} libMesaOpenCL.la

	@cd ${WRKSRC}/src/gallium/winsys/radeon/drm && ${MAKE_CMD} libradeonwinsys.la
	@cd ${WRKSRC}/src/gallium/winsys/svga/drm && ${MAKE_CMD} libsvgadrm.la
	@cd ${WRKSRC}/src/gallium/drivers/rbug && ${MAKE_CMD} librbug.la
	@cd ${WRKSRC}/src/gallium/drivers/trace && ${MAKE_CMD} libtrace.la
	@cd ${WRKSRC}/src/gallium/drivers/galahad && ${MAKE_CMD} libgalahad.la
	@cd ${WRKSRC}/src/gallium/drivers/svga && ${MAKE_CMD} libsvga.la
	@cd ${WRKSRC}/src/gallium/drivers/r300 && ${MAKE_CMD} libr300.la
	@cd ${WRKSRC}/src/gallium/drivers/r600 && ${MAKE_CMD} libr600.la
	@cd ${WRKSRC}/src/gallium/drivers/radeon && ${MAKE_CMD} libradeon.la
	@cd ${WRKSRC}/src/gallium/drivers/radeonsi && ${MAKE_CMD} libradeonsi.la
	@cd ${WRKSRC}/src/gallium/drivers/softpipe && ${MAKE_CMD} libsoftpipe.la
	@cd ${WRKSRC}/src/gallium/drivers/llvmpipe && ${MAKE_CMD} libllvmpipe.la
	@cd ${WRKSRC}/src/gallium/targets/pipe-loader && ${MAKE_CMD} pipe_r300.la pipe_r600.la pipe_radeonsi.la pipe_vmwgfx.la pipe_swrast.la

do-install:
	@cd ${WRKSRC}/src/gallium/targets/opencl && ${MAKE_CMD} DESTDIR=${STAGEDIR}/ install
	@cd ${WRKSRC}/src/gallium/targets/pipe-loader && ${MAKE_CMD} DESTDIR=${STAGEDIR}/ install

post-install:
	cp -Rp ${WRKSRC}/include/CL ${STAGEDIR}${PREFIX}/include/
	@${MV} ${STAGEDIR}/etc/OpenCL ${STAGEDIR}${PREFIX}/etc/

.include <bsd.port.mk>
