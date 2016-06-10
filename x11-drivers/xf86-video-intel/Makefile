# Created by: lesi@FreeBSD.org
# $FreeBSD$

PORTNAME=	xf86-video-intel
PORTVERSION=	2.99.917.20160417
PORTREVISION=	1
CATEGORIES=	x11-drivers
MASTER_SITES=	LOCAL/kwm \
		http://rainbow-runner.nl/freebsd/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Driver for Intel integrated graphics chipsets

LIB_DEPENDS=	libxcb-util.so:x11/xcb-util

ONLY_FOR_ARCHS=	amd64 i386
USE_GL=		gl

USE_LDCONFIG=	yes
XORG_CAT=	driver
USE_XORG=	glproto \
		pixman \
		x11 \
		xext \
		xf86driproto \
		xineramaproto \
		xrender \
		presentproto \
		xvmc

USES+=		cpe
CPE_VENDOR=	x

CONFIGURE_ARGS+=	--with-default-accel=sna
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE_amd64=	DRI3
OPTIONS_DEFINE_i386=	DRI3
DRI3_DESC=	Experimental: enable dri3 support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDRI3}
USE_XORG+=	dri3proto
CONFIGURE_ARGS+=	--enable-dri3
.else
CONFIGURE_ARGS+=	--disable-dri3
.endif

.if (${OSVERSION} >= 903000 && ${OSVERSION} < 1000000)
RUN_DEPENDS+=	drm-kmod>=9:x11-drivers/drm-kmod

post-patch:
	@${REINPLACE_CMD} -e 's|"i915kms"|"i915kms_port"|g' \
		${WRKSRC}/src/intel_device.c
.endif

.include <bsd.port.mk>
