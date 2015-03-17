# Created by: kwm@FreeBSD.org
# $FreeBSD$

PORTNAME=	gbm
PORTVERSION=	${MESAVERSION}
PORTREVISION=	${GBM_REVISION}
CATEGORIES=	graphics

COMMENT=	gbm library

LIB_DEPENDS+=	libpthread-stubs.so:${PORTSDIR}/devel/libpthread-stubs \
		libexpat.so:${PORTSDIR}/textproc/expat2 \
		libdrm.so:${PORTSDIR}/graphics/libdrm \
		libglapi.so:${PORTSDIR}/graphics/libglapi

USE_XORG=	x11 xau xcb xdmcp

# stuff not needed by gbm but configure wants it
USE_XORG+=	glproto dri2proto xext xdamage xfixes presentproto \
		xshmfence

.include <bsd.port.options.mk>
.include "${.CURDIR}/../../graphics/libGL/Makefile.common"

.if defined(WITH_NEW_MESA)
MESA_BUILD_WRKSRC=	src/mapi src/gbm
MESA_INSTALL_WRKSRC=	src/gbm
.else
MESA_BUILD_WRKSRC=	src/mapi-shared-glapi src/gbm
MESA_INSTALL_WRKSRC=	src/gbm
.endif

.if defined(WITH_NEW_MESA)
GBM_REVISION=	0
.else
GBM_REVISION=	0
.endif

.include "${.CURDIR}/../../graphics/libGL/Makefile.targets"

.include <bsd.port.mk>
