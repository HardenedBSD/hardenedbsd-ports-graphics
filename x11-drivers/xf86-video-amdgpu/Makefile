# $FreeBSD$

# this port is for future amdgpu kernel support testing.

PORTNAME=	xf86-video-amdgpu
PORTVERSION=	1.1.0
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org amdgpu display driver

#USE_GL=		gl
XORG_CAT=	driver
#USE_XORG=	xf86driproto \
#		xineramaproto \
#		xf86miscproto \
#		glproto \
#		presentproto
INSTALL_TARGET=	install-strip
# No Radeon kernel driver on non-x86 and PC98.
ONLY_FOR_ARCHS=	i386 amd64

CONFIGURE_ARGS+=--disable-udev
CONFIGURE_ARGS+=--disable-glamor

.include <bsd.port.options.mk>

.if (${OSVERSION} >= 903000 && ${OSVERSION} < 1000000)
# this probably should be 10.x too.
IGNORE=		Not support on 9.x, no kernel support
.endif

.include <bsd.port.mk>
