# $FreeBSD$

# this port is for future amdgpu kernel support testing.

PORTNAME=	xf86-video-amdgpu
PORTVERSION=	1.1.2
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org amdgpu display driver

LIB_DEPENDS=	libdrm_amdgpu.so:graphics/libdrm

USE_GL=		gbm
XORG_CAT=	driver
INSTALL_TARGET=	install-strip
# No amdgpu kernel driver on non-x86 and PC98.
ONLY_FOR_ARCHS=	i386 amd64

CONFIGURE_ARGS+=--disable-udev
CONFIGURE_ARGS+=--disable-glamor

.include <bsd.port.options.mk>

.if (${OSVERSION} < 1100000)
# this probably should be 11.x too.
IGNORE=		Not support on 11.x or older, no kernel support
.endif

.include <bsd.port.mk>
