# $FreeBSD$

PORTNAME=	wlc
PORTVERSION=0.0.5
CATEGORIES=	wayland

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Wayland compositor library

USE_GITHUB=	yes
GH_ACCOUNT=	cloudef
GH_TAGNAME=	fa780ce

GH_TUPLE=	cloudef:chck:3f27d2a:chck

USES=		cmake pkgconfig
USE_XORG=	x11 xcb xcursor
USE_GL=		egl gbm glesv2

LIB_DEPENDS= \
		libxkbcommon.so:${PORTSDIR}/x11/libxkbcommon		\
		libxcb-ewmh.so:${PORTSDIR}/wayland/libinput			\
		libX11.so:${PORTSDIR}/x11/libX11					\
		libxcb.so:${PORTSDIR}/x11/libxcb					\
		libpixman-1.so:${PORTSDIR}/x11/pixman				\
		libcairo.so:${PORTSDIR}/graphics/cairo				\
		libwayland-server.so:${PORTSDIR}/wayland/wayland	\
		libwayland-client.so:${PORTSDIR}/wayland/wayland	\
		libwayland-cursor.so:${PORTSDIR}/wayland/wayland	\
		libdrm.so:${PORTSDIR}/graphics/libdrm				\
		libudev.so:${PORTSDIR}/wayland/libudev-devd			\
		libinput.so:${PORTSDIR}/wayland/libinput

BUILD_DEPENDS+=	${NONEXISTENT}:${PORTSDIR}/wayland/wayland-protocols
BUILD_DEPENDS+=	wayland-scanner:${PORTSDIR}/wayland/wayland

RUN_DEPENDS=	${LOCALBASE}/lib/libglapi.so.0:${PORTSDIR}/graphics/libglapi

CPPFLAGS+=	-I${LOCALBASE}/include

post-extract:
	@${RM} -r ${WRKSRC}/lib/chck
	@${LN} -s ${WRKSRC_chck} ${WRKSRC}/lib/chck

.include <bsd.port.mk>
